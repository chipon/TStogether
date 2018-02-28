#include "admin.h"
#include "ui_admin.h"
#include <QDebug>
#include <QInputDialog>
#include <QMessageBox>
#include <QDate>
#include <QThread>
#include <utils.h>
#include <QSqlError>
#include <database.h>
#include <QStringList>
#include <QTcpSocket>

Admin::Admin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
    this->setWindowTitle("信息管理");

    QString dno,dname,mname;
    QStringList list;
    query.prepare("select dname from Dept");
    if(!query.exec()){
        qDebug()<<query.lastError();
        return;
    }
    while (query.next()) {
      dname= query.value(0).toString();
      list.append(dname);
    }
    ui->depts->addItems(list);
    ui->teacher_depts_combo->addItems(list);
    ui->teacher_tdept_combo->addItems(list);
    ui->student_depts_show_combo->addItems(list);
    ui->student_sdept_show_combo->addItems(list);

    //show tip for major
    ui->majors->addItem("请先选择院系以查看或修改专业");
    currentDeptNo=-1;
    //fetch teacher info
    update_teacher_list();

    //fetch major info
    list.clear();
    dno=Database::dname_to_deptno(ui->student_depts_show_combo->currentText());
    query.prepare("select mname from Major where mdept=?");
    query.addBindValue(dno);
    if(!query.exec()){
        qDebug()<<query.lastError();
        return;
    }
    while (query.next()) {
      mname= query.value(0).toString();
      list.append(mname);
    }
    ui->student_majors_show_combo->addItems(list);
    ui->student_smajor_show_combo->addItems(list);
    update_student_list();
    //update grade info
    list.clear();
    int year=QDate::currentDate().year()%100;
    for(int i=1;i<year;++i)
        list.append(QString::number(i));
    ui->student_sgrade_combo->addItems(list);
}

QString Admin::deptno_to_dname(int dno)
{
    query.prepare("select dname from Dept where deptno=?");
    query.addBindValue(dno);
    if(!query.exec()){
        qDebug()<<query.lastError();
        return "";
    }
    if (query.next())
        return query.value(0).toString();
    return "";
}

void Admin::update_teacher_list()
{
    int deptno=Database::dname_to_deptno(ui->teacher_depts_combo->currentText());
    if(!deptno){
        QMessageBox::about(this,"操作失败","发生错误，请检查数据是否合法!");
        return;
    }
    QString tno,tname;
    query.prepare("select tno,tname from Teacher where tdept=?");
    query.addBindValue(deptno);
    if(!query.exec()){
        qDebug()<<query.lastError();
        return;
    }
    ui->teacher_show_list->clear();
    while (query.next()) {
      tno=  query.value(0).toString();
      tname= query.value(1).toString();
      ui->teacher_show_list->addItem(tno+' '+tname);
    }
}

void Admin::update_student_list()
{
    //find departmant
    int deptno=Database::dname_to_deptno(ui->student_depts_show_combo->currentText());
    if(!deptno){
        QMessageBox::about(this,"操作失败","发生错误，请检查数据是否合法!");
        return;
    }
    //find major
    ui->student_show_list->clear();
    if(!ui->student_majors_show_combo->count()) return;
    int majorno=Database::mname_to_majorno(ui->student_majors_show_combo->currentText());
    if(!majorno){
        QMessageBox::about(this,"操作失败","发生错误，请检查数据是否合法!");
        return;
    }
    QString sno,sname;
    query.prepare("select sno,sname from Student where sdept=? and smajor=?");
    query.addBindValue(deptno);
    query.addBindValue(majorno);
    if(!query.exec()){
        qDebug()<<query.lastError();
        return;
    }
    while (query.next()) {
      sno=  query.value(0).toString();
      sname= query.value(1).toString();
      ui->student_show_list->addItem(sno+' '+sname);
    }
}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_add_dept_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(this,
        tr("添加院系"), tr("院系名称"), QLineEdit::Normal,
        QString::null, &ok);
    if (ok && !text.isEmpty()){
        if(ui->depts->findItems(text,Qt::MatchExactly).size())
            QMessageBox::about(this,"添加失败","该项内容已存在！");
        else{
            query.prepare("insert into Dept(dname) values(?)");
            query.addBindValue(text);
            if(!query.exec()){
                qDebug()<<query.lastError();
                QMessageBox::about(this,"添加失败","发生错误，请检查数据是否合法!");
            }else{
                ui->depts->insertItem(ui->depts->currentRow()+1,text);
                ui->depts->setCurrentRow(ui->depts->currentRow()+1);
            }
        }
    }
}

