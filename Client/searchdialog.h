#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>
#include <QList>
#include <course.h>
#include <QCloseEvent>

namespace Ui {
class SearchDialog;
}

class SearchDialog : public QDialog
{
    Q_OBJECT
signals:
    void SearchCourseRequest(QString,QList<QString>*);
    void AddCourseRequest(QString,QList<QString>*);
    void SendNewCourseInfo(QList<QString>*);
public:
    explicit SearchDialog(QWidget *parent = 0);
    ~SearchDialog();
private slots:
    void SearchCourseResponseOK(QList<Course> *list);
    void SearchCourseResponseFD();
    void on_course_search_btn_clicked();

    void on_course_confirm_btn_clicked();

    void on_course_add_btn_clicked();

    void AddCourseResponseOK();

    void AddCourseResponseFD();

    void ReadStudentCourseInfo(QList<QString>* courselist);

private:
    QString str;
    QList<QString> *newlist;
    QList<QString> *courselist;
    Ui::SearchDialog *ui;
protected:
    void closeEvent(QCloseEvent *event);
};

#endif // SEARCHDIALOG_H
