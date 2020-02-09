#include "login.h"
#include "ui_login.h"
#include<QMessageBox>
#include<QSqlQuery>
#include<QDebug>
#include<widget.h>
#include"form.h"
#include <QLabel>
#include<QPushButton>
#include<QLineEdit>
login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("st");
    db.setUserName("root");
    db.setPassword("123456");
    if(db.open())
    {
        qDebug()<<"成功连接数据库";
    }
    else
    {
        qDebug()<<"连接数据库失败";
    }
    loginn();
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
}
void login::loginn()
{
    connect(ui->pushButton,QPushButton::clicked,[=]()
    {
        if(ui->lineEdit->text()==NULL||ui->lineEdit_2->text()==NULL)
        {
              QMessageBox::warning(this,"登陆提示！","用户名或密码不能为空！");
        }
        else
        {
            QSqlQuery q;
            q.exec(QString("select * from sqt where sno='%1' and passwordd='%2' ").arg(ui->lineEdit->text()).arg(ui->lineEdit_2->text()));
            if(q.size())
            {
                QString so=ui->lineEdit->text();
                Widget *w=new Widget(NULL, so);
                w->show();
                this->close();

            }
            else
            {
                 QMessageBox::warning(this,"登陆提示！","用户名或密码错误");
            }
        }

    });

}
login::~login()
{
    delete ui;
}

void login::on_pushButton_2_clicked()//注册
{
    Form *f=new Form();
    f->show();

}

void login::on_pushButton_4_clicked()
{
    QMessageBox::warning(this,"笨啊","重新注册");
}
