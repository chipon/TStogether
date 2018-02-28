#include "logindialog.h"
#include "ui_logindialog.h"
#include <mainwindow.h>
#include <QDebug>
#include <utils.h>
#include <QMessageBox>
#include <QSqlError>
#include <utils.h>
#include <tcpcomhandler.h>
#include <QCryptographicHash>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("登陆");
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_login_clicked()
{
    user=ui->logintype->currentIndex();
    number=ui->number->text().toInt();
    QString pwdstr=ui->password->text();
    if(number==0 || pwdstr.length()==0){
        QMessageBox::about(this,"操作失败","发生错误，请检查数据是否合法!");
        return;
    }
    QString pwd=Utils::getMd5(pwdstr);
    QList<QString> *list=new QList<QString>();
    list->append(QString::number(user));
    list->append(QString::number(number));
    list->append(pwd);
    emit send_login_info("Login",list);
}

void LoginDialog::LoginOK()
{
    this->accept();
}

void LoginDialog::LoginFailed()
{
    QMessageBox::about(this,"操作失败","发生错误，请检查数据是否合法!");
    return;
}

void LoginDialog::closeEvent(QCloseEvent *event)
{
    this->reject();
}

