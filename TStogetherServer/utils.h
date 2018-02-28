#ifndef UTILS_H
#define UTILS_H
#include <QString>
#include <QTcpSocket>
#include <QMainWindow>
#include <QDesktopWidget>
#include <QApplication>
#include <QTime>

class Utils
{
public:
    Utils();
    static QString getMd5(QString s);
    static void sendMessage(QTcpSocket *tcp, QString msg);
    static void suit_window(QMainWindow *mw);
    static void sleep(double sec);
};

#endif // UTILS_H
