#include "utils.h"
#include <QCryptographicHash>
#include <QCoreApplication>
#include <QTime>
Utils::Utils()
{

}

void Utils::sleep(double sec)
{
    QTime t;
    t.start();
    while(t.elapsed()<1000*sec)
        QCoreApplication::processEvents();
}

QString Utils::getMd5(QString s)
{
    QString md5;
    QByteArray ba,bb;
    QCryptographicHash md(QCryptographicHash::Md5);
    ba.append(s);
    md.addData(ba);
    bb = md.result();
    md5.append(bb.toHex());
    return md5;
}

void Utils::suit_window(QMainWindow *mw)
{
    QDesktopWidget * desktop=QApplication::desktop();
    mw->move((desktop->width()-mw->width())/2,(desktop->height()-mw->height())/2);
}

