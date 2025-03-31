#include "widget.h"

Widget::Widget(QWidget *parent): QWidget(parent)
{
    mainLayout = new QGridLayout(this);

    setStyleSheet("background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #5CCDC9, stop: 0.4 #FFE273, stop:1 #EA69A6)");

    labelEnter = new QLabel(tr("Enter Text"),this);
    labelEnter -> setStyleSheet("background-color : white; color : black;"
                                "border-style: solid;"
                                "border-width: 2px;"
                                "border-color: black;");
    mainLayout ->addWidget(labelEnter,0,0,1,1);
    editEnter = new QLineEdit(this);
    editEnter -> setStyleSheet("background: white");
    mainLayout ->addWidget(editEnter,0,1,1,2);

    labelKey = new QLabel(tr("Key"),this);
    labelKey -> setStyleSheet("background-color : white; color : black;"
                              "border-style: solid;"
                              "border-width: 2px;"
                              "border-color: black;");
    mainLayout ->addWidget(labelKey,1,0,1,1);
    editKey = new QLineEdit(this);
    editKey -> setStyleSheet("background: white");
    mainLayout ->addWidget(editKey,1,1,1,2);

    labelEncrypt = new QLabel(tr("Encryption Text"),this);
    labelEncrypt -> setStyleSheet("background-color : white; color : black;"
                                  "border-style: solid;"
                                  "border-width: 2px;"
                                  "border-color: black;");
    mainLayout ->addWidget(labelEncrypt,2,0,1,1);
    editEncrypt = new QLineEdit(this);
    editEncrypt -> setStyleSheet("background: white");
    mainLayout ->addWidget(editEncrypt,2,1,1,2);

    buttonSet = new QPushButton(tr("Ok"),this);
    buttonSet -> setStyleSheet("background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #0A2323, stop: 1 #3A2310)");
    mainLayout ->addWidget(buttonSet,3,0,1,1);

    buttonSet = new QPushButton(tr("Cancel"),this);
    buttonSet -> setStyleSheet("background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #0A2323, stop: 1 #3A2310)");
    mainLayout ->addWidget(buttonSet,3,2,1,1);
}
Widget::~Widget(){}
