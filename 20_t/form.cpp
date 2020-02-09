#include "form.h"
#include "ui_form.h"
#include<QPushButton>
#include<QMessageBox>
#include<QSqlQuery>
#include<login.h>
#include<QLineEdit>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    chageline();
    connect(ui->pushButton,QPushButton::clicked,[=](){
        if(ui->lineEdit->text()==NULL||ui->lineEdit_2->text()==NULL)
        {
              QMessageBox::warning(this,"登陆提示！","注册用户名或密码不能为空！");
        }
        else
        {
            QString fsno=ui->lineEdit->text();
            QString fsname=ui->lineEdit_2->text();
            QString fpwd="123456";
            QString fclass="三年二班";
            QSqlQuery q;
            q.exec(QString("select * from sqt where sno='%1'").arg(fsno));
            if(q.size())
            {
                QMessageBox::warning(this,"注册提示！","注册用户学号重复");
            }
            else
            {
                q.exec(QString("insert into sqt values('%1' ,'%2' ,'%3','%4')").arg(fsno).arg(fsname).arg(fclass).arg(fpwd) );
                QMessageBox::warning(this,"注册提示！","注册成功");
                this->close();
            }

        }

    });
}
void Form::chageline()
{
     ui->lineEdit->setPlaceholderText("学号");
     ui->lineEdit_2->setPlaceholderText("姓名");
}
Form::~Form()
{
    delete ui;
}
