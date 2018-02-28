#include "coursewindow.h"
#include "ui_coursewindow.h"
#include <QMessageBox>
#include <utils.h>
#include <QFileDialog>

void CourseWindow::GetCourseInfoResponseOK(Course *c)
{
    this->c=*c;
    ui->course_intro_text->setText(c->cintro);
    ui->course_name_label->setText(c->cname);
    ui->course_notice_text->setText(c->cnotice);
    ui->course_cdept_label->setText(c->cdept);
    ui->course_cmajor_label->setText(c->cmajor);
    int tno,size=c->tnolist.size();
    QString tname;
    for(int i=0;i<size;++i){
        tno=c->tnolist.at(i);
        tname=c->tnamelist.at(i);
        ui->course_teacher_list->addItem(QString::number(tno)+" "+tname);
    }
    this->setWindowTitle(c->cname);
    delete c;
}

void CourseWindow::GetCourseInfoResponseFD()
{
    QMessageBox::about(this,"服务器出错了","获取课程失败");
    return;
}

CourseWindow::CourseWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CourseWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("教师课程");
    cr=nullptr;
}

CourseWindow::~CourseWindow()
{
    delete ui;
}

void CourseWindow::update_user(Teacher *t)
{
    this->t=t;
}

void CourseWindow::closeEvent(QCloseEvent *event)
{
    emit CloseCourseWindow(this);
    QMainWindow::closeEvent(event);
}

void CourseWindow::on_course_char_btn_clicked()
{
    if(cr!=nullptr){
        cr->activateWindow();
        return;
    }
    cr=new ChatRoom(this);
    connect(cr,SIGNAL(SendMessageRequest(QString,QList<QString>*)),this,SLOT(SendMessageRequestMid(QString,QList<QString>*)));
    connect(this,SIGNAL(SendMessageResponseOKMid(QString,int,QString)),cr,SLOT(SendMessageResponseOK(QString,int,QString)));
    connect(this,SIGNAL(SendMessageResponseFDMid()),cr,SLOT(SendMessageResponseFD()));
    connect(this,SIGNAL(SendWindowTitleInfo(QString,int,QString)),cr,SLOT(ReadWindowTitleInfo(QString,int,QString)));

    connect(this,SIGNAL(GetRecentMessageResponseOKMid(int,QList<Message>*)),cr,SLOT(GetRecentMessageResponseOK(int,QList<Message>*)));
    connect(this,SIGNAL(GetRecentMessageResponseFDMid()),cr,SLOT(GetRecentMessageResponseFD()));
    emit SendWindowTitleInfo(t->tname+"老师",c.cno,c.cname);
    cr->setAttribute(Qt::WA_DeleteOnClose, true);

    QList<QString> *list=new QList<QString>();
    list->append(QString::number(c.cno));
    emit GetRecentMessageRequest("GetRecentMessageRequest",list);
    Utils::sleep(0.2);
    cr->show();
    Utils::suit_window(cr);
}

void CourseWindow::SendMessageRequestMid(QString type, QList<QString> *list)
{
    list->append(QString::number(c.cno));
    emit SendMessageRequest(type,list);
}

void CourseWindow::SendMessageResponseOK(QString name, int cno, QString msg)
{
    emit SendMessageResponseOKMid(name,cno,msg);
}

void CourseWindow::SendMessageResponseFD()
{
    emit SendMessageResponseFDMid();
}

void CourseWindow::GetRecentMessageResponseOK(int cno, QList<Message> *msglist)
{
    emit GetRecentMessageResponseOKMid(cno,msglist);
}

void CourseWindow::GetRecentMessageResponseFD()
{
    emit GetRecentMessageResponseFDMid();
}

void CourseWindow::on_course_upload_file_btn_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, tr("选择上传文件"), ".");
    if(path.length() == 0) {
        QMessageBox::information(this, tr("路径为空"), tr("未选择任何文件"));
        return;
    }
    //qDebug()<<path;
    fname=path.right(path.size()-path.lastIndexOf('/')-1);
    //qDebug()<<fname;
    QList<QString> *list=new QList<QString>();
    list->append(QString::number(c.cno));

    emit UploadFileRequest(path,list);
}

void CourseWindow::UploadFileResponseOK(int fno)
{
    //QLabel label;
    //connect(&label,SIGNAL(linkActivated(QString))
    QMessageBox::information(this, tr("提示"), tr("文件上传成功"));
    QLabel *label=new QLabel("<a href = "+QString::number(fno)+" >"+fname+"</a>");
    connect(label,SIGNAL(linkActivated(QString)),this,SLOT(LinkHandler(QString)));
    //label->setOpenExternalLinks(true);
//    ui->listWidget->add->addItem(*label);
//    ui->verticalLayout->addWidget(label);
//    ui->listWidget->addItem("");
//    ui->listWidget->addItem("数据结构");
//    ui->listWidget->addItem("计算机网络");
    ui->courseware_layout->addWidget(label);
}

void CourseWindow::UploadFileResponseFD()
{
    QMessageBox::information(this, tr("上传错误"), tr("您已经上传过此文件"));
    return;
}

void CourseWindow::LinkHandler(QString s)
{
    int fno=s.toInt();
    QString folder = QFileDialog::getExistingDirectory(this,tr("保存课件"),".",QFileDialog::ShowDirsOnly|QFileDialog::DontResolveSymlinks); //选择路径
    if(folder.isEmpty()){
        QMessageBox::information(this, tr("路径为空"), tr("未设置任何文件"));
        return;
    }
    qDebug()<<folder;
    QList<QString> *list=new QList<QString>();
    list->append(QString::number(fno));
    list->append(folder);
    list->append(QString::number(c.cno));
    emit DownloadFileRequest("DownloadFileRequest",list);
}

void CourseWindow::DownloadFileResponseOK(int cno)
{
    QMessageBox::information(this, tr("提示"), tr("文件下载成功"));
}

void CourseWindow::DownloadFileResponseFD()
{
    QMessageBox::information(this, tr("服务器出错了"), tr("文件下载失败"));
    return;
}

void CourseWindow::GetCoursewareResponseOK(QList<Courseware> *filelist)
{
    QLabel *label;
    foreach (Courseware cw, *filelist) {
        label=new QLabel("<a href = "+QString::number(cw.cwno)+" >"+cw.cwname+"</a>");
        connect(label,SIGNAL(linkActivated(QString)),this,SLOT(LinkHandler(QString)));
        //filelist->append(label);
        ui->courseware_layout->addWidget(label);
    }
    //delete filelist;
}

void CourseWindow::GetCoursewareResponseFD()
{
    QMessageBox::information(this, tr("服务器出错了"), tr("获取课件信息失败"));
    return;
}
