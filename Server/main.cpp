#include "mainwindow.h"
#include <QApplication>
#include <QSqlQuery>
#include <QDebug>
#include <logindialog.h>
#include <admin.h>
#include <utils.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("./database/TSData");
    if(!database.open()){
        qDebug()<<"failed to connect database";
        a.quit();
    }
    MainWindow w;
    QObject::connect(&w,SIGNAL(windowClosed()),&a,SLOT(quit()));
    w.show();
    Utils::suit_window(&w);
    LoginDialog d;
    Admin aw;
    if(d.exec()==QDialog::Accepted){
        aw.show();
        Utils::suit_window(&aw);
    }

    return a.exec();
}
