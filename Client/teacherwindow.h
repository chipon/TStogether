#ifndef TEACHERWINDOW_H
#define TEACHERWINDOW_H

#include <QMainWindow>
#include <teacher.h>
#include <course.h>
#include <QList>
#include <dept.h>
#include <message.h>
#include <coursewindow.h>
#include <QListWidget>
#include <courseware.h>

namespace Ui {
class TeacherWindow;
}

class TeacherWindow : public QMainWindow
{
    Q_OBJECT
signals:
    void GetTeacherInfo(QString);
    void SendTeacherInfo(Teacher *);

    void UpdateTeacherInfo(QString,QList<QString>*);
    void UpdateTeacherInfoOKMW();
    void UpdateTeacherInfoFailedMW();

    void GetDeptInfo(QString);
    void GetDeptInfoOKMW(QList<Dept> *);
    void GetDeptInfoFailedMW();

    void FindTeacherByTnoRequest(QString type, QList<QString> *list);
    void FindTeacherByTnoResponseOKMid(QString);
    void FindTeacherByTnoResponseFDMid();

    void CreateCourseRequest(QString,QList<QString>*);
    void CreateCourseResponseOKMid(int);
    void CreateCourseResponseFDMid();

    void GetTeacherCourseRequest(QString);
    void GetCourseInfoRequest(QString,QList<QString>*);
    void GetCourseInfoResponseOKMid(Course *c);
    void GetCourseInfoResponseFDMid();

    void SendMessageRequest(QString,QList<QString>*);
    void SendMessageResponseOKMid(QString,int,QString);
    void SendMessageResponseFDMid();

    void GetRecentMessageRequest(QString,QList<QString>*);
    void GetRecentMessageResponseOKMid(int,QList<Message>*);
    void GetRecentMessageResponseFDMid();

    void UploadFileRequest(QString,QList<QString>*);
    void UploadFileResponseOKMid(int);
    void UploadFileResponseFDMid();

    void DownloadFileRequest(QString,QList<QString>*);
    void DownloadFileResponseOKMid(int);
    void DownloadFileResponseFDMid();

    void GetCoursewareRequest(QString,QList<QString>*);
    void GetCoursewareResponseOKMid(QList<Courseware>*);
    void GetCoursewareResponseFDMid();
public:
    explicit TeacherWindow(QWidget *parent = 0);
    ~TeacherWindow();
    void update_user_info();

private slots:
    void GetDeptInfoOK(QList<Dept> *list);

    void GetDeptInfoFailed();

    void UpdateTeacherInfoOK();

    void UpdateTeacherInfoFailed();

    void UpdateTeacherInfo(QList<QString>* list);

    void UpdateTeacherInfoMW(QString type, QList<QString>*list);

    void on_create_course_btn_clicked();

    void on_teacher_info_tbtn_clicked();

    void GetTeacherInfoOK(Teacher *t);

    void GetTeacherInfoFailed();


    void FindTeacherByTnoRequestMid(QString type,QList<QString>*list);

    void FindTeacherByTnoResponseOK(QString tname);

    void FindTeacherByTnoResponseFD();


    void CreateCourseRequestMid(QString type,QList<QString>* list);

    void CreateCourseResponseOK(int i);

    void CreateCourseResponseFD();

    void ReceiveCourseInfo(QString s);


    void GetTeacherCourseResponseOK(QList<QString> *list);
    void GetTeacherCourseResponseFD();

    void on_course_list_itemDoubleClicked(QListWidgetItem *item);

    void GetCourseInfoResponseOK(Course *c);
    void GetCourseInfoResponseFD();

    void SendMessageRequestMid(QString type,QList<QString>* list);
    void SendMessageResponseOK(QString name,int cno,QString msg);
    void SendMessageResponseFD();

    void GetRecentMessageRequestMid(QString type, QList<QString> *list);
    void GetRecentMessageResponseOK(int cno,QList<Message>* msglist);
    void GetRecentMessageResponseFD();

    void UploadFileRequestMid(QString path, QList<QString>* list);
    void UploadFileResponseOK(int fno);
    void UploadFileResponseFD();

    void DownloadFileRequestMid(QString type,QList<QString>* list);
    void DownloadFileResponseOK(int fno);
    void DownloadFileResponseFD();

    void GetCoursewareResponseOK(QList<Courseware> *list);
    void GetCoursewareResponseFD();
    void on_teacher_inform_tbtn_clicked();

    void CloseCourseWindow(CourseWindow *cw);
private:
    Teacher t;
    QList<CourseWindow *> courselist;
    Ui::TeacherWindow *ui;
};

#endif // TEACHERWINDOW_H
