#include "teacherwindow.h"
#include "ui_teacherwindow.h"
#include <QSqlError>
#include <QDebug>
#include <utils.h>
#include <teacherinfodialog.h>
#include <createcourse.h>
#include <QMessageBox>
#include <informdialog.h>

TeacherWindow::TeacherWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TeacherWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("教师首页");
}

//void TeacherWindow::update_user(int tno)
//{
//    this->tno=tno;
//    query.prepare("select * from Teacher where tno=?");
//    query.addBindValue(tno);
//    if(!query.exec()){
//        qDebug()<<query.lastError();
//        return;
//    }
//    if(!query.next()){
//        QMessageBox::about(this,"操作失败","发生错误，请检查数据是否合法!");
//        return;
//    }
//    ui->nickname_label->setText(query.value(2).toString());
//}

TeacherWindow::~TeacherWindow()
{
    delete ui;
}

void TeacherWindow::update_user_info()
{
    emit GetTeacherInfo("GetTeacherInfo");
    Utils::sleep(0.1);
    emit GetTeacherCourseRequest("GetTeacherCourseRequest");
}

void TeacherWindow::GetDeptInfoFailed()
{
    emit GetDeptInfoFailedMW();
}

void TeacherWindow::GetDeptInfoOK(QList<Dept> *list)
{
    emit GetDeptInfoOKMW(list);
}

void TeacherWindow::UpdateTeacherInfoOK()
{
    emit UpdateTeacherInfoOKMW();
}

void TeacherWindow::UpdateTeacherInfoFailed()
{
    emit UpdateTeacherInfoFailedMW();
}

void TeacherWindow::UpdateTeacherInfo(QList<QString> *list)
{
    t.tpwd=list->at(0);
    t.temail=list->at(1);
    ui->teacher_email_label->setText(t.temail);
}

void TeacherWindow::UpdateTeacherInfoMW(QString type, QList<QString> *list)
{
    emit UpdateTeacherInfo(type,list);
}

void TeacherWindow::on_create_course_btn_clicked()
{
    CreateCourse cc;
    //qDebug()<<"tno:"<<t->tno;
    cc.updateUser(t.tno);
    connect(this,SIGNAL(GetDeptInfoFailedMW()),&cc,SLOT(GetDeptInfoFailed()));
    connect(this,SIGNAL(GetDeptInfoOKMW(QList<Dept>*)),&cc,SLOT(GetDeptInfoOK(QList<Dept>*)));

    connect(&cc,SIGNAL(FindTeacherByTnoRequest(QString,QList<QString>*)),this,SLOT(FindTeacherByTnoRequestMid(QString,QList<QString>*)));
    connect(this,SIGNAL(FindTeacherByTnoResponseOKMid(QString)),&cc,SLOT(FindTeacherByTnoResponseOK(QString)));
    connect(this,SIGNAL(FindTeacherByTnoResponseFDMid()),&cc,SLOT(FindTeacherByTnoResponseFD()));

    connect(&cc,SIGNAL(CreateCourseRequest(QString,QList<QString>*)),this,SLOT(CreateCourseRequestMid(QString,QList<QString>*)));
    connect(this,SIGNAL(CreateCourseResponseOKMid(int)),&cc,SLOT(CreateCourseResponseOK(int)));
    connect(this,SIGNAL(CreateCourseResponseFDMid()),&cc,SLOT(CreateCourseResponseFD()));
    connect(&cc,SIGNAL(SendCourseInfo(QString)),this,SLOT(ReceiveCourseInfo(QString)));

    emit GetDeptInfo("GetDeptInfo");
    cc.exec();
}

void TeacherWindow::on_teacher_info_tbtn_clicked()
{
    TeacherInfoDialog tid;
    connect(this,SIGNAL(SendTeacherInfo(Teacher*)),&tid,SLOT(ReceiveTeacherInfo(Teacher*)));
    connect(&tid,SIGNAL(UpdateTeacherInfo(QList<QString>*)),this,SLOT(UpdateTeacherInfo(QList<QString>*)));
    connect(&tid,SIGNAL(UpdateTeacherInfo(QString,QList<QString>*)),this,SLOT(UpdateTeacherInfoMW(QString,QList<QString>*)));
    connect(this,SIGNAL(UpdateTeacherInfoOKMW()),&tid,SLOT(UpdateTeacherInfoOK()));
    connect(this,SIGNAL(UpdateTeacherInfoFailedMW()),&tid,SLOT(UpdateTeacherInfoFailed()));
    emit SendTeacherInfo(&t);
    tid.exec();
}

