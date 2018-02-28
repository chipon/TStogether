/********************************************************************************
** Form generated from reading UI file 'studentcourse.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTCOURSE_H
#define UI_STUDENTCOURSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentCourse
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QScrollArea *courseware_area;
    QWidget *scrollAreaWidgetContents_6;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *courseware_layout;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLabel *course_cdept_label;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_8;
    QLabel *course_cmajor_label;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label;
    QLabel *course_name_label;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QListWidget *course_teacher_list;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_4;
    QTextEdit *course_notice_text;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_6;
    QTextEdit *course_intro_text;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *course_chat_btn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *StudentCourse)
    {
        if (StudentCourse->objectName().isEmpty())
            StudentCourse->setObjectName(QStringLiteral("StudentCourse"));
        StudentCourse->resize(800, 600);
        centralwidget = new QWidget(StudentCourse);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(500, 40, 181, 381));
        verticalLayout_7 = new QVBoxLayout(layoutWidget);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_7->addWidget(label_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        courseware_area = new QScrollArea(layoutWidget);
        courseware_area->setObjectName(QStringLiteral("courseware_area"));
        courseware_area->setWidgetResizable(true);
        scrollAreaWidgetContents_6 = new QWidget();
        scrollAreaWidgetContents_6->setObjectName(QStringLiteral("scrollAreaWidgetContents_6"));
        scrollAreaWidgetContents_6->setGeometry(QRect(0, 0, 175, 351));
        verticalLayoutWidget = new QWidget(scrollAreaWidgetContents_6);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 181, 351));
        courseware_layout = new QVBoxLayout(verticalLayoutWidget);
        courseware_layout->setObjectName(QStringLiteral("courseware_layout"));
        courseware_layout->setContentsMargins(0, 0, 0, 0);
        courseware_area->setWidget(scrollAreaWidgetContents_6);

        horizontalLayout->addWidget(courseware_area);


        verticalLayout_7->addLayout(horizontalLayout);

        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(60, 30, 391, 391));
        verticalLayout_6 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_5 = new QLabel(layoutWidget_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);

        course_cdept_label = new QLabel(layoutWidget_2);
        course_cdept_label->setObjectName(QStringLiteral("course_cdept_label"));

        horizontalLayout_2->addWidget(course_cdept_label);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_8 = new QLabel(layoutWidget_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_6->addWidget(label_8);

        course_cmajor_label = new QLabel(layoutWidget_2);
        course_cmajor_label->setObjectName(QStringLiteral("course_cmajor_label"));

        horizontalLayout_6->addWidget(course_cmajor_label);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label = new QLabel(layoutWidget_2);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_7->addWidget(label);

        course_name_label = new QLabel(layoutWidget_2);
        course_name_label->setObjectName(QStringLiteral("course_name_label"));

        horizontalLayout_7->addWidget(course_name_label);


        verticalLayout_4->addLayout(horizontalLayout_7);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(layoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        course_teacher_list = new QListWidget(layoutWidget_2);
        course_teacher_list->setObjectName(QStringLiteral("course_teacher_list"));

        verticalLayout->addWidget(course_teacher_list);


        verticalLayout_4->addLayout(verticalLayout);


        formLayout->setLayout(0, QFormLayout::FieldRole, verticalLayout_4);


        horizontalLayout_5->addLayout(formLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_4 = new QLabel(layoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_3->addWidget(label_4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        course_notice_text = new QTextEdit(layoutWidget_2);
        course_notice_text->setObjectName(QStringLiteral("course_notice_text"));
        course_notice_text->setReadOnly(true);

        horizontalLayout_4->addWidget(course_notice_text);


        verticalLayout_3->addLayout(horizontalLayout_4);


        horizontalLayout_5->addLayout(verticalLayout_3);


        verticalLayout_6->addLayout(horizontalLayout_5);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_6 = new QLabel(layoutWidget_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_2->addWidget(label_6);

        course_intro_text = new QTextEdit(layoutWidget_2);
        course_intro_text->setObjectName(QStringLiteral("course_intro_text"));
        course_intro_text->setEnabled(true);
        course_intro_text->setReadOnly(true);

        verticalLayout_2->addWidget(course_intro_text);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));

        verticalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout_6->addLayout(verticalLayout_2);

        course_chat_btn = new QToolButton(centralwidget);
        course_chat_btn->setObjectName(QStringLiteral("course_chat_btn"));
        course_chat_btn->setGeometry(QRect(650, 10, 24, 25));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/people.png"), QSize(), QIcon::Normal, QIcon::Off);
        course_chat_btn->setIcon(icon);
        StudentCourse->setCentralWidget(centralwidget);
        layoutWidget->raise();
        layoutWidget_2->raise();
        course_chat_btn->raise();
        course_cdept_label->raise();
        label_5->raise();
        course_cmajor_label->raise();
        label_8->raise();
        course_cmajor_label->raise();
        label_8->raise();
        course_name_label->raise();
        label->raise();
        course_teacher_list->raise();
        label_2->raise();
        menubar = new QMenuBar(StudentCourse);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        StudentCourse->setMenuBar(menubar);
        statusbar = new QStatusBar(StudentCourse);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        StudentCourse->setStatusBar(statusbar);

        retranslateUi(StudentCourse);

        QMetaObject::connectSlotsByName(StudentCourse);
    } // setupUi

    void retranslateUi(QMainWindow *StudentCourse)
    {
        StudentCourse->setWindowTitle(QApplication::translate("StudentCourse", "MainWindow", 0));
        label_3->setText(QApplication::translate("StudentCourse", "\350\257\276\344\273\266", 0));
        label_5->setText(QApplication::translate("StudentCourse", "\351\231\242\347\263\273", 0));
        course_cdept_label->setText(QString());
        label_8->setText(QApplication::translate("StudentCourse", "\344\270\223\344\270\232", 0));
        course_cmajor_label->setText(QString());
        label->setText(QApplication::translate("StudentCourse", "\350\257\276\347\250\213\345\220\215", 0));
        course_name_label->setText(QString());
        label_2->setText(QApplication::translate("StudentCourse", "\345\274\200\350\257\276\346\225\231\345\270\210", 0));
        label_4->setText(QApplication::translate("StudentCourse", "\350\257\276\347\250\213\345\205\254\345\221\212", 0));
        label_6->setText(QApplication::translate("StudentCourse", "\350\257\276\347\250\213\347\256\200\344\273\213", 0));
        course_chat_btn->setText(QApplication::translate("StudentCourse", "...", 0));
    } // retranslateUi

};

namespace Ui {
    class StudentCourse: public Ui_StudentCourse {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTCOURSE_H
