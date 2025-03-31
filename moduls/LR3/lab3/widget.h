#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QBoxLayout>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT
    public:
    Widget(QWidget *parent = 0);
        ~Widget();
    private:
        QBoxLayout *mainLayout=NULL;
        QBoxLayout *layout1=NULL;
        QPushButton *buttonA=NULL;
        QPushButton *buttonB=NULL;
        QPushButton *buttonC=NULL;
        QBoxLayout *layout2=NULL;
        QPushButton *buttonD=NULL;
        QPushButton *buttonE=NULL;
        QPushButton *buttonF=NULL;

};

#endif // WIDGET_H
