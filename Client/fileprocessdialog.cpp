#include "fileprocessdialog.h"
#include "ui_fileprocessdialog.h"

FileProcessDialog::FileProcessDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FileProcessDialog)
{
    ui->setupUi(this);
}

FileProcessDialog::~FileProcessDialog()
{
    delete ui;
}

void FileProcessDialog::setMaxValue(qint64 max)
{
    ui->file_processbar->setMaximum((int)(max/RATE));
    ui->file_processbar->setValue(0);
}

void FileProcessDialog::updateValue(qint64 value)
{
    ui->file_processbar->setValue((int)(value/RATE));
}
