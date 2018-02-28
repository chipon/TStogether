#ifndef STUDENTINFODIALOG_H
#define STUDENTINFODIALOG_H

#include <QDialog>
#include <student.h>
#include <QList>

namespace Ui {
class StudentInfoDialog;
}

class StudentInfoDialog : public QDialog
{
    Q_OBJECT
signals:
    void UpdateStudentInfo(QList<QString> *);
    void UpdateStudentInfo(QString,QList<QString> *);
public:
    explicit StudentInfoDialog(QWidget *parent = 0);
    ~StudentInfoDialog();

private slots:
    void UpdateStudentInfoOK();

    void UpdateStudentInfoFailed();

    void receiveStudentInfo(Student *stu);

    void on_student_confirm_btn_clicked();

    void on_student_modify_btn_clicked();

private:
    Student * stu;
    QList<QString> *list;
    Ui::StudentInfoDialog *ui;
};

#endif // STUDENTINFODIALOG_H
