#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <logindialog.h>
#include <studentinfodialog.h>
#include <QMessageBox>
#include <QDebug>
#include <searchdialog.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("学生首页");
//    label=new QLabel("<a href = http://www.baidu.com >大学计算机</a>");
//    label->setOpenExternalLinks(true);
//    ui->listWidget->add->addItem(*label);
//    ui->verticalLayout->addWidget(label);
//    ui->listWidget->addItem("");
//    ui->listWidget->addItem("数据结构");
    //    ui->listWidget->addItem("计算机网络");
}

void MainWindow::update_user_info()
{
    emit send_student_info_request("GetStudentInfo");
    Utils::sleep(0.1);
    emit GetStudentCourseRequest("GetStudentCourseRequest");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_student_info_tbtn_clicked()
{
    StudentInfoDialog sid;
    connect(this,SIGNAL(sendStudentInfo(Student*)),&sid,SLOT(receiveStudentInfo(Student*)));
    connect(&sid,SIGNAL(UpdateStudentInfo(QList<QString>*)),this,SLOT(UpdateStudentInfo(QList<QString>*)));
    connect(&sid,SIGNAL(UpdateStudentInfo(QString,QList<QString>*)),this,SLOT(UpdateStudentInfoMW(QString,QList<QString>*)));

    connect(this,SIGNAL(UpdateStudentInfoOKMW()),&sid,SLOT(UpdateStudentInfoOK()));
    connect(this,SIGNAL(UpdateStudentInfoFailedMW()),&sid,SLOT(UpdateStudentInfoFailed()));
    emit sendStudentInfo(&stu);
    sid.exec();
//    if(sid.exec()==QDialog::Accepted){
//
//    }
}

void MainWindow::GetStudentInfoOK(Student *stu)
{
    this->stu=*stu;
    ui->nickname_label->setText(stu->snickname);
    ui->signature_browser->setText(stu->ssignature);
    delete stu;
}

void MainWindow::GetStudentInfoFailed()
{
    QMessageBox::about(this,"操作失败","发生错误，请检查数据是否合法!");
    return;
}

void MainWindow::UpdateStudentInfoOK()
{
    emit UpdateStudentInfoOKMW();
}

void MainWindow::UpdateStudentInfoFailed()
{
    emit UpdateStudentInfoFailedMW();
}

void MainWindow::UpdateStudentInfo(QList<QString> *list)
{
    //qDebug()<<list<<list->size();
    stu.snickname=list->at(0);
    stu.spwd=list->at(1);
    stu.ssignature=list->at(2);
    ui->nickname_label->setText(stu.snickname);
    ui->signature_browser->setText(stu.ssignature);
    delete list;
}

void MainWindow::UpdateStudentInfoMW(QString type, QList<QString> *list)
{
    emit UpdateStudentInfo(type,list);
}

void MainWindow::on_course_search_btn_clicked()
{
    SearchDialog sd;
    connect(&sd,SIGNAL(SearchCourseRequest(QString,QList<QString>*)),this,SLOT(SearchCourseRequestMid(QString,QList<QString>*)));
    connect(this,SIGNAL(SearchCourseResponseOKMid(QList<Course>*)),&sd,SLOT(SearchCourseResponseOK(QList<Course>*)));
    connect(this,SIGNAL(SearchCourseResponseFDMid()),&sd,SLOT(SearchCourseResponseFD()));

    connect(&sd,SIGNAL(AddCourseRequest(QString,QList<QString>*)),this,SLOT(AddCourseRequestMid(QString,QList<QString>*)));
    connect(this,SIGNAL(AddCourseResponseOKMid()),&sd,SLOT(AddCourseResponseOK()));
    connect(this,SIGNAL(AddCourseResponseFDMid()),&sd,SLOT(AddCourseResponseFD()));

    connect(this,SIGNAL(SendStudentCourseInfo(QList<QString>*)),&sd,SLOT(ReadStudentCourseInfo(QList<QString>*)));
    connect(&sd,SIGNAL(SendNewCourseInfo(QList<QString>*)),this,SLOT(ReadNewCourseInfo(QList<QString>*)));

    QList<QString> *list=new QList<QString>();
    QString search=ui->course_search_edit->text();
    list->append(search);

    emit SendStudentCourseInfo(courselist);
    //if(search.length()==0) QMessageBox::about(this,"未填入搜索值","将显示所有可选的课程");
    emit SearchCourseRequest("SearchCourseRequest",list);
    Utils::sleep(0.3);
    sd.exec();
}

void MainWindow::SearchCourseRequestMid(QString type, QList<QString> *list)
{
    emit SearchCourseRequest(type,list);
}

void MainWindow::SearchCourseResponseOK(QList<Course> *list)
{
    emit SearchCourseResponseOKMid(list);
}

void MainWindow::SearchCourseResponseFD()
{
    emit SearchCourseResponseFDMid();
}

void MainWindow::AddCourseRequestMid(QString type, QList<QString> *list)
{
    emit AddCourseRequest(type,list);
}

void MainWindow::AddCourseResponseOK()
{
    emit AddCourseResponseOKMid();
}

void MainWindow::AddCourseResponseFD()
{
    emit AddCourseResponseFDMid();
}

void MainWindow::GetStudentCourseResponseOK(QList<QString> *list)
{
    this->courselist=list;
    foreach (QString s, *list) {
        ui->course_list->addItem(s);
    }
}

void MainWindow::GetStudentCourseResponseFD()
{
    QMessageBox::about(this,"获取课程失败","服务器出错了");
    return;
}

void MainWindow::ReadNewCourseInfo(QList<QString> *list)
{
    foreach (QString s, *list) {
        ui->course_list->addItem(s);
    }
    delete list;
}

void MainWindow::on_course_list_itemDoubleClicked(QListWidgetItem *item)
{
    QString str=item->text();
    int cno=str.section(' ',0,0).toInt();
    foreach (StudentCourse *sc, sclist) {
        if(sc->c.cno==cno){
            sc->activateWindow();
            return;
        }
    }
    StudentCourse *sc=new StudentCourse();
    sclist.append(sc);
    sc->setAttribute(Qt::WA_DeleteOnClose, true);
    sc->updateUser(&stu);
    connect(this,SIGNAL(GetCourseInfoResponseOKMid(Course*)),sc,SLOT(GetCourseInfoResponseOK(Course*)));
    connect(this,SIGNAL(GetCourseInfoResponseFDMid()),sc,SLOT(GetCourseInfoResponseFD()));

    connect(sc,SIGNAL(SendMessageRequest(QString,QList<QString>*)),this,SLOT(SendMessageRequestMid(QString,QList<QString>*)));
    connect(this,SIGNAL(SendMessageResponseOKMid(QString,int,QString)),sc,SLOT(SendMessageResponseOK(QString,int,QString)));
    connect(this,SIGNAL(SendMessageResponseFDMid()),sc,SLOT(SendMessageResponseFD()));

    connect(sc,SIGNAL(GetRecentMessageRequest(QString,QList<QString>*)),this,SLOT(GetRecentMessageRequestMid(QString,QList<QString>*)));
    connect(this,SIGNAL(GetRecentMessageResponseOKMid(int,QList<Message>*)),sc,SLOT(GetRecentMessageResponseOK(int,QList<Message>*)));
    connect(this,SIGNAL(GetRecentMessageResponseFDMid()),sc,SLOT(GetRecentMessageResponseFD()));

    connect(this,SIGNAL(GetCoursewareResponseOKMid(QList<Courseware>*)),sc,SLOT(GetCoursewareResponseOK(QList<Courseware>*)));
    connect(this,SIGNAL(GetCoursewareResponseFDMid()),sc,SLOT(GetRecentMessageResponseFD()));

    connect(sc,SIGNAL(DownloadFileRequest(QString,QList<QString>*)),this,SLOT(DownloadFileRequestMid(QString,QList<QString>*)));
    connect(this,SIGNAL(DownloadFileResponseOKMid(int)),sc,SLOT(DownloadFileResponseOK(int)));
    connect(this,SIGNAL(DownloadFileResponseFDMid()),sc,SLOT(DownloadFileResponseFD()));

    connect(sc,SIGNAL(CloseCourseWindow(StudentCourse*)),this,SLOT(CloseCourseWindow(StudentCourse*)));
    QList<QString> *list=new QList<QString>();
    list->append(item->text().section(' ',0,0));
    emit GetCourseInfoRequest("GetCourseInfoRequest",list);
    Utils::sleep(0.2);

    disconnect(this,SIGNAL(GetCourseInfoResponseOKMid(Course*)),sc,SLOT(GetCourseInfoResponseOK(Course*)));
    disconnect(this,SIGNAL(GetCourseInfoResponseFDMid()),sc,SLOT(GetCourseInfoResponseFD()));

    list=new QList<QString>();
    list->append(item->text().section(' ',0,0));
    emit GetCoursewareRequest("GetCoursewareRequest",list);
    Utils::sleep(0.2);

    sc->show();
    Utils::suit_window(sc);
}

void MainWindow::GetCourseInfoResponseOK(Course *c)
{
    emit GetCourseInfoResponseOKMid(c);
}

void MainWindow::GetCourseInfoResponseFD()
{
    emit GetCourseInfoResponseFDMid();
}

void MainWindow::SendMessageRequestMid(QString type, QList<QString> *list)
{
    emit SendMessageRequest(type,list);
}

void MainWindow::SendMessageResponseOK(QString name,int cno,QString msg)
{
    emit SendMessageResponseOKMid(name,cno,msg);
}

void MainWindow::SendMessageResponseFD()
{
    emit SendMessageResponseFDMid();
}

void MainWindow::GetRecentMessageRequestMid(QString type, QList<QString> *list)
{
    emit GetRecentMessageRequest(type,list);
}

void MainWindow::GetRecentMessageResponseOK(int cno, QList<Message> *list)
{
    emit GetRecentMessageResponseOKMid(cno,list);
}

void MainWindow::GetRecentMessageResponseFD()
{
    emit GetRecentMessageResponseFDMid();
}

void MainWindow::GetCoursewareResponseOK(QList<Courseware> *list)
{
    emit GetCoursewareResponseOKMid(list);
}

void MainWindow::GetCoursewareResponseFD()
{
    emit GetCoursewareResponseFDMid();
}

void MainWindow::DownloadFileRequestMid(QString type, QList<QString> *list)
{
    emit DownloadFileRequest(type,list);
}

void MainWindow::DownloadFileResponseOK(int cno)
{
    emit DownloadFileResponseOKMid(cno);
}

void MainWindow::DownloadFileResponseFD()
{
    emit DownloadFileResponseFDMid();
}

void MainWindow::CloseCourseWindow(StudentCourse *sc)
{
    sclist.removeAll(sc);
}

