/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton_3;
    QToolButton *student_info_tbtn;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_6;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *create_course_btn_3;
    QPushButton *delete_course_btn_3;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QListWidget *course_list;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_7;
    QListWidget *listWidget_2;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *nickname_label;
    QTextBrowser *signature_browser;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout;
    QLineEdit *course_search_edit;
    QPushButton *course_search_btn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(743, 530);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(750, 130, 51, 26));
        student_info_tbtn = new QToolButton(centralWidget);
        student_info_tbtn->setObjectName(QStringLiteral("student_info_tbtn"));
        student_info_tbtn->setGeometry(QRect(610, 20, 24, 25));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/user.ico"), QSize(), QIcon::Normal, QIcon::Off);
        student_info_tbtn->setIcon(icon);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 100, 181, 291));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_2->addWidget(label_6);

        textBrowser = new QTextBrowser(layoutWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout_2->addWidget(textBrowser);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        create_course_btn_3 = new QPushButton(layoutWidget);
        create_course_btn_3->setObjectName(QStringLiteral("create_course_btn_3"));

        horizontalLayout_6->addWidget(create_course_btn_3);

        delete_course_btn_3 = new QPushButton(layoutWidget);
        delete_course_btn_3->setObjectName(QStringLiteral("delete_course_btn_3"));

        horizontalLayout_6->addWidget(delete_course_btn_3);


        verticalLayout_2->addLayout(horizontalLayout_6);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(260, 100, 181, 291));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_3->addWidget(label_5);

        course_list = new QListWidget(layoutWidget1);
        course_list->setObjectName(QStringLiteral("course_list"));

        verticalLayout_3->addWidget(course_list);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(480, 100, 161, 291));
        verticalLayout_4 = new QVBoxLayout(layoutWidget2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget2);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_4->addWidget(label_7);

        listWidget_2 = new QListWidget(layoutWidget2);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));

        verticalLayout_4->addWidget(listWidget_2);

        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(50, 10, 181, 81));
        verticalLayout = new QVBoxLayout(layoutWidget3);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(layoutWidget3);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        nickname_label = new QLabel(layoutWidget3);
        nickname_label->setObjectName(QStringLiteral("nickname_label"));

        horizontalLayout_2->addWidget(nickname_label);


        verticalLayout->addLayout(horizontalLayout_2);

        signature_browser = new QTextBrowser(layoutWidget3);
        signature_browser->setObjectName(QStringLiteral("signature_browser"));

        verticalLayout->addWidget(signature_browser);

        layoutWidget4 = new QWidget(centralWidget);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(340, 30, 211, 28));
        horizontalLayout = new QHBoxLayout(layoutWidget4);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        course_search_edit = new QLineEdit(layoutWidget4);
        course_search_edit->setObjectName(QStringLiteral("course_search_edit"));

        horizontalLayout->addWidget(course_search_edit);

        course_search_btn = new QPushButton(layoutWidget4);
        course_search_btn->setObjectName(QStringLiteral("course_search_btn"));

        horizontalLayout->addWidget(course_search_btn);

        MainWindow->setCentralWidget(centralWidget);
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        pushButton_3->raise();
        student_info_tbtn->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 743, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "\346\220\234\347\264\242", 0));
        student_info_tbtn->setText(QApplication::translate("MainWindow", "...", 0));
        label_6->setText(QApplication::translate("MainWindow", "\346\266\210\346\201\257\345\210\227\350\241\250", 0));
        create_course_btn_3->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272", 0));
        delete_course_btn_3->setText(QApplication::translate("MainWindow", "\345\210\267\346\226\260", 0));
        label_5->setText(QApplication::translate("MainWindow", "\346\210\221\347\232\204\350\257\276\347\250\213", 0));
        label_7->setText(QApplication::translate("MainWindow", "\346\210\221\347\232\204\345\245\275\345\217\213", 0));
        label->setText(QApplication::translate("MainWindow", "\346\254\242\350\277\216\345\233\236\346\235\245", 0));
        nickname_label->setText(QString());
        course_search_btn->setText(QApplication::translate("MainWindow", "\346\220\234\347\264\242\350\257\276\347\250\213", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
