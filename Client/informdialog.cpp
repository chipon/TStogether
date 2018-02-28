#include "informdialog.h"
#include "ui_informdialog.h"

void InformDialog::GetInformInfo(QList<Message> *msglist)
{
    QString s;
    foreach (Message m, *msglist) {
        s=m.time+" "+m.name+"在课程"+m.cname+"中说"+m.msg;
        ui->textBrowser->append(s);
    }
}

InformDialog::InformDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InformDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("消息提醒");
}

InformDialog::~InformDialog()
{
    delete ui;
}

void InformDialog::on_inform_clear_clicked()
{
    ui->textBrowser->clear();
    this->accept();
}

void InformDialog::on_inform_close_clicked()
{
    ui->textBrowser->clear();
    this->reject();
}
