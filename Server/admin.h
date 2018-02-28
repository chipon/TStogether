#ifndef ADMIN_H
#define ADMIN_H

#include <QMainWindow>
#include <QSqlQuery>
#include <QtNetwork>
#include <QListWidget>
#include <QList>
#include <QMap>

namespace Ui {
class Admin;
}

class Admin : public QMainWindow
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = 0);
    QString deptno_to_dname(int dno);
    void update_teacher_list();
    void update_student_list();
    ~Admin();

private slots:
    void on_add_dept_clicked();

    void on_del_dept_clicked();

    void on_depts_itemSelectionChanged();

    void on_depts_itemDoubleClicked(QListWidgetItem *item);

    void on_majors_itemDoubleClicked(QListWidgetItem *item);

    void on_add_major_clicked();

    void on_del_major_clicked();

    void on_majors_itemSelectionChanged();

    void on_teacher_depts_combo_currentIndexChanged(const QString &arg1);

    void on_teacher_show_list_itemSelectionChanged();

    void on_teacher_modify_btn_clicked();

    void on_teacher_add_btn_clicked();

    void on_teacher_delete_btn_clicked();

    void on_teacher_search_btn_clicked();

    void on_student_add_btn_clicked();

    void on_student_modify_btn_clicked();

    void on_student_delete_btn_clicked();

    void on_student_depts_show_combo_currentIndexChanged(const QString &arg1);

    void on_student_majors_show_combo_currentIndexChanged(const QString &arg1);

    void on_student_show_list_itemSelectionChanged();

    void on_student_sdept_show_combo_currentIndexChanged(const QString &arg1);

    void on_student_search_btn_clicked();

private:
    Ui::Admin *ui;
    QSqlQuery query;
    QTcpSocket *socket;
    int currentDeptNo;
    QListWidgetItem *deptitem,*majoritem;
};

#endif // ADMIN_H
