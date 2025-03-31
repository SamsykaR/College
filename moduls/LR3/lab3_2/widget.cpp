#include "widget.h"

Widget::Widget(QWidget *parent): QWidget(parent)
{
    mainLayout = new QVBoxLayout(this);
    layout1 = new QHBoxLayout;
    mainLayout ->addLayout(layout1);
    labelA = new QLabel(tr("Enter A"),this);
    layout1 ->addWidget(labelA);
    editA = new QLineEdit(this);
    layout1 ->addWidget(editA);
    layout2 = new QHBoxLayout;
    mainLayout ->addLayout(layout2);
    layout2 ->addStretch();
    buttonSetA = new QPushButton(tr("Set A"),this);
    layout2 ->addWidget(buttonSetA);
}

Widget::~Widget(){}
