#include "showuserdialog.h"
#include "ui_showuserdialog.h"

ShowUserDialog::ShowUserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowUserDialog)
{
    ui->setupUi(this);
}

ShowUserDialog::~ShowUserDialog()
{
    delete ui;
}
