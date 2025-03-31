#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
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
        QVBoxLayout *mainLayout=NULL;
        QHBoxLayout *layout1=NULL;
        QLabel *labelA=NULL;
        QLineEdit *editA=NULL;
        QHBoxLayout *layout2=NULL;
        QPushButton *buttonSetA=NULL;
};

#endif // WIDGET_H