void Admin::on_del_dept_clicked()
{
    int ret = QMessageBox::warning(this,tr("删除院系"),
         tr("确认删除吗?\n"
            "本操作将不可撤销"),
         QMessageBox::Yes | QMessageBox::No,
         QMessageBox::Yes);
    if(ret==QMessageBox::Yes){
        query.prepare("delete from Dept where dname=?");
        query.addBindValue(deptitem->text());
        if(!query.exec()){
            qDebug()<<query.lastError();
            QMessageBox::about(this,"删除失败","发生错误，请检查操作是否合法!");
        }else{
            ui->depts->takeItem(ui->depts->currentRow());
        }
    }
}

void Admin::on_depts_itemSelectionChanged()
{
    //update item currently choosed
    deptitem=ui->depts->currentItem();
    currentDeptNo=Database::dname_to_deptno(ui->depts->currentItem()->text());
    if(!currentDeptNo){
        QMessageBox::about(this,"操作失败","发生错误，请检查数据是否合法!");
        return;
    }
    //get department number
    int dno=Database::dname_to_deptno(deptitem->text());
    if(!dno){
        QMessageBox::about(this,"操作失败","发生错误，请检查数据是否合法!");
        return;
    }
    //fetch major of this department
    QString mname;
    query.prepare("select mname from Major where mdept=?");
    query.addBindValue(dno);
    if(!query.exec()) return;
    ui->majors->clear();
    while (query.next()) {
      mname= query.value(0).toString();
      //qDebug()<<mname;
      ui->majors->addItem(mname);
    }
}

void Admin::on_depts_itemDoubleClicked(QListWidgetItem *item)
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("修改院系名"),"",
       QLineEdit::Normal,item->text(),&ok);
    if(ok) {
       query.prepare("update Dept set dname=? where dname=?");
       query.addBindValue(text);
       query.addBindValue(item->text());
       if(!query.exec()){
           qDebug()<<query.lastError();
           QMessageBox::about(this,"修改失败","发生错误，请检查数据是否合法!");
       }else{
           item->setText(text);
       }
    }
}

void Admin::on_majors_itemSelectionChanged()
{
    //update item currently choosed
    majoritem=ui->majors->currentItem();
}

void Admin::on_majors_itemDoubleClicked(QListWidgetItem *item)
{
    //check department has been choosed
    if(currentDeptNo<0){
        QMessageBox::about(this,"添加失败","请先选择该专业所在的院系!");
        return;
    }
    //update major name
    bool ok;
    QString text = QInputDialog::getText(this, tr("修改专业名"),"",
       QLineEdit::Normal,item->text(),&ok);
    if(ok) {
       query.prepare("update Major set mname=? where mdept=? and mname=?");
       query.addBindValue(text);
       query.addBindValue(currentDeptNo);
       query.addBindValue(item->text());
       if(!query.exec()){
           qDebug()<<query.lastError();
           QMessageBox::about(this,"修改失败","发生错误，请检查数据是否合法!");
       }else{
           item->setText(text);
       }
    }
}

void Admin::on_add_major_clicked()
{
    //check department has been choosed
    if(currentDeptNo<0){
        QMessageBox::about(this,"添加失败","请先选择该专业所在的院系!");
        return;
    }
    //add major
    bool ok;
    QString text = QInputDialog::getText(this,
        tr("添加专业"), tr("专业名称"), QLineEdit::Normal,
        QString::null, &ok);
    if (ok && !text.isEmpty()){
        if(ui->majors->findItems(text,Qt::MatchExactly).size())
            QMessageBox::about(this,"添加失败","该项内容已存在！");
        else{
            query.prepare("insert into Major(mdept,mname) values(?,?)");
            query.addBindValue(currentDeptNo);
            query.addBindValue(text);
            if(!query.exec()){
                qDebug()<<query.lastError();
                QMessageBox::about(this,"添加失败","发生错误，请检查数据是否合法!");
            }else{
                ui->majors->insertItem(ui->majors->currentRow()+1,text);
                ui->majors->setCurrentRow(ui->majors->currentRow()+1);
            }
        }
    }
}

