#include "createcourse.h"
#include "ui_createcourse.h"
#include <QMessageBox>
#include <QInputDialog>
#include <qdebug.h>

CreateCourse::CreateCourse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateCourse)
{
    ui->setupUi(this);
    c=new Course();
}

CreateCourse::~CreateCourse()
{
    delete ui;
}

void CreateCourse::updateUser(int tno)
{
    this->tno=tno;
    c->tnolist.append(tno);
}

void CreateCourse::updateMajor()
{
    QString dname=ui->course_cdept_combo->currentText();
    foreach (Dept dept, *list) {
        if(dept.dname==dname){
            ui->course_cmajor_combo->clear();
            foreach (QString s, dept.majors) {
                ui->course_cmajor_combo->addItem(s);
            }
            break;
        }
    }
}

void CreateCourse::GetDeptInfoFailed()
{
    QMessageBox::about(this,"服务器错误","获取院系信息失败");
    return;
}

void CreateCourse::GetDeptInfoOK(QList<Dept> *list)
{
    this->list=list;
    foreach (Dept dept, *list) {
        ui->course_cdept_combo->addItem(dept.dname);
    }
    updateMajor();
}

void CreateCourse::FindTeacherByTnoResponseOK(QString tname)
{
    ui->course_cteacher_list->addItem(QString::number(tmptno)+" "+tname);
    c->tnolist.append(tmptno);
    this->update();
}

void CreateCourse::FindTeacherByTnoResponseFD()
{
    QMessageBox::about(this,"操作失败","发生错误，请检查数据是否合法!");
}


void CreateCourse::on_course_create_btn_clicked()
{
    c->cname=ui->course_cname_edit->text();
    c->cdept=ui->course_cdept_combo->currentText();
    c->cmajor=ui->course_cmajor_combo->currentText();
    c->cintro=ui->course_cintro_text->toPlainText();
    QList<QString> *list=new QList<QString>();
    list->append(c->cdept);
    list->append(c->cintro);
    list->append(c->cmajor);
    list->append(c->cname);
    list->append(QString::number(c->tnolist.size()));
    foreach (int i, c->tnolist) {
       list->append(QString::number(i));
    }
    emit CreateCourseRequest("CreateCourseRequest",list);
}

void CreateCourse::on_course_cancel_btn_clicked()
{
    this->reject();
}

void CreateCourse::on_course_cdept_combo_currentIndexChanged(const QString &arg1)
{
    updateMajor();
}

void CreateCourse::on_course_add_teacher_btn_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(this,
        tr("添加开课教师"), tr("请输入教师号"), QLineEdit::Normal,
        QString::null, &ok);
    if(!ok)
        return;
    if(text.length()==0){
        QMessageBox::about(this,"修改失败","密码不能为空");
        return;
    }
    tmptno=text.toInt();
    if(tmptno==0){
        QMessageBox::about(this,"操作失败","发生错误，请检查数据是否合法!");
        return;
    }else if(tmptno==tno){
        QMessageBox::about(this,"操作失败","您已是该课程的创建者");
        return;
    }else if(c->tnolist.indexOf(tmptno)!=-1){
        QMessageBox::about(this,"操作失败","该教师已在列表中");
        return;
    }
    QList<QString> *list=new QList<QString>();
    list->append(text);
    emit FindTeacherByTnoRequest("FindTeacherByTno",list);
}

void CreateCourse::CreateCourseResponseOK(int cno)
{
    //qDebug()<<cno<<ui->course_cname_edit->text();
    emit SendCourseInfo(QString::number(cno)+" "+ui->course_cname_edit->text());
    this->accept();
}

void CreateCourse::CreateCourseResponseFD()
{
    QMessageBox::about(this,"操作失败","发生错误，请检查数据是否合法!");
    return;
}
