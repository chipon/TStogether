#ifndef STUDENTCOURSE_H
#define STUDENTCOURSE_H

#include <QMainWindow>
#include <course.h>
#include <QList>
#include <student.h>
#include <chatroom.h>
#include <message.h>
#include <courseware.h>
#include <QFileDialog>
namespace Ui {
class StudentCourse;
}

class StudentCourse : public QMainWindow
{
    Q_OBJECT
signals:
    void SendMessageRequest(QString,QList<QString>*);
    void SendMessageResponseOKMid(QString,int,QString);
    void SendMessageResponseFDMid();
    void SendWindowTitleInfo(QString,int,QString);

    void GetRecentMessageRequest(QString,QList<QString>*);
    void GetRecentMessageResponseOKMid(int,QList<Message>*);
    void GetRecentMessageResponseFDMid();

    void DownloadFileRequest(QString,QList<QString>*);
    void CloseCourseWindow(StudentCourse *sc);
public:
    Course c;
    explicit StudentCourse(QWidget *parent = 0);
    ~StudentCourse();
    void updateUser(Student *stu);
protected:
    void closeEvent(QCloseEvent *event);
private slots:
    void GetCourseInfoResponseOK(Course *c);
    void GetCourseInfoResponseFD();
    void on_course_chat_btn_clicked();

    void SendMessageRequestMid(QString type,QList<QString> *list);
    void SendMessageResponseOK(QString name,int cno,QString msg);
    void SendMessageResponseFD();

    void GetRecentMessageResponseOK(int cno,QList<Message>* msglist);
    void GetRecentMessageResponseFD();

    void GetCoursewareResponseOK(QList<Courseware> *filelist);
    void GetCoursewareResponseFD();
    void LinkHandler(QString s);

    void DownloadFileResponseOK(int cno);
    void DownloadFileResponseFD();
private:
    ChatRoom *cr;
    Student *stu;
    Ui::StudentCourse *ui;
};

#endif // STUDENTCOURSE_H
