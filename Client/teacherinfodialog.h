#ifndef TEACHERINFODIALOG_H
#define TEACHERINFODIALOG_H

#include <QDialog>
#include <teacher.h>
#include <QList>

namespace Ui {
class TeacherInfoDialog;
}

class TeacherInfoDialog : public QDialog
{
    Q_OBJECT
signals:
    void UpdateTeacherInfo(QList<QString>*);
    void UpdateTeacherInfo(QString,QList<QString>*);
public:
    explicit TeacherInfoDialog(QWidget *parent = 0);
    ~TeacherInfoDialog();

private slots:
    void UpdateTeacherInfoFailed();

    void UpdateTeacherInfoOK();

    void ReceiveTeacherInfo(Teacher *t);

    void on_teacher_confirm_btn_clicked();

    void on_teacher_modify_btn_clicked();

private:
    Teacher *t;
    QList<QString> *list;
    Ui::TeacherInfoDialog *ui;
};

#endif // TEACHERINFODIALOG_H