void Admin::on_del_major_clicked()
{
    //check department has been choosed
    if(currentDeptNo<0){
        QMessageBox::about(this,"添加失败","请先选择该专业所在的院系!");
        return;
    }
    //delete major
    int ret = QMessageBox::warning(this,tr("删除专业"),
         tr("确认删除吗?\n"
            "本操作将不可撤销"),
         QMessageBox::Yes | QMessageBox::No,
         QMessageBox::Yes);
    if(ret==QMessageBox::Yes){
        query.prepare("delete from Major where mdept=? and mname=?");
        query.addBindValue(currentDeptNo);
        query.addBindValue(majoritem->text());
        if(!query.exec()){
            qDebug()<<query.lastError();
            QMessageBox::about(this,"删除失败","发生错误，请检查操作是否合法!");
        }else{
            ui->majors->takeItem(ui->majors->currentRow());
        }
    }
}

void Admin::on_teacher_add_btn_clicked()
{
    int tno=ui->teacher_tno_edit->text().toInt();
    if(tno==0){
        QMessageBox::about(this,"添加失败","发生错误，请检查数据是否合法!");
        return;
    }
    QString tname=ui->teacher_tname_edit->text();
    if(tname.length()==0){
        QMessageBox::about(this,"添加失败","发生错误，请检查数据是否合法!");
        return;
    }
    QString tpwd=ui->teacher_tpwd_edit->text();
    if(tpwd.length()==0){
        QMessageBox::about(this,"添加失败","发生错误，请检查数据是否合法!");
        return;
    }
    QString md5=Utils::getMd5(tpwd);
    QString dname=ui->teacher_tdept_combo->currentText();
    int deptno=Database::dname_to_deptno(dname);
    if(!deptno){
        QMessageBox::about(this,"操作失败","发生错误，请检查数据是否合法!");
        return;
    }
    query.prepare("insert into Teacher(tno,tname,tpwd,tdept) values(?,?,?,?)");
    query.addBindValue(tno);
    query.addBindValue(tname);
    query.addBindValue(md5);
    query.addBindValue(deptno);
    if(!query.exec()){
        qDebug()<<query.lastError();
        QMessageBox::about(this,"添加失败","发生错误，请检查数据是否合法!");
    }else{
        update_teacher_list();
    }
}

void Admin::on_teacher_depts_combo_currentIndexChanged(const QString &arg1)
{
    ui->teacher_show_list->clear();
    update_teacher_list();
}


void Admin::on_teacher_show_list_itemSelectionChanged()
{
    if(ui->teacher_show_list->currentRow()<0){
        return;
    }
    QString str=ui->teacher_show_list->currentItem()->text();
    int tno=str.section(' ',0,0).toInt();
    query.prepare("select * from Teacher where tno=?");
    query.addBindValue(tno);
    if(!query.exec()){
        qDebug()<<query.lastError();
        QMessageBox::about(this,"查询失败","发生错误，请检查数据是否合法!");
    }else if(query.next()){
        ui->teacher_tno_edit->setText(query.value(0).toString());
        ui->teacher_tpwd_edit->setText("请输入新密码，或保持原密码");
        ui->teacher_tname_edit->setText(query.value(2).toString());
        ui->teacher_tdept_combo->setCurrentText(ui->teacher_depts_combo->currentText());
    }else{
        QMessageBox::about(this,"查询失败","发生错误，请检查数据是否合法!");
    }
}

