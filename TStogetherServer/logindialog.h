#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QSqlQuery>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();
private slots:
    void on_login_clicked();

private:
    QSqlQuery query;
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H