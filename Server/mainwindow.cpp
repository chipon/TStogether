#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <tcpcomhandler.h>
#include <QDebug>

void MainWindow::newClientConnect()
{
    QTcpSocket *socket = server->nextPendingConnection();
    TCPComHandler *handler=new TCPComHandler(socket);
    connect(handler,SIGNAL(SendMessageRequest(bool,int,int,QString,QString)),this,SLOT(SendMessageRequest(bool,int,int,QString,QString)));
    connect(this,SIGNAL(SendMessageResponse(bool,int,int,QString,QString)),handler,SLOT(SendMessageResponse(bool,int,int,QString,QString)));
    qDebug()<<"收到新的客户端请求";
}

void MainWindow::SendMessageRequest(bool user,int uno, int cno, QString name, QString msg)
{
    emit SendMessageResponse(user,uno,cno,name,msg);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    emit windowClosed();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("TStogether服务器");
    server = new QTcpServer(this);
    if(!server->listen(QHostAddress::LocalHost,6666)){ //本地主机的6666端口，如果出错就输出错误信息，并关闭
        qDebug() << server->errorString();
        close();
    }
    connect(server, SIGNAL(newConnection()), this, SLOT(newClientConnect()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