void Admin::on_teacher_modify_btn_clicked()
{
    if(ui->teacher_show_list->currentRow()<0){
        QMessageBox::about(this,"修改失败","请先选择要修改的对象!");
        return;
    }
    //fetch teacher data
    QString str=ui->teacher_show_list->currentItem()->text();
    int oldtno=str.section(' ',0,0).toInt();
    int newtno=ui->teacher_tno_edit->text().toInt();
    //qDebug()<<"tno"<<newtno;
    if(!newtno){
        QMessageBox::about(this,"操作失败","发生错误，请检查数据是否合法!");
        return;
    }
    QString tname=ui->teacher_tname_edit->text();
    if(!tname.length()){
        QMessageBox::about(this,"操作失败","发生错误，请检查数据是否合法!");
        return;
    }
    int tdept=Database::dname_to_deptno(ui->teacher_tdept_combo->currentText());
    if(!tdept){
        QMessageBox::about(this,"操作失败","发生错误，请检查数据是否合法!");
        return;
    }
    bool flag=true;
    QString pwd=ui->teacher_tpwd_edit->text();
    //add teacher info
    if(pwd=="请输入新密码，或使用原密码" || pwd.length()==0){
        flag=false;
        query.prepare("update Teacher set tno=?,tname=?,tdept=? where tno=?");
    }else
        query.prepare("update Teacher set tno=?,tpwd=?,tname=?,tdept=? where tno=?");
    query.addBindValue(newtno);
    if(flag) query.addBindValue(Utils::getMd5(pwd));
    query.addBindValue(tname);
    query.addBindValue(tdept);
    query.addBindValue(oldtno);

    if(!query.exec()){
        qDebug()<<query.lastError();
        QMessageBox::about(this,"修改失败","发生错误，请检查数据是否合法!");
    }else{
        ui->teacher_show_list->currentItem()->setText(QString::number(newtno)+" "+tname);
    }
}

void Admin::on_teacher_search_btn_clicked()
{
    QString search=ui->teacher_search_edit->text();
    if(search.length()==0){
        QMessageBox::about(this,"查找失败","请填写要查找的内容!");
        return;
    }
    int tno=search.toInt();
    //qDebug()<<tno;
    QString tname;
    QStringList list;
    if(tno!=0){
        query.prepare("select tname from Teacher where tno=?");
        query.addBindValue(tno);
        if(!query.exec()){
            qDebug()<<query.lastError();
            QMessageBox::about(this,"删除失败","发生错误，请检查数据是否合法!");
        }else{
            if(query.next()){
                ui->teacher_show_list->clear();
                tname=query.value(0).toString();
                ui->teacher_show_list->addItem(QString::number(tno)+" "+tname);
                return;
            }
        }
    }else{
        query.prepare("select tno from Teacher where tname=?");
        query.addBindValue(search);
        if(!query.exec()){
            qDebug()<<query.lastError();
            QMessageBox::about(this,"删除失败","发生错误，请检查数据是否合法!");
        }else{
            while(query.next()){
                tno=query.value(0).toInt();
                list.append(QString::number(tno)+" "+search);
            }
            if(list.size()){
                ui->teacher_show_list->clear();
                ui->teacher_show_list->addItems(list);
                return;
            }
        }
    }
    QMessageBox::about(this,"查找失败","未找到查找的内容!");
}

void Admin::on_teacher_delete_btn_clicked()
{
    if(ui->teacher_show_list->currentRow()<0){
        QMessageBox::about(this,"删除失败","请先选择要删除的对象!");
        return;
    }
    QString str=ui->teacher_show_list->currentItem()->text();
    int tno=str.section(' ',0,0).toInt();
    //qDebug()<<tno;
    query.prepare("delete from Teacher where tno=?");
    query.addBindValue(tno);
    if(!query.exec()){
        qDebug()<<query.lastError();
        QMessageBox::about(this,"删除失败","发生错误，请检查数据是否合法!");
    }else{
        ui->teacher_show_list->takeItem(ui->teacher_show_list->currentRow());
        ui->teacher_tno_edit->clear();
        ui->teacher_tname_edit->clear();
        ui->teacher_tpwd_edit->clear();
    }
}


