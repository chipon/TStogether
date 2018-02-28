#include "studentinfodialog.h"
#include "ui_studentinfodialog.h"
#include <utils.h>
#include <QInputDialog>
StudentInfoDialog::StudentInfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentInfoDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("查看个人信息");
    list=new QList<QString>();
}

StudentInfoDialog::~StudentInfoDialog()
{
    delete ui;
}

void StudentInfoDialog::UpdateStudentInfoOK()
{
    //qDebug()<<"size"<<list->size();
    emit UpdateStudentInfo(list);
    Utils::sleep(0.1);
    this->accept();
}

void StudentInfoDialog::UpdateStudentInfoFailed()
{
    QMessageBox::about(this,"修改失败","请检查数据是否合法");
    return;
}

void StudentInfoDialog::receiveStudentInfo(Student *stu)
{
    this->stu=stu;
    ui->sdept_label->setText(stu->sdept);
    ui->smajor_label->setText(stu->smajor);
    ui->sno_label->setText(QString::number(stu->sno));
    ui->snickname_edit->setText(stu->snickname);
    ui->spwd_edit->setText("test");
    ui->grade_label->setText(QString::number(stu->sgrade));
    ui->ssignature_edit->setText(stu->ssignature);
}


void StudentInfoDialog::on_student_confirm_btn_clicked()
{
    this->reject();
}

void StudentInfoDialog::on_student_modify_btn_clicked()
{
    bool ok;
    QString pwdstr=ui->spwd_edit->text();
    if(pwdstr!="test"){
        QString text = QInputDialog::getText(this,
            tr("用户验证"), tr("请输入原密码"), QLineEdit::Password,
            QString::null, &ok);
        if(!ok) return;
        if(Utils::getMd5(text)!=stu->spwd){
            QMessageBox::about(this,"密码错误","请重新输入密码");
            return;
        }
    }
    if(pwdstr.length()==0){
        QMessageBox::about(this,"修改失败","密码不能为空");
        return;
    }
    QString pwd=Utils::getMd5(pwdstr);
    QString nickname=ui->snickname_edit->text();
    if(nickname.length()==0){
        QMessageBox::about(this,"修改失败","昵称不能为空");
        return;
    }
    QString signature=ui->ssignature_edit->toPlainText();
    QList<QString> *list=new QList<QString>();
    list->clear();
    list->append(nickname);
    list->append(pwd);
    list->append(signature);
    this->list->append(nickname);
    this->list->append(pwd);
    this->list->append(signature);
    emit UpdateStudentInfo("UpdateStudentInfo",list);
}
