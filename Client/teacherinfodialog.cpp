#include "teacherinfodialog.h"
#include "ui_teacherinfodialog.h"
#include <QInputDialog>
#include <utils.h>

TeacherInfoDialog::TeacherInfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TeacherInfoDialog)
{
    ui->setupUi(this);
    list=new QList<QString>();
}

TeacherInfoDialog::~TeacherInfoDialog()
{
    delete ui;
}

void TeacherInfoDialog::UpdateTeacherInfoFailed()
{
    QMessageBox::about(this,"修改失败","请检查数据是否合法");
    return;
}

void TeacherInfoDialog::UpdateTeacherInfoOK()
{
    emit UpdateTeacherInfo(list);
    this->accept();
}

void TeacherInfoDialog::ReceiveTeacherInfo(Teacher *t)
{
    this->t=t;
    ui->tno_label->setText(QString::number(t->tno));
    ui->tdept_label->setText(t->tdept);
    ui->temail_edit->setText(t->temail);
    ui->tname_label->setText(t->tname);
    ui->tpwd_eidt->setText("test");
}

void TeacherInfoDialog::on_teacher_confirm_btn_clicked()
{
    this->reject();
}

void TeacherInfoDialog::on_teacher_modify_btn_clicked()
{
    bool ok;
    QString pwdstr=ui->tpwd_eidt->text();
    if(pwdstr!="test"){
        QString text = QInputDialog::getText(this,
            tr("用户验证"), tr("请输入原密码"), QLineEdit::Password,
            QString::null, &ok);
        if(!ok) return;
        if(Utils::getMd5(text)!=t->tpwd){
            QMessageBox::about(this,"密码错误","请重新输入密码");
            return;
        }
    }
    if(pwdstr.length()==0){
        QMessageBox::about(this,"修改失败","密码不能为空");
        return;
    }
    QString pwd=Utils::getMd5(pwdstr);
    QString email=ui->temail_edit->text();
    if(email.length()==0){
        QMessageBox::about(this,"修改失败","邮箱不能为空");
        return;
    }
    list->clear();
    list->append(pwd);
    list->append(email);
    emit UpdateTeacherInfo("UpdateTeacherInfo",list);
}
