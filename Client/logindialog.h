#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QCloseEvent>
namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT
signals:
    void send_login_info(QString,QList<QString>*);
public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();
    int user;
    int number;
private slots:
    void on_login_clicked();
    void LoginOK();
    void LoginFailed();
protected:
    void closeEvent(QCloseEvent *event);
private:
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H
