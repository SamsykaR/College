#ifndef WIDGET_H
#define WIDGET_H

#include "winout.h"
#include "winin.h"
#include "winhome.h"
#include "winchart.h"
#include <QWidget>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QStackedWidget *stackedWidget;

    Winhome  *home;
    Winin    *winin;
    Winout   *winout;
    Winchart *winchart;

    QVBoxLayout *vbox;
    QHBoxLayout *hbox;

    QPushButton *homebtn;
    QPushButton *inbtn;
    QPushButton *outbtn;
    QPushButton *chartbtn;
    QPushButton *exbt;
};
#endif // WIDGET_H
