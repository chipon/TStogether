#ifndef STUDENT_H
#define STUDENT_H
#include <QString>

class Student
{
public:
    Student();
//    Student(int sno, int sdept, int smajor, int sgrade, QString sname,
//        QString snickname, QString spwd, QString ssignature);

    int sno,sgrade;
    QString sname,snickname,sdept,smajor;
    QString spwd,ssignature;
};

#endif // STUDENT_H
