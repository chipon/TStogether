#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
signals:
    void windowClosed();
    void SendMessageResponse(bool,int,int,QString,QString);
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void newClientConnect();
    void SendMessageRequest(bool user, int uno, int cno, QString name, QString msg);
private:
    QTcpServer *server;
    Ui::MainWindow *ui;
    void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H