void Admin::on_student_add_btn_clicked()
{
    int sno=ui->student_sno_edit->text().toInt();
    if(sno==0){
        QMessageBox::about(this,"添加失败","发生错误，请检查数据是否合法!");
        return;
    }
    QString sname=ui->student_sname_edit->text();
    if(sname.length()==0){
        QMessageBox::about(this,"添加失败","发生错误，请检查数据是否合法!");
        return;
    }
    int sgrade=ui->student_sgrade_combo->currentText().toInt();
    QString spwd=ui->student_spwd_edit->text();
    if(spwd.length()==0){
        QMessageBox::about(this,"添加失败","发生错误，请检查数据是否合法!");
        return;
    }
    QString md5=Utils::getMd5(spwd);
    QString dname=ui->student_sdept_show_combo->currentText();
    QString mname=ui->student_smajor_show_combo->currentText();
    int deptno=Database::dname_to_deptno(dname);
    if(!deptno){
        QMessageBox::about(this,"操作失败","发生错误，请检查数据是否合法!");
        return;
    }
    int majorno=Database::mname_to_majorno(mname);
    if(!majorno){
        QMessageBox::about(this,"操作失败","发生错误，请检查数据是否合法!");
        return;
    }
    query.prepare("insert into Student(sno,sname,sgrade,spwd,sdept,smajor) values(?,?,?,?,?,?)");
    query.addBindValue(sno);
    query.addBindValue(sname);
    query.addBindValue(sgrade);
    query.addBindValue(md5);
    query.addBindValue(deptno);
    query.addBindValue(majorno);
    if(!query.exec()){
        qDebug()<<query.lastError();
        QMessageBox::about(this,"添加失败","发生错误，请检查数据是否合法!");
    }else{
        QMessageBox::about(this,"添加学生","添加成功!");
        update_student_list();
    }
}

void Admin::on_student_modify_btn_clicked()
{
    if(ui->student_show_list->currentRow()<0){
        QMessageBox::about(this,"修改失败","请先选择要修改的对象!");
        return;
    }
    //fetch student data
    QString str=ui->student_show_list->currentItem()->text();
    int oldsno=str.section(' ',0,0).toInt();
    int newsno=ui->student_sno_edit->text().toInt();
    if(!newsno){
        QMessageBox::about(this,"操作失败","发生错误，请检查数据是否合法!");
        return;
    }
    QString sname=ui->student_sname_edit->text();
    QString mname=ui->student_smajor_show_combo->currentText();
    int sgrade=ui->student_sgrade_combo->currentText().toInt();
    int sdept=Database::dname_to_deptno(ui->student_sdept_show_combo->currentText());
    if(!sdept){
        QMessageBox::about(this,"操作失败","发生错误，请检查数据是否合法!");
        return;
    }
    int smajor=Database::mname_to_majorno(mname);
    if(!smajor){
        QMessageBox::about(this,"操作失败","发生错误，请检查数据是否合法!");
        return;
    }
    bool flag=true;
    QString pwd=ui->student_spwd_edit->text();
    //add teacher info
    if(pwd=="请输入新密码，或使用原密码" || pwd.length()==0){
        flag=false;
        query.prepare("update Student set sno=?,sname=?,sgrade=?,sdept=?,smajor=? where sno=?");
    }else
        query.prepare("update Student set sno=?,sname=?,spwd=?,sgrade=?,sdept=?,smajor=? where sno=?");
    query.addBindValue(newsno);
    query.addBindValue(sname);
    if(flag) query.addBindValue(Utils::getMd5(pwd));
    query.addBindValue(sgrade);
    query.addBindValue(sdept);
    query.addBindValue(smajor);
    query.addBindValue(oldsno);

    if(!query.exec()){
        qDebug()<<query.lastError();
        QMessageBox::about(this,"修改失败","发生错误，请检查数据是否合法!");
    }else{
        ui->student_show_list->currentItem()->setText(QString::number(newsno)+" "+sname);
    }
}

