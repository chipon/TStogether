#ifndef INFORMDIALOG_H
#define INFORMDIALOG_H

#include <QDialog>
#include <QList>
#include <message.h>

namespace Ui {
class InformDialog;
}

class InformDialog : public QDialog
{
    Q_OBJECT
private slots:
    void GetInformInfo(QList<Message>* msglist);
    void on_inform_clear_clicked();

    void on_inform_close_clicked();

public:
    explicit InformDialog(QWidget *parent = 0);
    ~InformDialog();

private:
    Ui::InformDialog *ui;
};

#endif // INFORMDIALOG_H
