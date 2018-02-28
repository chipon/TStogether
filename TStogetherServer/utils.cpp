#include "utils.h"
#include <QCryptographicHash>
#include <QDataStream>

Utils::Utils()
{

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


void Utils::sendMessage(QTcpSocket *tcp, QString msg)
{
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_7);
    out<<msg;
    tcp->write(block);
}

void Utils::suit_window(QMainWindow *mw)
{
    QDesktopWidget * desktop=QApplication::desktop();
    mw->move((desktop->width()-mw->width())/2,(desktop->height()-mw->height())/2);
}

void Utils::sleep(double sec)
{
    QTime t;
    t.start();
    while(t.elapsed()<1000*sec)
        QCoreApplication::processEvents();
}