void TeacherWindow::GetTeacherInfoOK(Teacher *t)
{
    this->t=*t;
    ui->teacher_name_label->setText(t->tname);
    ui->teacher_email_label->setText(t->temail);
    //qDebug()<<t->tdept<<t->temail<<t->tname<<t->tno<<t->tpwd;
}

void TeacherWindow::GetTeacherInfoFailed()
{
    QMessageBox::about(this,"操作失败","发生错误，请检查数据是否合法!");
    return;
}

void TeacherWindow::FindTeacherByTnoRequestMid(QString type, QList<QString> *list)
{
    emit FindTeacherByTnoRequest(type,list);
}

void TeacherWindow::FindTeacherByTnoResponseOK(QString tname)
{
    emit FindTeacherByTnoResponseOKMid(tname);
}

void TeacherWindow::FindTeacherByTnoResponseFD()
{
    emit FindTeacherByTnoResponseFDMid();
}

void TeacherWindow::CreateCourseRequestMid(QString type, QList<QString> *list)
{
    emit CreateCourseRequest(type,list);
}

void TeacherWindow::CreateCourseResponseOK(int i)
{
    emit CreateCourseResponseOKMid(i);
}

void TeacherWindow::CreateCourseResponseFD()
{
    emit CreateCourseResponseFDMid();
}

void TeacherWindow::ReceiveCourseInfo(QString s)
{
    ui->course_list->addItem(s);
    //this->update();
}

void TeacherWindow::GetTeacherCourseResponseOK(QList<QString> *list)
{
    foreach (QString s, *list) {
        ui->course_list->addItem(s);
    }
}

void TeacherWindow::GetTeacherCourseResponseFD()
{
    //QMessageBox::about(this,"服务器出错了","获取课程失败");
    return;
}

void TeacherWindow::on_course_list_itemDoubleClicked(QListWidgetItem *item)
{
    QString str=item->text();
    int cno=str.section(' ',0,0).toInt();
    foreach (CourseWindow *cw, courselist) {
        if(cw->c.cno==cno){
            cw->activateWindow();
            return;
        }
    }
    CourseWindow *cw=new CourseWindow();
    courselist.append(cw);
    cw->update_user(&t);
    connect(this,SIGNAL(GetCourseInfoResponseOKMid(Course*)),cw,SLOT(GetCourseInfoResponseOK(Course*)));
    connect(this,SIGNAL(GetCourseInfoResponseFDMid()),cw,SLOT(GetCourseInfoResponseFD()));

    connect(cw,SIGNAL(SendMessageRequest(QString,QList<QString>*)),this,SLOT(SendMessageRequestMid(QString,QList<QString>*)));
    connect(this,SIGNAL(SendMessageResponseOKMid(QString,int,QString)),cw,SLOT(SendMessageResponseOK(QString,int,QString)));
    connect(this,SIGNAL(SendMessageResponseFDMid()),cw,SLOT(SendMessageResponseFD()));

    connect(cw,SIGNAL(GetRecentMessageRequest(QString,QList<QString>*)),this,SLOT(GetRecentMessageRequestMid(QString,QList<QString>*)));
    connect(this,SIGNAL(GetRecentMessageResponseOKMid(int,QList<Message>*)),cw,SLOT(GetRecentMessageResponseOK(int,QList<Message>*)));
    connect(this,SIGNAL(GetRecentMessageResponseFDMid()),cw,SLOT(GetRecentMessageResponseFD()));

    connect(cw,SIGNAL(UploadFileRequest(QString,QList<QString>*)),this,SLOT(UploadFileRequestMid(QString,QList<QString>*)));
    connect(this,SIGNAL(UploadFileResponseOKMid(int)),cw,SLOT(UploadFileResponseOK(int)));
    connect(this,SIGNAL(UploadFileResponseFDMid()),cw,SLOT(UploadFileResponseFD()));

    connect(cw,SIGNAL(DownloadFileRequest(QString,QList<QString>*)),this,SLOT(DownloadFileRequestMid(QString,QList<QString>*)));
    connect(this,SIGNAL(DownloadFileResponseOKMid(int)),cw,SLOT(DownloadFileResponseOK(int)));
    connect(this,SIGNAL(DownloadFileResponseFDMid()),cw,SLOT(DownloadFileResponseFD()));

    connect(this,SIGNAL(GetCoursewareResponseOKMid(QList<Courseware>*)),cw,SLOT(GetCoursewareResponseOK(QList<Courseware>*)));
    connect(this,SIGNAL(GetCoursewareResponseFDMid()),cw,SLOT(GetCoursewareResponseFD()));

    connect(cw,SIGNAL(CloseCourseWindow(CourseWindow*)),this,SLOT(CloseCourseWindow(CourseWindow*)));
    QList<QString> *list=new QList<QString>();
    list->append(QString::number(cno));
    emit GetCourseInfoRequest("GetCourseInfoRequest",list);
    Utils::sleep(0.2);
    list=new QList<QString>();
    list->append(QString::number(cno));
    emit GetCoursewareRequest("GetCoursewareRequest",list);
    Utils::sleep(0.4);
    cw->show();
    Utils::suit_window(cw);
    disconnect(this,SIGNAL(GetCourseInfoResponseOKMid(Course*)),cw,SLOT(GetCourseInfoResponseOK(Course*)));
    disconnect(this,SIGNAL(GetCourseInfoResponseFDMid()),cw,SLOT(GetCourseInfoResponseFD()));
}

