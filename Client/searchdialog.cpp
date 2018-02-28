#include "searchdialog.h"
#include "ui_searchdialog.h"
#include <QTableWidget>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QDebug>

SearchDialog::SearchDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchDialog)
{
    ui->setupUi(this);
    newlist=new QList<QString>();
}

SearchDialog::~SearchDialog()
{
    delete ui;
}

void SearchDialog::SearchCourseResponseOK(QList<Course> *list)
{
    //qDebug()<<list->size();
    QTableWidget *table=ui->course_result_table;
    //table->clear();
    table->setRowCount(list->size());
    Course c;
    QString tnames;
    for(int i=0;i<list->size();++i){
        c=list->at(i);
        table->setItem(i,0,new QTableWidgetItem(QString::number(c.cno)));
        table->setItem(i,1,new QTableWidgetItem(c.cname));
        tnames=c.tnamelist.first();
        for(int j=1;j<c.tnamelist.size();++j){
            tnames+=(","+c.tnamelist.at(j));
        }
        table->setItem(i,2,new QTableWidgetItem(tnames));
        table->setItem(i,3,new QTableWidgetItem(c.ctime));
    }
}

void SearchDialog::SearchCourseResponseFD()
{
    QMessageBox::about(this,"查找失败","没有找到符合查找内容的课程");
    return;
}

void SearchDialog::on_course_search_btn_clicked()
{
    QList<QString> *list=new QList<QString>();
    QString search=ui->course_search_edit->text();
    list->append(search);
    //if(search.length()==0) QMessageBox::about(this,"未填入搜索值","将显示所有可选的课程");
    emit SearchCourseRequest("SearchCourseRequest",list);
}

void SearchDialog::on_course_confirm_btn_clicked()
{
    emit SendNewCourseInfo(newlist);
    this->accept();
}

void SearchDialog::on_course_add_btn_clicked()
{
    int row=ui->course_result_table->currentRow();
    if(row<0){
        QMessageBox::about(this,"加入课程失败","请先选择要加入的课程");
        return;
    }

    QString cno=ui->course_result_table->item(row,0)->text();
    QString cname=ui->course_result_table->item(row,1)->text();
    str=cno+" "+cname;
    if(courselist->indexOf(str)!=-1 || newlist->indexOf(str)!=-1){
        QMessageBox::about(this,"加入课程失败","您已加入该课程");
        return;
    }

    QList<QString> *list=new QList<QString>();
    list->append(cno);
    emit AddCourseRequest("AddCourseRequest",list);
}

void SearchDialog::AddCourseResponseOK()
{
    QMessageBox::about(this,"提示","加入课程成功");
    newlist->append(str);
    return;
}

void SearchDialog::AddCourseResponseFD()
{
    QMessageBox::about(this,"加入课程失败","服务器出错了");
    return;
}

void SearchDialog::ReadStudentCourseInfo(QList<QString> *courselist)
{
    this->courselist=courselist;
}

void SearchDialog::closeEvent(QCloseEvent *event)
{
    emit SendNewCourseInfo(newlist);
    this->accept();
}
