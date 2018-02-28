#ifndef UTILS_H
#define UTILS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QtNetwork>
#include <QMessageBox>
#include <QMainWindow>
#include <QDesktopWidget>
#include <QApplication>

class Utils
{
public:
    Utils();
    static void sleep(double sec);
    static int dname_to_deptno(QString dname);
    static int mname_to_majorno(QString mname);
    static QString getMd5(QString s);
    static void suit_window(QMainWindow *mw);
};

#endif // UTILS_H
