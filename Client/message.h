#ifndef MESSAGE_H
#define MESSAGE_H
#include <QString>

class Message
{
public:
    Message();
    int cno;
    QString msg;
    QString time;
    QString name;   //sender name
    QString cname;  //course name
};

#endif // MESSAGE_H
