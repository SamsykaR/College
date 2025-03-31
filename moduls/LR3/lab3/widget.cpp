#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    mainLayout = new QBoxLayout(QBoxLayout::TopToBottom,this);

        layout1 = new QBoxLayout(QBoxLayout::LeftToRight);
          mainLayout ->addLayout(layout1);

          buttonA = new QPushButton(tr("Button A"),this);
          layout1 ->addWidget(buttonA);

          buttonB = new QPushButton(tr("Button B"),this);
          layout1 ->addWidget(buttonB);

          buttonC = new QPushButton(tr("Button C"),this);
          layout1 ->addWidget(buttonC);

          layout2 = new QBoxLayout(QBoxLayout::RightToLeft);
          mainLayout ->addLayout(layout2);

          buttonD = new QPushButton(tr("Button D"),this);
          layout2 ->addWidget(buttonD);

          buttonE = new QPushButton(tr("Button E"),this);
          layout2 ->addWidget(buttonE);

          buttonF = new QPushButton(tr("Button F"),this);
          layout2 ->addWidget(buttonF);
}

Widget::~Widget()
{
    delete buttonA;
        delete buttonB;
        delete buttonC;
        delete buttonD;
        delete buttonE;
        delete buttonF;

        delete layout1;
        delete layout2;
}
