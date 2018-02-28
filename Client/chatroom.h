#ifndef CHATROOM_H
#define CHATROOM_H

#include <QMainWindow>
#include <QTextCharFormat>
#include <QList>
#include <message.h>
namespace Ui {
class ChatRoom;
}

class ChatRoom : public QMainWindow
{
    Q_OBJECT
signals:
    void SendMessageRequest(QString,QList<QString>*);
public:
    explicit ChatRoom(QWidget *parent = 0);
    ~ChatRoom();

private slots:
    void on_font_size_combo_currentIndexChanged(const QString &arg1);

    void on_msg_erase_tbtn_clicked();

    void on_msg_send_btn_clicked();

    void on_font_color_tbtn_clicked();

    void on_font_bold_tbtn_clicked(bool checked);

    void on_font_italic_tbtn_clicked(bool checked);

    void on_font_underline_tbtn_clicked(bool checked);

    void on_font_name_combo_currentIndexChanged(const QString &arg1);

    void text_format_changed(const QTextCharFormat fmt);

    void SendMessageResponseOK(QString name,int cno,QString msg);

    void SendMessageResponseFD();

    void ReadWindowTitleInfo(QString sname, int cno, QString cname);

    void GetRecentMessageResponseOK(int cno, QList<Message> *msglist);
    void GetRecentMessageResponseFD();
private:
    int cno;
    QString name;
    Ui::ChatRoom *ui;
};

#endif // CHATROOM_H
