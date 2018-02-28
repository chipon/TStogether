#include "mainwindow.h"
#include <QApplication>
#include <logindialog.h>
#include <QDesktopWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <tcpcomhandler.h>
#include <teacherwindow.h>
#include <QSqlTableModel>
#include <QSqlError>
#include <utils.h>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDialog d;
    TcpComHandler *handler=new TcpComHandler();
    QObject::connect(handler,SIGNAL(LoginOK()),&d,SLOT(LoginOK()));
    QObject::connect(handler,SIGNAL(LoginFailed()),&d,SLOT(LoginFailed()));
    QObject::connect(&d,SIGNAL(send_login_info(QString,QList<QString>*)),
        handler,SLOT(sendData(QString,QList<QString>*)));
    if(d.exec()==QDialog::Rejected)
        return 0;

    if(!d.user){
        MainWindow *mw=new MainWindow();
        QObject::connect(mw,SIGNAL(send_student_info_request(QString)),handler,SLOT(sendData(QString)));
        QObject::connect(handler,SIGNAL(GetStudentInfoFailed()),mw,SLOT(GetStudentInfoFailed()));
        QObject::connect(handler,SIGNAL(GetStudentInfoOK(Student*)),mw,SLOT(GetStudentInfoOK(Student*)));

        QObject::connect(mw,SIGNAL(UpdateStudentInfo(QString,QList<QString>*)),handler,SLOT(sendData(QString,QList<QString>*)));
        QObject::connect(handler,SIGNAL(UpdateStudentInfoOK()),mw,SLOT(UpdateStudentInfoOK()));
        QObject::connect(handler,SIGNAL(UpdateStudentInfoFailed()),mw,SLOT(UpdateStudentInfoFailed()));

        QObject::connect(mw,SIGNAL(SearchCourseRequest(QString,QList<QString>*)),handler,SLOT(sendData(QString,QList<QString>*)));
        QObject::connect(handler,SIGNAL(SearchCourseResponseOK(QList<Course>*)),mw,SLOT(SearchCourseResponseOK(QList<Course>*)));
        QObject::connect(handler,SIGNAL(SearchCourseResponseFD()),mw,SLOT(SearchCourseResponseFD()));

        QObject::connect(mw,SIGNAL(AddCourseRequest(QString,QList<QString>*)),handler,SLOT(sendData(QString,QList<QString>*)));
        QObject::connect(handler,SIGNAL(AddCourseResponseOK()),mw,SLOT(AddCourseResponseOK()));
        QObject::connect(handler,SIGNAL(AddCourseResponseFD()),mw,SLOT(AddCourseResponseFD()));

        QObject::connect(mw,SIGNAL(GetStudentCourseRequest(QString)),handler,SLOT(sendData(QString)));
        QObject::connect(handler,SIGNAL(GetStudentCourseResponseOK(QList<QString>*)),mw,SLOT(GetStudentCourseResponseOK(QList<QString>*)));
        QObject::connect(handler,SIGNAL(GetStudentCourseResponseFD()),mw,SLOT(GetStudentCourseResponseFD()));

        QObject::connect(mw,SIGNAL(GetCourseInfoRequest(QString,QList<QString>*)),handler,SLOT(sendData(QString,QList<QString>*)));
        QObject::connect(handler,SIGNAL(GetCourseInfoResponseOK(Course*)),mw,SLOT(GetCourseInfoResponseOK(Course*)));
        QObject::connect(handler,SIGNAL(GetCourseInfoResponseFD()),mw,SLOT(GetCourseInfoResponseFD()));

        QObject::connect(mw,SIGNAL(SendMessageRequest(QString,QList<QString>*)),handler,SLOT(sendData(QString,QList<QString>*)));
        QObject::connect(handler,SIGNAL(SendMessageResponseOK(QString,int,QString)),mw,SLOT(SendMessageResponseOK(QString,int,QString)));
        QObject::connect(handler,SIGNAL(SendMessageResponseFD()),mw,SLOT(SendMessageResponseFD()));

        QObject::connect(mw,SIGNAL(GetRecentMessageRequest(QString,QList<QString>*)),handler,SLOT(sendData(QString,QList<QString>*)));
        QObject::connect(handler,SIGNAL(GetRecentMessageResponseOK(int,QList<Message>*)),mw,SLOT(GetRecentMessageResponseOK(int,QList<Message>*)));
        QObject::connect(handler,SIGNAL(GetRecentMessageResponseFD()),mw,SLOT(GetRecentMessageResponseFD()));

        QObject::connect(mw,SIGNAL(GetCoursewareRequest(QString,QList<QString>*)),handler,SLOT(sendData(QString,QList<QString>*)));
        QObject::connect(handler,SIGNAL(GetCoursewareResponseOK(QList<Courseware>*)),mw,SLOT(GetCoursewareResponseOK(QList<Courseware>*)));
        QObject::connect(handler,SIGNAL(GetCoursewareResponseFD()),mw,SLOT(GetCoursewareResponseFD()));

        QObject::connect(mw,SIGNAL(DownloadFileRequest(QString,QList<QString>*)),handler,SLOT(DownloadFileRequest(QString,QList<QString>*)));
        QObject::connect(handler,SIGNAL(DownloadFileResponseOK(int)),mw,SLOT(DownloadFileResponseOK(int)));
        QObject::connect(handler,SIGNAL(DownloadFileResponseFD()),mw,SLOT(DownloadFileResponseFD()));
        mw->update_user_info();
        mw->show();
        Utils::suit_window(mw);
        //mw.move((desktop->width()-mw.width())/2,(desktop->height()-mw.height())/2);
    }else{
        TeacherWindow *tw=new TeacherWindow();
        QObject::connect(tw,SIGNAL(GetTeacherInfo(QString)),handler,SLOT(sendData(QString)));
        QObject::connect(handler,SIGNAL(GetTeacherInfoFailed()),tw,SLOT(GetTeacherInfoFailed()));
        QObject::connect(handler,SIGNAL(GetTeacherInfoOK(Teacher*)),tw,SLOT(GetTeacherInfoOK(Teacher*)));

        QObject::connect(tw,SIGNAL(UpdateTeacherInfo(QString,QList<QString>*)),handler,SLOT(sendData(QString,QList<QString>*)));
        QObject::connect(handler,SIGNAL(UpdateTeacherInfoOK()),tw,SLOT(UpdateTeacherInfoOK()));
        QObject::connect(handler,SIGNAL(UpdateTeacherInfoFailed()),tw,SLOT(UpdateTeacherInfoFailed()));

        QObject::connect(tw,SIGNAL(GetDeptInfo(QString)),handler,SLOT(sendData(QString)));
        QObject::connect(handler,SIGNAL(GetDeptInfoFailed()),tw,SLOT(GetDeptInfoFailed()));
        QObject::connect(handler,SIGNAL(GetDeptInfoOK(QList<Dept>*)),tw,SLOT(GetDeptInfoOK(QList<Dept>*)));

        QObject::connect(tw,SIGNAL(FindTeacherByTnoRequest(QString,QList<QString>*)),handler,SLOT(sendData(QString,QList<QString>*)));
        QObject::connect(handler,SIGNAL(FindTeacherByTnoResponseOK(QString)),tw,SLOT(FindTeacherByTnoResponseOK(QString)));
        QObject::connect(handler,SIGNAL(FindTeacherByTnoResponseFD()),tw,SLOT(FindTeacherByTnoResponseFD()));

        QObject::connect(tw,SIGNAL(CreateCourseRequest(QString,QList<QString>*)),handler,SLOT(sendData(QString,QList<QString>*)));
        QObject::connect(handler,SIGNAL(CreateCourseResponseOK(int)),tw,SLOT(CreateCourseResponseOK(int)));
        QObject::connect(handler,SIGNAL(CreateCourseResponseFD()),tw,SLOT(CreateCourseResponseFD()));

        QObject::connect(tw,SIGNAL(GetTeacherCourseRequest(QString)),handler,SLOT(sendData(QString)));
        QObject::connect(handler,SIGNAL(GetTeacherCourseResponseOK(QList<QString>*)),tw,SLOT(GetTeacherCourseResponseOK(QList<QString>*)));
        QObject::connect(handler,SIGNAL(GetTeacherCourseResponseFD()),tw,SLOT(GetTeacherCourseResponseFD()));

        QObject::connect(tw,SIGNAL(GetCourseInfoRequest(QString,QList<QString>*)),handler,SLOT(sendData(QString,QList<QString>*)));
        QObject::connect(handler,SIGNAL(GetCourseInfoResponseOK(Course*)),tw,SLOT(GetCourseInfoResponseOK(Course*)));
        QObject::connect(handler,SIGNAL(GetCourseInfoResponseFD()),tw,SLOT(GetCourseInfoResponseFD()));

        QObject::connect(tw,SIGNAL(SendMessageRequest(QString,QList<QString>*)),handler,SLOT(sendData(QString,QList<QString>*)));
        QObject::connect(handler,SIGNAL(SendMessageResponseOK(QString,int,QString)),tw,SLOT(SendMessageResponseOK(QString,int,QString)));
        QObject::connect(handler,SIGNAL(SendMessageResponseFD()),tw,SLOT(SendMessageResponseFD()));

        QObject::connect(tw,SIGNAL(GetRecentMessageRequest(QString,QList<QString>*)),handler,SLOT(sendData(QString,QList<QString>*)));
        QObject::connect(handler,SIGNAL(GetRecentMessageResponseOK(int,QList<Message>*)),tw,SLOT(GetRecentMessageResponseOK(int,QList<Message>*)));
        QObject::connect(handler,SIGNAL(GetRecentMessageResponseFD()),tw,SLOT(GetRecentMessageResponseFD()));

        QObject::connect(tw,SIGNAL(UploadFileRequest(QString,QList<QString>*)),handler,SLOT(UploadFileRequest(QString,QList<QString>*)));
        QObject::connect(handler,SIGNAL(UploadFileResponseOK(int)),tw,SLOT(UploadFileResponseOK(int)));
        QObject::connect(handler,SIGNAL(UploadFileResponseFD()),tw,SLOT(UploadFileResponseFD()));

        QObject::connect(tw,SIGNAL(DownloadFileRequest(QString,QList<QString>*)),handler,SLOT(DownloadFileRequest(QString,QList<QString>*)));
        QObject::connect(handler,SIGNAL(DownloadFileResponseOK(int)),tw,SLOT(DownloadFileResponseOK(int)));
        QObject::connect(handler,SIGNAL(DownloadFileResponseFD()),tw,SLOT(DownloadFileResponseFD()));

        QObject::connect(tw,SIGNAL(GetCoursewareRequest(QString,QList<QString>*)),handler,SLOT(sendData(QString,QList<QString>*)));
        QObject::connect(handler,SIGNAL(GetCoursewareResponseOK(QList<Courseware>*)),tw,SLOT(GetCoursewareResponseOK(QList<Courseware>*)));
        QObject::connect(handler,SIGNAL(GetCoursewareResponseFD()),tw,SLOT(GetCoursewareResponseFD()));
        tw->update_user_info();
        //Utils::sleep(0.1);
        tw->show();
        Utils::suit_window(tw);
        //tw.move((desktop->width()-tw.width())/2,(desktop->height()-tw.height())/2);
    }
    return a.exec();
}
