#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QCheckBox>
#include <QDateTime>
#include <QMessageBox>
#include "person.h"
#include "login.h"
Widget::Widget(QWidget *parent,QString so) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
   //qDebug()<<so;
    this->ssno=so;
    dataToTable("select * from sqt");
    displayclass();
    displaysno();
    connect(ui->tableWidget,QTableWidget::cellDoubleClicked,[=](int r, int c){
        Person *p=new Person();
        p->show();
        p->init(ui->tableWidget->item(r,0)->text(),ui->tableWidget->item(r,1)->text());

    });
}


 void Widget::displaysno()
 {
     connect(ui->pushButton,QPushButton::clicked,[=](){
         if(ui->lineEdit->text().isEmpty())
         {
             QMessageBox::warning(this,"warning","输入为空");
         }
         else
         {
              dataToTable(QString("select * from sqt where sno like '%1'").arg(ui->lineEdit->text()));
         }
     });
 }


 void Widget::displayclass()
 {
     QSqlQuery q4;
     q4.exec("select distinct sclass from sqt");
     ui->comboBox->addItem("全部班级");
     while(q4.next())
     {
          ui->comboBox->addItem(q4.value(0).toString());
     }
     connect(ui->comboBox,QComboBox::currentTextChanged,[=](QString s){
         if(s=="全部班级")
         {
             dataToTable("select * from student");
         }
         else
         {
             dataToTable(QString("select * from sqt where sclass='%1'").arg(s));
         }
     });
 }
void Widget::dataToTable(QString sql)
{
    QSqlQuery q;
    if(q.exec(sql))
    {
        int i=0;
        ui->tableWidget->setRowCount(q.size());
        while(q.next())
        {
                QCheckBox *c =new QCheckBox("未签到");
                QString sno=q.value(0).toString();
                QSqlQuery q2;
                          q2.exec(QString("select logtime from loqt where sno=%1 and date(logtime)=curdate() order by logtime desc").arg(sno));
                          q2.next();

                          if(sno!=this->ssno)
                          {
                              c->setDisabled(true);
                          }
                          if(q2.size())
                          {
                              c->setText("已签到");
                              c->setDisabled(true);
                              c->setChecked(true);
                              ui->tableWidget->setItem(i,4,new QTableWidgetItem(q2.value(0).toString()));
                          }
                ui->tableWidget->setItem(i,0,new QTableWidgetItem(sno));
                ui->tableWidget->setItem(i,1,new QTableWidgetItem(q.value(1).toString()));
                ui->tableWidget->setItem(i,2,new QTableWidgetItem(q.value(2).toString()));
                ui->tableWidget->setCellWidget(i,3,c);
                connect(c,QCheckBox::clicked,[=](){
                c->setText("已签到");
                c->setDisabled(true);
                ui->tableWidget->setItem(i,4,new QTableWidgetItem(QDateTime::currentDateTime().toString()));
                QSqlQuery q1;
                q1.exec(QString("insert into loqt values(%1,now())").arg(sno));
            });
            i++;
        }
    }
}
Widget::~Widget()
{
    delete ui;
}
