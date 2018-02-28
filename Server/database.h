#ifndef DATABASE_H
#define DATABASE_H
#include <QSqlError>
#include <QSqlQuery>
#include <QList>
#include <student.h>
#include <teacher.h>
#include <course.h>
#include <courseware.h>
#include <dept.h>
#include <message.h>
#define MAX_MSG_COUNT 50
#define UPLOAD_PATH

class Database
{
public:
    Database();
    static bool login(int user, int number, QString pwd);
    static QStringList get_all_dept_major();
    static QStringList get_major_by_dname(QString dname);
    static int dname_to_deptno(QString dname);
    static int mname_to_majorno(QString mname);
    static Student get_student_by_sno(int sno);
    static Teacher get_teacher_by_tno(int tno);
    static bool update_student_info(QString name, QString pwd, QString sig, int sno);
    static bool update_teacher_info(QString pwd,QString email,int tno);
    static QList<Dept> get_dept_info();
    static QString find_teacher_by_tno(int tno);
    static int create_course(Course c);
    static QList<QString> get_teacher_course(int tno);
    static Course get_course_info_by_cno(int cno);
    static int get_deptno_by_sno(int sno);
    static int get_majorno_by_sno(int sno);
    static QList<Course> search_course(QString search,int sno);
    static bool get_course_teacher_info(Course &c);
    static bool add_course_by_cno(int sno, int cno);
    static QList<QString> get_student_course(int sno);
    static QString add_message(bool user, int number, int cno, QString msg);
    static bool student_join_course(int sno, int cno);
    static bool teacher_start_course(int tno, int cno);
    static QList<Message> get_recent_message(int cno);
    static QString get_message_username(bool user,int number);
    static int add_courseware(int cno, QString path);
    static QString get_courseware_path(int fno);
    static QList<Courseware> get_courseware_info_by_cno(int cno);
};

#endif // DATABASE_H
