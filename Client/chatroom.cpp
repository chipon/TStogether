#include "chatroom.h"
#include "ui_chatroom.h"
#include <QColorDialog>
#include <QColor>
#include <QDebug>
#include <QDateTime>
#include <QMessageBox>
#include <QScrollBar>

ChatRoom::ChatRoom(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChatRoom)
{
    ui->setupUi(this);
    ui->msg_text->setFontPointSize(12);
    ui->msg_text->setFocus();
    ui->msg_browser->setAlignment(Qt::AlignRight);
    connect(ui->msg_text,SIGNAL(currentCharFormatChanged(QTextCharFormat)),this,SLOT(text_format_changed(QTextCharFormat)));
}

ChatRoom::~ChatRoom()
{
    delete ui;
}

void ChatRoom::on_font_size_combo_currentIndexChanged(const QString &arg1)
{
    int size=arg1.toInt();
    qDebug()<<"size"<<size;
    ui->msg_text->setFontPointSize(size);
    ui->msg_text->setFocus();
}

void ChatRoom::on_msg_erase_tbtn_clicked()
{
    ui->msg_text->clear();
    ui->msg_text->setFocus();
}

void ChatRoom::on_msg_send_btn_clicked()
{
    if(!ui->msg_text->toPlainText().size()){
        QMessageBox::about(this,"发送消息失败","消息不能为空!");
        return;
    }
    QString msg=ui->msg_text->toHtml();
    QList<QString> *list=new QList<QString>();
    list->append(msg);
    emit SendMessageRequest("SendMessageRequest",list);
}

void ChatRoom::on_font_color_tbtn_clicked()
{
    QColor color = QColorDialog::getColor(Qt::black,this);
    //qDebug()<<color;
    if(color.isValid()) ui->msg_text->setTextColor(color);
    ui->msg_text->setFocus();
}

void ChatRoom::on_font_bold_tbtn_clicked(bool checked)
{
    if(checked) ui->msg_text->setFontWeight(QFont::Bold);
    else ui->msg_text->setFontWeight(QFont::Normal);
    ui->msg_text->setFocus();
}

void ChatRoom::on_font_italic_tbtn_clicked(bool checked)
{
    ui->msg_text->setFontItalic(checked);
    ui->msg_text->setFocus();
}

void ChatRoom::on_font_underline_tbtn_clicked(bool checked)
{
    ui->msg_text->setFontUnderline(checked);
    ui->msg_text->setFocus();
}


void ChatRoom::on_font_name_combo_currentIndexChanged(const QString &arg1)
{
    ui->msg_text->setFontFamily(arg1);
    ui->msg_text->setFocus();
}

void ChatRoom::text_format_changed(const QTextCharFormat fmt)
{
    ui->msg_text->setCurrentCharFormat(fmt);
    ui->font_name_combo->setCurrentFont(fmt.font());
    ui->font_bold_tbtn->setChecked(fmt.fontWeight()==QFont::Bold);
    ui->font_italic_tbtn->setChecked(fmt.fontItalic());
    ui->font_size_combo->setCurrentText(QString::number((int)(fmt.fontPointSize())));
}

void ChatRoom::SendMessageResponseOK(QString name,int cno,QString msg)
{
    if(cno!=this->cno) return;
    //qDebug()<<cno;
    ui->msg_browser->setTextColor(Qt::cyan);
    ui->msg_browser->setCurrentFont(QFont("Noto Sans CJK SC",10));
    if(name==this->name && cno==this->cno)
        ui->msg_browser->setAlignment(Qt::AlignRight);
    else
        ui->msg_browser->setAlignment(Qt::AlignLeft);
    ui->msg_browser->append(name+" "+QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));

//    if(name==this->name && cno==this->cno)
//        ui->msg_browser->setAlignment(Qt::AlignRight);
//    else
//        ui->msg_browser->setAlignment(Qt::AlignLeft);
    ui->msg_browser->append(msg);
    ui->msg_browser->append("");
    ui->msg_browser->verticalScrollBar()->setValue(ui->msg_browser->verticalScrollBar()->maximum());
    ui->msg_text->clear();
    ui->msg_text->setFocus();
}

void ChatRoom::SendMessageResponseFD()
{
    QMessageBox::about(this,"服务器出错了","发送消息失败");
    return;
}

void ChatRoom::ReadWindowTitleInfo(QString sname, int cno, QString cname)
{
    name=sname;
    this->cno=cno;
    this->setWindowTitle(sname+"在课程"+cname+"的聊天室");
}

void ChatRoom::GetRecentMessageResponseOK(int cno, QList<Message> *msglist)
{
    if(cno!=this->cno) return;
    foreach (Message m, *msglist) {
        ui->msg_browser->setTextColor(Qt::gray);
        ui->msg_browser->setCurrentFont(QFont("Noto Sans CJK SC",10));
        if(m.name==this->name && cno==this->cno)
            ui->msg_browser->setAlignment(Qt::AlignRight);
        else
            ui->msg_browser->setAlignment(Qt::AlignLeft);
        ui->msg_browser->append(m.name+" "+m.time);

        ui->msg_browser->append(m.msg);
        ui->msg_browser->append("");
    }

    ui->msg_browser->verticalScrollBar()->setValue(ui->msg_browser->verticalScrollBar()->maximum());
    ui->msg_text->setFocus();
}

void ChatRoom::GetRecentMessageResponseFD()
{
    QMessageBox::about(this,"服务器出错了","获取历史消息失败");
    return;
}

