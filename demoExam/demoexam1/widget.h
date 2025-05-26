#ifndef WIDGET_H
#define WIDGET_H

#include "redaction.h"
#include "home.h"
#include "partners.h"
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
    Home *home;
    Redaction *redaction;
    Partners *partners;
    QVBoxLayout *vbox;
    QHBoxLayout *hbox;
    QPushButton *hbtn;
    QPushButton *rbtn;
    QPushButton *pbtn;
    QPushButton *exbt;
};
#endif // WIDGET_H
