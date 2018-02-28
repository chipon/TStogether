#ifndef COURSE_H
#define COURSE_H
#include <QString>
#include <QList>

class Course
{
public:
    Course();

    int cno;
    QString cname,cintro,cnotice,cdept,cmajor,ctime;
    QList<int> tnolist;
    QList<QString> tnamelist;
};

#endif // COURSE_H
