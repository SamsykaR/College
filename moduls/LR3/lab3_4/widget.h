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
    QLabel *labelEnter=NULL;
    QLineEdit *editEnter=NULL;
    QLabel *labelKey=NULL;
    QLineEdit *editKey=NULL;
    QLabel *labelEncrypt=NULL;
    QLineEdit *editEncrypt=NULL;
    QPushButton *buttonSet=NULL;
};

#endif // WIDGET_H
