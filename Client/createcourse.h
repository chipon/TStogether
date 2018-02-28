#ifndef CREATECOURSE_H
#define CREATECOURSE_H

#include <QDialog>
#include <course.h>
#include <dept.h>
#include <QList>

namespace Ui {
class CreateCourse;
}

class CreateCourse : public QDialog
{
    Q_OBJECT
signals:
    void GetDeptInfo(QString);
    void CreateCourseRequest(QString,QList<QString>*);
    void FindTeacherByTnoRequest(QString,QList<QString>*);
    void SendCourseInfo(QString);

public:
    explicit CreateCourse(QWidget *parent = 0);
    ~CreateCourse();
    void updateUser(int tno);
    void updateMajor();

    QString cname;
    int cteacher,cdept,cmajor;
    QString cintro;

private slots:
    void GetDeptInfoFailed();

    void GetDeptInfoOK(QList<Dept> *list);

    void FindTeacherByTnoResponseOK(QString tname);

    void FindTeacherByTnoResponseFD();

    void on_course_create_btn_clicked();

    void on_course_cancel_btn_clicked();

    void on_course_cdept_combo_currentIndexChanged(const QString &arg1);

    void on_course_add_teacher_btn_clicked();

    void CreateCourseResponseOK(int cno);

    void CreateCourseResponseFD();

private:
    Course *c;
    int tno,tmptno;
    QList<Dept> *list;
    Ui::CreateCourse *ui;
};

#endif // CREATECOURSE_H
