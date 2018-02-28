#include "studentcourse.h"
#include "ui_studentcourse.h"
#include <QMessageBox>
#include <QDebug>
#include <utils.h>

StudentCourse::StudentCourse(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StudentCourse)
{
    ui->setupUi(this);
    cr=nullptr;
}

StudentCourse::~StudentCourse()
{
    delete ui;
}

void StudentCourse::GetCourseInfoResponseOK(Course *c)
{
    this->c=*c;
    //qDebug()<<"ok"<<c->cno;
    ui->course_intro_text->setText(c->cintro);
    ui->course_name_label->setText(c->cname);
    ui->course_notice_text->setText(c->cnotice);
    ui->course_cdept_label->setText(c->cdept);
    ui->course_cmajor_label->setText(c->cmajor);
    int size=c->tnolist.size();
    QString tname;
    for(int i=0;i<size;++i){
        tname=c->tnamelist.at(i);
        ui->course_teacher_list->addItem(tname+"老师");
    }
    this->setWindowTitle(c->cname+"课程");
    delete c;
}

void StudentCourse::GetCourseInfoResponseFD()
{
    QMessageBox::about(this,"服务器出错了","获取课程失败");
    return;
}

void StudentCourse::updateUser(Student *stu)
{
    this->stu=stu;
}

void StudentCourse::on_course_chat_btn_clicked()
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
    QString name=(stu->snickname.length())?stu->snickname:stu->sname;
    emit SendWindowTitleInfo(name,c.cno,c.cname);

    cr->setAttribute(Qt::WA_DeleteOnClose, true);
    QList<QString> *list=new QList<QString>();
    list->append(QString::number(c.cno));
    emit GetRecentMessageRequest("GetRecentMessageRequest",list);
    Utils::sleep(0.2);
    cr->show();
    Utils::suit_window(cr);
}

void StudentCourse::GetCoursewareResponseOK(QList<Courseware> *filelist)
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

void StudentCourse::GetCoursewareResponseFD()
{
    QMessageBox::about(this,"服务器出错了","获取课程失败");
    return;
}

void StudentCourse::closeEvent(QCloseEvent *event)
{
    emit CloseCourseWindow(this);
    QMainWindow::closeEvent(event);
}

void StudentCourse::SendMessageRequestMid(QString type, QList<QString> *list)
{
    //list->append(QString::number(0));
    list->append(QString::number(c.cno));
    emit SendMessageRequest(type,list);
}

void StudentCourse::SendMessageResponseOK(QString name,int cno,QString msg)
{
    emit SendMessageResponseOKMid(name,cno,msg);
}

void StudentCourse::SendMessageResponseFD()
{
    emit SendMessageResponseFDMid();
}

void StudentCourse::GetRecentMessageResponseOK(int cno, QList<Message> *msglist)
{
    emit GetRecentMessageResponseOKMid(cno,msglist);
}

void StudentCourse::GetRecentMessageResponseFD()
{
    emit GetRecentMessageResponseFDMid();
}

void StudentCourse::DownloadFileResponseOK(int cno)
{
    QMessageBox::information(this, tr("提示"), tr("文件下载成功"));
}

void StudentCourse::DownloadFileResponseFD()
{
    QMessageBox::information(this, tr("服务器出错了"), tr("文件下载失败"));
    return;
}

void StudentCourse::LinkHandler(QString s)
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
