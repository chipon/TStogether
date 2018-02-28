#include "database.h"
#include <QDebug>
#include <QMap>
#include <QDate>
#include <utils.h>
#include <QList>

Database::Database()
{

}

bool Database::login(int user, int number, QString pwd)
{
    QSqlQuery query;
    QString q1 = "select * from Teacher where tno=? and tpwd=?";
    QString q2 = "select * from Student where sno=? and spwd=?";
    if(user){
        query.prepare(q1);
        query.addBindValue(number);
        query.addBindValue(pwd);
        if(!query.exec()){
            qDebug()<<query.lastError();
            return false;
        }else{
            return query.next();
        }
    }else{
        query.prepare(q2);
        query.addBindValue(number);
        query.addBindValue(pwd);
        if(!query.exec()){
            qDebug()<<query.lastError();
            return false;
        }else{
            return query.next();
        }
    }
}

QStringList Database::get_all_dept_major()
{
    //
    QString dname;
    QSqlQuery query;
    QStringList list;
    query.prepare("select dname from Dept");
    if(!query.exec()){
        qDebug()<<query.lastError();
        return list;
    }
    while (query.next()) {
      dname= query.value(0).toString();
      list.append(dname);
    }
    return list;
}

QStringList Database::get_major_by_dname(QString dname)
{
    QString mname;
    QSqlQuery query;
    QStringList list;
    query.prepare("select mname from Major,Dept where Major.mdept=Dept.deptno and Dept.dname=?");
    query.addBindValue(dname);
    if(!query.exec()){
        qDebug()<<query.lastError();
        return list;
    }
    while (query.next()) {
      mname= query.value(0).toString();
      list.append(dname);
    }
    return list;
}

Student Database::get_student_by_sno(int sno)
{
    Student stu;
    stu.sno=0;
    QSqlQuery query;
    query.prepare("select sno,snickname,spwd,sname,sgrade,dname,mname,ssignature"
                  " from Student,Dept,Major where sno=? and sdept=deptno and smajor=majorno");
    query.addBindValue(sno);
    if(!query.exec()){
        qDebug()<<query.lastError();
        return stu;
    }
    if(query.next()){
        stu.sno=query.value(0).toInt();
        stu.snickname=query.value(1).toString();
        stu.spwd=query.value(2).toString();
        stu.sname=query.value(3).toString();
        stu.sgrade=query.value(4).toInt();
        stu.sdept=query.value(5).toString();
        stu.smajor=query.value(6).toString();
        stu.ssignature=query.value(7).toString();
    }
    return stu;
}

Teacher Database::get_teacher_by_tno(int tno)
{
    Teacher t;
    t.tno=0;
    QSqlQuery query;
    query.prepare("select tno,tpwd,tname,dname,temail from Teacher,Dept where tno=? and Teacher.tdept=Dept.deptno");
    query.addBindValue(tno);
    if(!query.exec()){
        qDebug()<<query.lastError();
        return t;
    }
    if(query.next()){
        t.tno=query.value(0).toInt();
        t.tpwd=query.value(1).toString();
        t.tname=query.value(2).toString();
        t.tdept=query.value(3).toString();
        t.temail=query.value(4).toString();
    }
    return t;
}

bool Database::update_student_info(QString name, QString pwd, QString sig, int sno)
{
    QSqlQuery query;
    query.prepare("update Student set snickname=?,spwd=?,ssignature=? where sno=?");
    query.addBindValue(name);
    query.addBindValue(pwd);
    query.addBindValue(sig);
    query.addBindValue(sno);
    if(!query.exec()){
        qDebug()<<query.lastError();
        return false;
    }
    return true;
}

bool Database::update_teacher_info(QString pwd, QString email, int tno)
{
    QSqlQuery query;
    query.prepare("update Teacher set tpwd=?,temail=? where tno=?");
    query.addBindValue(pwd);
    query.addBindValue(email);
    query.addBindValue(tno);
    if(!query.exec()){
        qDebug()<<query.lastError();
        return false;
    }
    return true;
}

