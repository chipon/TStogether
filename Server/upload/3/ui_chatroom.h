/********************************************************************************
** Form generated from reading UI file 'chatroom.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATROOM_H
#define UI_CHATROOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatRoom
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QTextBrowser *msg_browser;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QListWidget *student_list;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QFontComboBox *font_name_combo;
    QComboBox *font_size_combo;
    QToolButton *font_bold_tbtn;
    QToolButton *font_italic_tbtn;
    QToolButton *font_underline_tbtn;
    QToolButton *font_color_tbtn;
    QToolButton *msg_erase_tbtn;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *msg_text;
    QPushButton *msg_send_btn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ChatRoom)
    {
        if (ChatRoom->objectName().isEmpty())
            ChatRoom->setObjectName(QStringLiteral("ChatRoom"));
        ChatRoom->resize(800, 600);
        centralwidget = new QWidget(ChatRoom);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 20, 381, 261));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        msg_browser = new QTextBrowser(layoutWidget);
        msg_browser->setObjectName(QStringLiteral("msg_browser"));

        verticalLayout_2->addWidget(msg_browser);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(530, 20, 151, 401));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_3->addWidget(label);

        student_list = new QListWidget(layoutWidget1);
        student_list->setObjectName(QStringLiteral("student_list"));

        verticalLayout_3->addWidget(student_list);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(60, 320, 440, 108));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        font_name_combo = new QFontComboBox(layoutWidget2);
        font_name_combo->setObjectName(QStringLiteral("font_name_combo"));

        horizontalLayout->addWidget(font_name_combo);

        font_size_combo = new QComboBox(layoutWidget2);
        font_size_combo->setObjectName(QStringLiteral("font_size_combo"));

        horizontalLayout->addWidget(font_size_combo);

        font_bold_tbtn = new QToolButton(layoutWidget2);
        font_bold_tbtn->setObjectName(QStringLiteral("font_bold_tbtn"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/bold.png"), QSize(), QIcon::Normal, QIcon::Off);
        font_bold_tbtn->setIcon(icon);
        font_bold_tbtn->setCheckable(true);

        horizontalLayout->addWidget(font_bold_tbtn);

        font_italic_tbtn = new QToolButton(layoutWidget2);
        font_italic_tbtn->setObjectName(QStringLiteral("font_italic_tbtn"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/italic .png"), QSize(), QIcon::Normal, QIcon::Off);
        font_italic_tbtn->setIcon(icon1);
        font_italic_tbtn->setCheckable(true);

        horizontalLayout->addWidget(font_italic_tbtn);

        font_underline_tbtn = new QToolButton(layoutWidget2);
        font_underline_tbtn->setObjectName(QStringLiteral("font_underline_tbtn"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/underline.png"), QSize(), QIcon::Normal, QIcon::Off);
        font_underline_tbtn->setIcon(icon2);
        font_underline_tbtn->setCheckable(true);

        horizontalLayout->addWidget(font_underline_tbtn);

        font_color_tbtn = new QToolButton(layoutWidget2);
        font_color_tbtn->setObjectName(QStringLiteral("font_color_tbtn"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/font_ color.png"), QSize(), QIcon::Normal, QIcon::Off);
        font_color_tbtn->setIcon(icon3);

        horizontalLayout->addWidget(font_color_tbtn);

        msg_erase_tbtn = new QToolButton(layoutWidget2);
        msg_erase_tbtn->setObjectName(QStringLiteral("msg_erase_tbtn"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        msg_erase_tbtn->setIcon(icon4);

        horizontalLayout->addWidget(msg_erase_tbtn);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        msg_text = new QTextEdit(layoutWidget2);
        msg_text->setObjectName(QStringLiteral("msg_text"));

        horizontalLayout_2->addWidget(msg_text);

        msg_send_btn = new QPushButton(layoutWidget2);
        msg_send_btn->setObjectName(QStringLiteral("msg_send_btn"));

        horizontalLayout_2->addWidget(msg_send_btn);


        verticalLayout->addLayout(horizontalLayout_2);

        ChatRoom->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ChatRoom);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        ChatRoom->setMenuBar(menubar);
        statusbar = new QStatusBar(ChatRoom);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        ChatRoom->setStatusBar(statusbar);

        retranslateUi(ChatRoom);

        font_size_combo->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(ChatRoom);
    } // setupUi

    void retranslateUi(QMainWindow *ChatRoom)
    {
        ChatRoom->setWindowTitle(QApplication::translate("ChatRoom", "MainWindow", 0));
        label_2->setText(QApplication::translate("ChatRoom", "\346\266\210\346\201\257\345\210\227\350\241\250", 0));
        label->setText(QApplication::translate("ChatRoom", "\350\257\276\347\250\213\346\210\220\345\221\230", 0));
        font_size_combo->clear();
        font_size_combo->insertItems(0, QStringList()
         << QApplication::translate("ChatRoom", "8", 0)
         << QApplication::translate("ChatRoom", "10", 0)
         << QApplication::translate("ChatRoom", "12", 0)
         << QApplication::translate("ChatRoom", "14", 0)
         << QApplication::translate("ChatRoom", "16", 0)
         << QApplication::translate("ChatRoom", "18", 0)
         << QApplication::translate("ChatRoom", "20", 0)
         << QApplication::translate("ChatRoom", "22", 0)
         << QApplication::translate("ChatRoom", "24", 0)
        );
        font_bold_tbtn->setText(QApplication::translate("ChatRoom", "...", 0));
        font_italic_tbtn->setText(QApplication::translate("ChatRoom", "...", 0));
        font_underline_tbtn->setText(QApplication::translate("ChatRoom", "...", 0));
        font_color_tbtn->setText(QApplication::translate("ChatRoom", "...", 0));
        msg_erase_tbtn->setText(QApplication::translate("ChatRoom", "...", 0));
        msg_send_btn->setText(QApplication::translate("ChatRoom", "\345\217\221\351\200\201", 0));
    } // retranslateUi

};

namespace Ui {
    class ChatRoom: public Ui_ChatRoom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATROOM_H
