#ifndef COURSEWINDOW_H
#define COURSEWINDOW_H

#include <QMainWindow>
#include <course.h>
#include <teacher.h>
#include <chatroom.h>
#include <message.h>
#include <QLabel>
#include <courseware.h>
namespace Ui {
class CourseWindow;
}

class CourseWindow : public QMainWindow
{
    Q_OBJECT
signals:
    void SendMessageRequest(QString,QList<QString>*);
    void SendMessageResponseOKMid(QString,int,QString);
    void SendMessageResponseFDMid();

    void SendWindowTitleInfo(QString,int,QString);

    void GetRecentMessageRequest(QString,QList<QString>*);
    void GetRecentMessageResponseOKMid(int cno,QList<Message>*);
    void GetRecentMessageResponseFDMid();

    void UploadFileRequest(QString,QList<QString>*);

    void DownloadFileRequest(QString,QList<QString>*);

    void CloseCourseWindow(CourseWindow *cw);
private slots:
    void GetCourseInfoResponseOK(Course *c);
    void GetCourseInfoResponseFD();
    void on_course_char_btn_clicked();

    void SendMessageRequestMid(QString type,QList<QString>* list);
    void SendMessageResponseOK(QString name,int cno,QString msg);
    void SendMessageResponseFD();

    void GetRecentMessageResponseOK(int cno, QList<Message> *msglist);
    void GetRecentMessageResponseFD();
    void on_course_upload_file_btn_clicked();

    void UploadFileResponseOK(int fno);
    void UploadFileResponseFD();
    void LinkHandler(QString s);

    void DownloadFileResponseOK(int cno);
    void DownloadFileResponseFD();

    void GetCoursewareResponseOK(QList<Courseware> *filelist);
    void GetCoursewareResponseFD();
public:
    Course c;
    explicit CourseWindow(QWidget *parent = 0);
    ~CourseWindow();
    void update_user(Teacher *t);
private:
    Teacher *t;
    ChatRoom *cr;
    QString fname;
    //QLabel *label;
    //QList<QLabel*> filelist;
    Ui::CourseWindow *ui;
protected:
    void closeEvent(QCloseEvent *event);
};

#endif // COURSEWINDOW_H