QList<Dept> Database::get_dept_info()
{
    int dno;
    Dept dept;
    QString dname,mname;
    QSqlQuery query;
    QList<Dept> list;
    query.prepare("select * from Dept");
    if(!query.exec()){
        qDebug()<<query.lastError();
        return list;
    }
    while (query.next()) {
        dno= query.value(0).toInt();
        dname= query.value(1).toString();
        dept.dname=dname;
        dept.majors.clear();

        QSqlQuery innerquery;
        innerquery.prepare("select mname from Major where mdept=?");
        innerquery.addBindValue(dno);
        if(!innerquery.exec()){
            qDebug()<<innerquery.lastError();
            return list;
        }
        while (innerquery.next()) {
          mname= innerquery.value(0).toString();
          dept.majors.append(mname);
        }

        list.append(dept);
    }
    return list;
}

QString Database::find_teacher_by_tno(int tno)
{
    QSqlQuery query;
    query.prepare("select tname from Teacher where tno=?");
    query.addBindValue(tno);
    if(!query.exec()){
        qDebug()<<query.lastError();
        return "";
    }
    if (query.next())
        return query.value(0).toString();
    return "";
}

int Database::create_course(Course c)
{
    QSqlQuery query;
    int cdept=Database::dname_to_deptno(c.cdept);
    if(!cdept){
        return 0;
    }
    int cmajor=Database::mname_to_majorno(c.cmajor);
    if(!cmajor){
        return 0;
    }

    query.prepare("select cno from Course where cname=? and cdept=? and cmajor=?");
    query.addBindValue(c.cname);
    query.addBindValue(cdept);
    query.addBindValue(cmajor);
    if(!query.exec()){
        qDebug()<<query.lastError();
        return 0;
    }
    if(query.next())
        return 0;

    query.prepare("insert into Course(cname,cintro,cdept,cmajor,ctime) values(?,?,?,?,DATE('now'))");
    query.addBindValue(c.cname);
    query.addBindValue(c.cintro);
    query.addBindValue(cdept);
    query.addBindValue(cmajor);
    if(!query.exec()){
        qDebug()<<query.lastError();
        return 0;
    }

    query.prepare("select cno from Course where cname=? and cdept=? and cmajor=?");
    query.addBindValue(c.cname);
    query.addBindValue(cdept);
    query.addBindValue(cmajor);
    if(!query.exec()){
        qDebug()<<query.lastError();
        return 0;
    }
    if(!query.next()){
        return 0;
    }

    int cno=query.value(0).toInt();
    foreach (int tno, c.tnolist) {
        query.prepare("insert into StartCourse values(?,?)");
        query.addBindValue(tno);
        query.addBindValue(cno);
        if(!query.exec()){
            qDebug()<<query.lastError();
            return 0;
        }
    }

    return cno;
}

QList<QString> Database::get_teacher_course(int tno)
{
    QList<QString> list;
    QSqlQuery query;
    query.prepare("select cno,cname from StartCourse,Course where teacher=? and course=cno");
    query.addBindValue(tno);
    if(!query.exec()){
        qDebug()<<query.lastError();
        return list;
    }
    int cno;
    QString cname;
    while (query.next()){
        cno=query.value(0).toInt();
        cname=query.value(1).toString();
        list.append(QString::number(cno)+" "+cname);
    }
    return list;
}

Course Database::get_course_info_by_cno(int cno)
{
    Course c;
    c.cno=0;
    QSqlQuery query;
    query.prepare("select cno,cname,cintro,cnotice,dname,mname from Course,Dept,Major where cno=? and cdept=deptno and cmajor=majorno");
    query.addBindValue(cno);
    if(!query.exec()){
        qDebug()<<query.lastError();
        return c;
    }
    if(!query.next()) return c;
    c.cno=query.value(0).toInt();
    c.cname=query.value(1).toString();
    c.cintro=query.value(2).toString();
    c.cnotice=query.value(3).toString();
    c.cdept=query.value(4).toString();
    c.cmajor=query.value(5).toString();
    if(!Database::get_course_teacher_info(c)){
        c.cno=0;
        qDebug()<<query.lastError();
        return c;
    }
    return c;
}

