#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT

    public:
        Widget(QWidget *parent = 0);
        ~Widget();

    private:
        QGridLayout *mainLayout=NULL;
        QLabel *labelA=NULL;
        QLineEdit *editA=NULL;
        QLabel *labelB=NULL;
        QLineEdit *editB=NULL;
        QPushButton *buttonSet=NULL;
};

#endif // WIDGET_H
