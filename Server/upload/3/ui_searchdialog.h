/********************************************************************************
** Form generated from reading UI file 'searchdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHDIALOG_H
#define UI_SEARCHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchDialog
{
public:
    QLineEdit *course_search_edit;
    QPushButton *course_search_btn;
    QPushButton *course_add_btn;
    QLabel *label;
    QTableWidget *course_result_table;
    QPushButton *course_confirm_btn;

    void setupUi(QDialog *SearchDialog)
    {
        if (SearchDialog->objectName().isEmpty())
            SearchDialog->setObjectName(QStringLiteral("SearchDialog"));
        SearchDialog->resize(459, 361);
        course_search_edit = new QLineEdit(SearchDialog);
        course_search_edit->setObjectName(QStringLiteral("course_search_edit"));
        course_search_edit->setGeometry(QRect(192, 30, 121, 26));
        course_search_btn = new QPushButton(SearchDialog);
        course_search_btn->setObjectName(QStringLiteral("course_search_btn"));
        course_search_btn->setGeometry(QRect(350, 30, 51, 26));
        course_add_btn = new QPushButton(SearchDialog);
        course_add_btn->setObjectName(QStringLiteral("course_add_btn"));
        course_add_btn->setGeometry(QRect(140, 320, 80, 26));
        label = new QLabel(SearchDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 30, 91, 21));
        course_result_table = new QTableWidget(SearchDialog);
        if (course_result_table->columnCount() < 4)
            course_result_table->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        course_result_table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        course_result_table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        course_result_table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        course_result_table->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        course_result_table->setObjectName(QStringLiteral("course_result_table"));
        course_result_table->setGeometry(QRect(20, 70, 411, 221));
        course_confirm_btn = new QPushButton(SearchDialog);
        course_confirm_btn->setObjectName(QStringLiteral("course_confirm_btn"));
        course_confirm_btn->setGeometry(QRect(260, 320, 80, 26));

        retranslateUi(SearchDialog);

        QMetaObject::connectSlotsByName(SearchDialog);
    } // setupUi

    void retranslateUi(QDialog *SearchDialog)
    {
        SearchDialog->setWindowTitle(QApplication::translate("SearchDialog", "Dialog", 0));
        course_search_btn->setText(QApplication::translate("SearchDialog", "\346\220\234\347\264\242", 0));
        course_add_btn->setText(QApplication::translate("SearchDialog", "\345\212\240\345\205\245\350\257\276\347\250\213", 0));
        label->setText(QApplication::translate("SearchDialog", "\346\220\234\347\264\242\350\257\276\347\250\213/\346\225\231\345\270\210:", 0));
        QTableWidgetItem *___qtablewidgetitem = course_result_table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("SearchDialog", "\350\257\276\347\250\213\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem1 = course_result_table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("SearchDialog", "\350\257\276\347\250\213\345\220\215", 0));
        QTableWidgetItem *___qtablewidgetitem2 = course_result_table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("SearchDialog", "\345\274\200\350\257\276\346\225\231\345\270\210", 0));
        QTableWidgetItem *___qtablewidgetitem3 = course_result_table->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("SearchDialog", "\345\274\200\350\257\276\346\227\266\351\227\264", 0));
        course_confirm_btn->setText(QApplication::translate("SearchDialog", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class SearchDialog: public Ui_SearchDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHDIALOG_H