int Database::get_deptno_by_sno(int sno)
{
    QSqlQuery query;
    query.prepare("select sdept from Student where sno=?");
    query.addBindValue(sno);
    if(!query.exec()){
        qDebug()<<query.lastError();
        return 0;
    }
    if (query.next())
        return query.value(0).toInt();
    return 0;
}

int Database::get_majorno_by_sno(int sno)
{
    QSqlQuery query;
    query.prepare("select smajor from Student where sno=?");
    query.addBindValue(sno);
    if(!query.exec()){
        qDebug()<<query.lastError();
        return 0;
    }
    if (query.next())
        return query.value(0).toInt();
    return 0;
}

QList<Course> Database::search_course(QString search, int sno)
{
    QList<Course> list;
    int deptno=Database::get_deptno_by_sno(sno);
    if(!deptno) return list;
    int majorno=Database::get_majorno_by_sno(sno);
    if(!majorno) return list;

    QSqlQuery query;
    query.prepare("select cno,cname,ctime from Course");
    if(!query.exec()){
        qDebug()<<query.lastError();
        return list;
    }
    QString cno,cname;
    while(query.next()){
        cno=QString::number(query.value(0).toInt());
        cname=query.value(1).toString();
        if(cno.indexOf(search)!=-1 || cname.indexOf(search)!=-1){
            Course c;
            c.cno=cno.toInt();
            c.cname=cname;
            c.ctime=query.value(2).toDate().toString();
            Database::get_course_teacher_info(c);
            list.append(c);
        }
    }
    return list;
}

bool Database::get_course_teacher_info(Course &c)
{
    QSqlQuery query;
    query.prepare("select teacher,tname from StartCourse,Teacher where course=? and teacher=tno");
    query.addBindValue(c.cno);
    if(!query.exec()){
        qDebug()<<query.lastError();
        return false;
    }
    int tno;
    QString tname;
    while (query.next()){
        tno=query.value(0).toInt();
        tname=query.value(1).toString();
        c.tnolist.append(tno);
        c.tnamelist.append(tname);
    }
    return true;
}

bool Database::add_course_by_cno(int sno, int cno)
{
    QSqlQuery query;
    query.prepare("insert into JoinCourse values(?,?)");
    query.addBindValue(sno);
    query.addBindValue(cno);
    if(!query.exec()){
        qDebug()<<query.lastError();
        return false;
    }
    return true;
}

QList<QString> Database::get_student_course(int sno)
{
    QList<QString> list;
    QSqlQuery query;
    query.prepare("select cno,cname from JoinCourse,Course where student=? and course=cno");
    query.addBindValue(sno);
    if(!query.exec()){
        qDebug()<<query.lastError();
        return list;
    }
    int cno;
    QString cname;
    while (query.next()){
        cno=query.value(0).toInt();
        cname=query.value(1).toString();
        list.append(QString::number(cno)+" "+cname);
    }
    return list;
}

QString Database::add_message(bool user,int number, int cno, QString msg)
{
    QString name;
    QSqlQuery query;
    query.prepare("insert into Message(musertype,muserno,mcontent,mcourse,mtime) values(?,?,?,?,DATETIME('now','localtime'))");
    query.addBindValue(user);
    query.addBindValue(number);
    query.addBindValue(msg);
    query.addBindValue(cno);
    if(!query.exec()){
        qDebug()<<query.lastError();
        return name;
    }
    //get name
    return Database::get_message_username(user,number);
}

bool Database::student_join_course(int sno, int cno)
{
    QSqlQuery query;
    query.prepare("select * from JoinCourse where student=? and course=?");
    query.addBindValue(sno);
    query.addBindValue(cno);
    if(!query.exec()){
        qDebug()<<query.lastError();
        return false;
    }
    return query.next();
}

bool Database::teacher_start_course(int tno, int cno)
{
    QSqlQuery query;
    query.prepare("select * from StartCourse where teacher=? and course=?");
    query.addBindValue(tno);
    query.addBindValue(cno);
    if(!query.exec()){
        qDebug()<<query.lastError();
        return false;
    }
    return query.next();
}