void Admin::on_student_delete_btn_clicked()
{
    if(ui->student_show_list->currentRow()<0){
        QMessageBox::about(this,"删除失败","请先选择要删除的对象!");
        return;
    }
    QString str=ui->student_show_list->currentItem()->text();
    int sno=str.section(' ',0,0).toInt();
    //qDebug()<<sno;
    query.prepare("delete from Student where sno=?");
    query.addBindValue(sno);
    if(!query.exec()){
        qDebug()<<query.lastError();
        QMessageBox::about(this,"删除失败","发生错误，请检查数据是否合法!");
    }else{
        ui->student_show_list->takeItem(ui->student_show_list->currentRow());
        ui->student_sno_edit->clear();
        ui->student_sname_edit->clear();
        ui->student_spwd_edit->clear();
        ui->student_sgrade_combo->setCurrentIndex(0);
    }
}

void Admin::on_student_depts_show_combo_currentIndexChanged(const QString &arg1)
{
    //update major
    int deptno=Database::dname_to_deptno(arg1);
    QString mname;
    QStringList list;
    query.prepare("select mname from Major where mdept=?");
    query.addBindValue(deptno);
    if(!query.exec()){
        qDebug()<<query.lastError();
        return;
    }
    while (query.next()) {
      mname= query.value(0).toString();
      list.append(mname);
    }
    ui->student_majors_show_combo->clear();
    ui->student_majors_show_combo->addItems(list);
    //if(!ui->student_majors_show_combo->count()) return;
    //update student
    update_student_list();
}

void Admin::on_student_majors_show_combo_currentIndexChanged(const QString &arg1)
{
    update_student_list();
}

void Admin::on_student_show_list_itemSelectionChanged()
{
    if(ui->student_show_list->currentRow()<0){
        return;
    }
    QString str=ui->student_show_list->currentItem()->text();
    int sno=str.section(' ',0,0).toInt();
    query.prepare("select * from Student where sno=?");
    query.addBindValue(sno);
    if(!query.exec()){
        qDebug()<<query.lastError();
        QMessageBox::about(this,"查询失败","发生错误，请检查数据是否合法!");
    }else if(query.next()){
        ui->student_sno_edit->setText(query.value(0).toString());
        ui->student_spwd_edit->setText("请输入新密码，或保持原密码");
        ui->student_sname_edit->setText(query.value(3).toString());
        ui->student_sgrade_combo->setCurrentText(query.value(4).toString());
    }else{
        QMessageBox::about(this,"查询失败","发生错误，请检查数据是否合法!");
    }
}

void Admin::on_student_sdept_show_combo_currentIndexChanged(const QString &arg1)
{
    //update major
    int deptno=Database::dname_to_deptno(arg1);
    QString mname;
    QStringList list;
    query.prepare("select mname from Major where mdept=?");
    query.addBindValue(deptno);
    if(!query.exec()){
        qDebug()<<query.lastError();
        return;
    }
    while (query.next()) {
      mname= query.value(0).toString();
      list.append(mname);
    }
    ui->student_smajor_show_combo->clear();
    ui->student_smajor_show_combo->addItems(list);
}

void Admin::on_student_search_btn_clicked()
{
    QString search=ui->student_search_edit->text();
    if(search.length()==0){
        QMessageBox::about(this,"查找失败","请填写要查找的内容!");
        return;
    }
    int sno=search.toInt();
    QString sname;
    QStringList list;
    if(sno!=0){
        query.prepare("select sname from Student where sno=?");
        query.addBindValue(sno);
        if(!query.exec()){
            qDebug()<<query.lastError();
            QMessageBox::about(this,"删除失败","发生错误，请检查数据是否合法!");
        }else{
            if(query.next()){
                ui->student_show_list->clear();
                sname=query.value(0).toString();
                ui->student_show_list->addItem(QString::number(sno)+" "+sname);
                return;
            }
        }
    }else{
        query.prepare("select sno from Student where sname=?");
        query.addBindValue(search);
        if(!query.exec()){
            qDebug()<<query.lastError();
            QMessageBox::about(this,"删除失败","发生错误，请检查数据是否合法!");
        }else{
            while(query.next()){
                sno=query.value(0).toInt();
                list.append(QString::number(sno)+" "+search);
            }
            if(list.size()){
                ui->student_show_list->clear();
                ui->student_show_list->addItems(list);
                return;
            }
        }
    }
    QMessageBox::about(this,"查找失败","未找到查找的内容!");
}
