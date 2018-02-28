#ifndef DEPT_H
#define DEPT_H
#include <QList>
#include <QString>

class Dept
{
public:
    Dept();

    QString dname;
    QList<QString> majors;
};

#endif // DEPT_H
