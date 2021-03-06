#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QString>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0 , QString so=NULL);
    ~Widget();
    void dataToTable(QString sql);
    void displayclass();
    void displaysno();
    QString ssno;

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
