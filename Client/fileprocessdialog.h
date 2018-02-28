#ifndef FILEPROCESSDIALOG_H
#define FILEPROCESSDIALOG_H

#include <QDialog>
#define RATE 10
namespace Ui {
class FileProcessDialog;
}

class FileProcessDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FileProcessDialog(QWidget *parent = 0);
    ~FileProcessDialog();
    void setMaxValue(qint64 max);
    void updateValue(qint64 value);
private:
    Ui::FileProcessDialog *ui;
};

#endif // FILEPROCESSDIALOG_H
