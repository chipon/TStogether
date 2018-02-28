#ifndef TCPCOMHANDLER_H
#define TCPCOMHANDLER_H
#include <QtNetwork>
#include <QList>
#include <handler.h>
#include <student.h>
#include <teacher.h>
#include <course.h>
#include <message.h>
#include <courseware.h>
#include <dept.h>
#include <utils.h>
#include <QString>
#include <QFile>
#include <fileprocessdialog.h>

class TcpComHandler:public Handler
{
    Q_OBJECT
signals:
    void LoginOK();
    void LoginFailed();
    void GetStudentInfoFailed();
    void GetStudentInfoOK(Student *);
    void GetTeacherInfoFailed();
    void GetTeacherInfoOK(Teacher *);
    void UpdateStudentInfoOK();
    void UpdateStudentInfoFailed();
    void UpdateTeacherInfoOK();
    void UpdateTeacherInfoFailed();
    void GetDeptInfoOK(QList<Dept> *);
    void GetDeptInfoFailed();
    void FindTeacherByTnoResponseOK(QString);
    void FindTeacherByTnoResponseFD();
    void CreateCourseResponseOK(int);
    void CreateCourseResponseFD();
    void GetTeacherCourseResponseOK(QList<QString> *);
    void GetTeacherCourseResponseFD();
    void GetCourseInfoResponseOK(Course*);
    void GetCourseInfoResponseFD();
    void SearchCourseResponseOK(QList<Course> *);
    void SearchCourseResponseFD();
    void AddCourseResponseOK();
    void AddCourseResponseFD();
    void GetStudentCourseResponseOK(QList<QString> *);
    void GetStudentCourseResponseFD();
    void SendMessageResponseOK(QString,int,QString);
    void SendMessageResponseFD();
    void GetRecentMessageResponseOK(int,QList<Message>*);
    void GetRecentMessageResponseFD();
    void UploadFileResponseOK(int);
    void UploadFileResponseFD();
    void DownloadFileResponseOK(int);
    void DownloadFileResponseFD();
    void GetCoursewareResponseOK(QList<Courseware>*);
    void GetCoursewareResponseFD();
private slots:
    void readData();
    void sendData(QString type);
    void UploadFileRequest(QString path,QList<QString>* list);
    void UpdateClientProgress(qint64 numBytes);
    void sendData(QString type, QList<QString> *list);
    void UpdateServerProgress();
    void DownloadFileRequest(QString type, QList<QString> *list);
public:
    TcpComHandler();
    void updateFileErrorHandler();
private:
    bool readFile,sendFile;
    QByteArray block;
    QFile *localFile;   //要发送的文件
    qint64 totalBytes;  //数据总大小
    qint64 bytesWritten;    //已经发送数据大小
    qint64 bytesToWrite;    //剩余数据大小
    qint64 loadSize;    //每次发送数据的大小
    QTcpSocket *socket;
    FileProcessDialog fpd;

//    int user,number;
//    bool sendFile;
    QString cnostr,filepath;
//    //QList<QString> list;
//    QTcpSocket *socket;
//    qint64 totalBytes;	//存放总大小信息
    qint64 bytesReceived; //已收到数据的大小
    qint64 fileNameSize; //文件名的大小信息
    QString folder;
    QString fileName; //存放文件名
//    QFile *localFile; //本地文件
//    QByteArray block; //数据缓冲区
};

#endif // TCPCOMHANDLER_H
