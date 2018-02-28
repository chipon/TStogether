#ifndef SHOWUSERDIALOG_H
#define SHOWUSERDIALOG_H

#include <QDialog>

namespace Ui {
class ShowUserDialog;
}

class ShowUserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ShowUserDialog(QWidget *parent = 0);
    ~ShowUserDialog();

private:
    Ui::ShowUserDialog *ui;
};

#endif // SHOWUSERDIALOG_H