QList<Message> Database::get_recent_message(int cno)
{
    QSqlQuery query;
    QList<Message> list;
    query.prepare("select * from Message where mcourse=?");
    query.addBindValue(cno);
    if(!query.exec()){
        qDebug()<<query.lastError();
        return list;
    }
    bool user;
    int number,count=0;
    Message c;
    QString name;
    while(query.next()){
        if(count>=MAX_MSG_COUNT) break;
        user=query.value(1).toBool();
        number=query.value(2).toInt();
        name=Database::get_message_username(user,number);
        if(!name.length()) break;
        c.name=name;
        c.time=query.value(3).toString();
        c.msg=query.value(4).toString();
        list.append(c);
        count++;
    }
    return list;
}

QString Database::get_message_username(bool user, int number)
{
    QString name;
    QSqlQuery query;
    if(user){
        query.prepare("select tname from Teacher where tno=?");
        query.addBindValue(number);
        if(!query.exec()){
            qDebug()<<query.lastError();
        }else if(query.next()){
            name=query.value(0).toString();
        }
    }else{
        query.prepare("select snickname,sname from Student where sno=?");
        query.addBindValue(number);
        if(!query.exec()){
            qDebug()<<query.lastError();
        }else if(query.next()){
            name=query.value(0).toString();
            if(!name.length()) name=query.value(1).toString();
        }
    }
    return name;
}

int Database::add_courseware(int cno, QString path)
{
//    QString path;
//    query.prepare("select cpath from Course where cno=?");
//    query.prepare(cno);
//    if(!query.exec()){
//        qDebug()<<query.lastError();
//        return false;
//    }
//    if(!query.next()) return false;
//    path=query.value(0).toString();
    QSqlQuery query;
    QString	filename=path.right(path.size()-path.lastIndexOf('/')-1);
    query.prepare("insert into Courseware(course,cwname,cwpath,cwtime) values(?,?,?,DATETIME('now','localtime'))");
    query.addBindValue(cno);
    query.addBindValue(filename);
    query.addBindValue(path);
    if(!query.exec()){
        qDebug()<<query.lastError();
        return 0;
    }

    query.prepare("select cwno from Courseware where course=? and cwname=?");
    query.addBindValue(cno);
    query.addBindValue(filename);
    if(!query.exec()){
        qDebug()<<query.lastError();
        return 0;
    }
    if(!query.next()) return 0;
    return query.value(0).toInt();
}

QString Database::get_courseware_path(int fno)
{
    QString path;
    QSqlQuery query;
    query.prepare("select cwpath from Courseware where cwno=?");
    query.addBindValue(fno);
    if(!query.exec()){
        qDebug()<<query.lastError();
        return path;
    }
    if(!query.next()) return path;
    return query.value(0).toString();
}

QList<Courseware> Database::get_courseware_info_by_cno(int cno)
{
    QSqlQuery query;
    Courseware cw;
    QList<Courseware> list;
    query.prepare("select cwno,cwname from Courseware where course=?");
    query.addBindValue(cno);
    if(!query.exec()){
        qDebug()<<query.lastError();
        return list;
    }
    while(query.next()){
        cw.cwno=query.value(0).toInt();
        cw.cwname=query.value(1).toString();
        list.append(cw);
    }
    return list;
}

int Database::dname_to_deptno(QString dname)
{
    QSqlQuery query;
    query.prepare("select deptno from Dept where dname=?");
    query.addBindValue(dname);
    if(!query.exec()){
        qDebug()<<query.lastError();
        return 0;
    }
    if (query.next())
        return query.value(0).toInt();
    return 0;
}

int Database::mname_to_majorno(QString mname)
{
    QSqlQuery query;
    query.prepare("select majorno from Major where mname=?");
    query.addBindValue(mname);
    if(!query.exec()){
        qDebug()<<query.lastError();
        return 0;
    }
    if (query.next())
        return query.value(0).toInt();
    return 0;
}

