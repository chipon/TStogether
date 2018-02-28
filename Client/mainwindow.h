#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <student.h>
#include <utils.h>
#include <course.h>
#include <student.h>
#include <courseware.h>
#include <tcpcomhandler.h>
#include <logindialog.h>
#include <QListWidgetItem>
#include <studentcourse.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
signals:
    void sendStudentInfo(Student *stu);
    void send_student_info_request(QString);
    void UpdateStudentInfo(QString,QList<QString>*);
    void UpdateStudentInfoOKMW();
    void UpdateStudentInfoFailedMW();

    void SearchCourseRequest(QString,QList<QString>*);
    void SearchCourseResponseOKMid(QList<Course> *list);
    void SearchCourseResponseFDMid();

    void AddCourseRequest(QString,QList<QString>*);
    void AddCourseResponseOKMid();
    void AddCourseResponseFDMid();

    void GetStudentCourseRequest(QString);
    void SendStudentCourseInfo(QList<QString>*);

    void GetCourseInfoRequest(QString,QList<QString>*);
    void GetCourseInfoResponseOKMid(Course*);
    void GetCourseInfoResponseFDMid();

    void SendMessageRequest(QString,QList<QString>*);
    void SendMessageResponseOKMid(QString,int,QString);
    void SendMessageResponseFDMid();

    void GetRecentMessageRequest(QString, QList<QString>*);
    void GetRecentMessageResponseOKMid(int,QList<Message>*);
    void GetRecentMessageResponseFDMid();

    void GetCoursewareRequest(QString, QList<QString>*);
    void GetCoursewareResponseOKMid(QList<Courseware>*);
    void GetCoursewareResponseFDMid();

    void DownloadFileRequest(QString, QList<QString>*);
    void DownloadFileResponseOKMid(int);
    void DownloadFileResponseFDMid();
public:
    explicit MainWindow(QWidget *parent = 0);
    void update_user_info();
    ~MainWindow();

private slots:
    void on_student_info_tbtn_clicked();
    void GetStudentInfoOK(Student *stu);
    void GetStudentInfoFailed();
    void UpdateStudentInfoOK();
    void UpdateStudentInfoFailed();
    void UpdateStudentInfo(QList<QString> *list);
    void UpdateStudentInfoMW(QString type, QList<QString> *list);
    void on_course_search_btn_clicked();

    void SearchCourseRequestMid(QString type, QList<QString>*list);
    void SearchCourseResponseOK(QList<Course> *list);
    void SearchCourseResponseFD();

    void AddCourseRequestMid(QString type, QList<QString>*list);
    void AddCourseResponseOK();
    void AddCourseResponseFD();

    void GetStudentCourseResponseOK(QList<QString> *list);
    void GetStudentCourseResponseFD();
    void ReadNewCourseInfo(QList<QString> *list);
    void on_course_list_itemDoubleClicked(QListWidgetItem *item);

    void GetCourseInfoResponseOK(Course *c);
    void GetCourseInfoResponseFD();

    void SendMessageRequestMid(QString type, QList<QString>*list);
    void SendMessageResponseOK(QString name, int cno, QString msg);
    void SendMessageResponseFD();

    void GetRecentMessageRequestMid(QString type, QList<QString>*list);
    void GetRecentMessageResponseOK(int cno,QList<Message> *list);
    void GetRecentMessageResponseFD();

    void GetCoursewareResponseOK(QList<Courseware>*list);
    void GetCoursewareResponseFD();

    void DownloadFileRequestMid(QString type, QList<QString>*list);
    void DownloadFileResponseOK(int cno);
    void DownloadFileResponseFD();

    void CloseCourseWindow(StudentCourse *sc);
private:
    Student stu;
    QList<StudentCourse *> sclist;
    QList<QString> *courselist;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