void TeacherWindow::GetCourseInfoResponseOK(Course *c)
{
    emit GetCourseInfoResponseOKMid(c);
}

void TeacherWindow::GetCourseInfoResponseFD()
{
    emit GetCourseInfoResponseFDMid();
}

void TeacherWindow::SendMessageRequestMid(QString type, QList<QString> *list)
{
    emit SendMessageRequest(type,list);
}

void TeacherWindow::SendMessageResponseOK(QString name, int cno, QString msg)
{
    emit SendMessageResponseOKMid(name,cno,msg);
}

void TeacherWindow::SendMessageResponseFD()
{
    emit SendMessageResponseFDMid();
}

void TeacherWindow::GetRecentMessageRequestMid(QString type, QList<QString> *list)
{
    emit GetRecentMessageRequest(type,list);
}

void TeacherWindow::GetRecentMessageResponseOK(int cno, QList<Message> *msglist)
{
    emit GetRecentMessageResponseOKMid(cno,msglist);
}

void TeacherWindow::GetRecentMessageResponseFD()
{
    emit GetRecentMessageResponseFDMid();
}

void TeacherWindow::UploadFileRequestMid(QString path, QList<QString> *list)
{
    emit UploadFileRequest(path,list);
}

void TeacherWindow::UploadFileResponseOK(int fno)
{
    emit UploadFileResponseOKMid(fno);
}

void TeacherWindow::UploadFileResponseFD()
{
    emit UploadFileResponseFDMid();
}

void TeacherWindow::DownloadFileRequestMid(QString type, QList<QString> *list)
{
    emit DownloadFileRequest(type,list);
}

void TeacherWindow::DownloadFileResponseOK(int fno)
{
    emit DownloadFileResponseOKMid(fno);
}


void TeacherWindow::DownloadFileResponseFD()
{
    emit DownloadFileResponseFDMid();
}

void TeacherWindow::GetCoursewareResponseOK(QList<Courseware> *list)
{
    emit GetCoursewareResponseOKMid(list);
}

void TeacherWindow::GetCoursewareResponseFD()
{
    emit GetCoursewareResponseFDMid();
}

void TeacherWindow::on_teacher_inform_tbtn_clicked()
{
    InformDialog id;
    id.exec();
}

void TeacherWindow::CloseCourseWindow(CourseWindow *cw)
{
    courselist.removeAll(cw);
}
