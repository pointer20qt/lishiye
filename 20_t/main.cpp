#include "widget.h"
#include <QApplication>
#include<login.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login w;
    w.setWindowTitle("学生签到系统");//改主窗口名字
    w.show();

    return a.exec();
}
