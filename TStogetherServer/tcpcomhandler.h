#ifndef TCPCOMHANDLER_H
#define TCPCOMHANDLER_H
#include <QTcpServer>
#include <QTcpSocket>
#include <teacher.h>
#include <student.h>
#include <course.h>
#include <dept.h>
#include <message.h>
#include <QList>
#include <QFile>
#include <QDir>

class TCPComHandler:public QObject
{
    Q_OBJECT
signals:
    void SendMessageRequest(bool,int,int,QString,QString);
private slots:
    void handleData();
    void UpdateServerProgress();
    void UpdateClientProgress(qint64 numBytes);
    void SendMessageResponse(bool user, int uno, int cno, QString name, QString msg);
    //void displayError(QAbstractSocket::SocketError);
public:
    TCPComHandler(QTcpSocket * tcpsocket);
private:
    //QString kind;
    int user,number;
    //bool readFile;
    QString cnostr,filepath;
    //QList<QString> list;
    QTcpSocket *socket;
    qint64 totalBytes;	//存放总大小信息
    qint64 bytesReceived; //已收到数据的大小
    qint64 fileNameSize; //文件名的大小信息
    QString fileName; //存放文件名
    QFile *localFile; //本地文件
    QByteArray block; //数据缓冲区

    bool readFile,sendFile;
//    QByteArray block;
//    QFile *localFile;   //要发送的文件
//    qint64 totalBytes;  //数据总大小
    qint64 bytesWritten;    //已经发送数据大小
    qint64 bytesToWrite;    //剩余数据大小
    qint64 loadSize;    //每次发送数据的大小
//    QTcpSocket *socket;
//    FileProcessDialog fpd;
    void sendData(QString type);
    void updateFileErrorHandler();
};

#endif // TCPCOMHANDLER_H
