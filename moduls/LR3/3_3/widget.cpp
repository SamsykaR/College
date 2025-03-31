#include "widget.h"

Widget::Widget(QWidget *parent): QWidget(parent)
{
    mainLayout = new QGridLayout(this);

    labelA = new QLabel(tr("Enter A"),this);
    mainLayout ->addWidget(labelA,0,0,1,1);
    editA = new QLineEdit(this);
    mainLayout ->addWidget(editA,0,1,1,2);

    labelB = new QLabel(tr("Enter B"),this);
    mainLayout ->addWidget(labelB,1,0,1,1);
    editB = new QLineEdit(this);
    mainLayout ->addWidget(editB,1,1,1,2);
    buttonSet = new QPushButton(tr("Set"),this);
    mainLayout ->addWidget(buttonSet,2,2,1,1);
}
Widget::~Widget(){}
