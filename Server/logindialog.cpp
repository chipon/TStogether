#include "logindialog.h"
#include "ui_logindialog.h"
#include <mainwindow.h>
#include <QDebug>
#include <database.h>
#include <QMessageBox>
#include <QSqlError>
#include <utils.h>
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
    QString s = "select * from Admin where aname=? and apwd=?";
    QString username=ui->username->text();
    QString password=ui->password->text();
    query.prepare(s);
    query.bindValue(0,username);
    query.bindValue(1,Utils::getMd5(password));
    if(!query.exec()){
        qDebug()<<query.lastError();
        return;
    }else{
        if(query.next()){
            this->accept();
            return;
        }
    }
    QMessageBox msgbox;
    msgbox.setText(tr("登陆失败,请检查用户名或密码是否正确"));
    msgbox.exec();
}
