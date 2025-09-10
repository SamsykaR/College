#include "winhome.h"

Winhome::Winhome(QWidget *parent)
    : QWidget{parent}
{
    resize(800, 600);
    img1 = new QImage("./pic/akula.png");
    lbl1 = new QLabel();
    lbl2 = new QLabel();
    vbox = new QVBoxLayout();
    lbl1->setFixedSize(img1->size());
    lbl1->setPixmap(QPixmap::fromImage(*img1));
    vbox->addWidget(lbl1);
    lbl2->setStyleSheet("font-size: 18px;"
                        "padding: 15px;"
                        "margin-top: 50px;");
    lbl2->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    lbl2->setText("Подводные лодки проекта 885 «Ясень» — серия российских многоцелевых "
                  "\nатомных подводных лодок с крылатыми ракетами 4-го поколения."
                  "\n27 марта 2025 года дал старт спуску на воду новой АПЛ «Пермь», "
                  "\nставшей пятой по счету и четвертой серийной подводной лодкой проекта «Ясень»,"
                  "\nа также первой многоцелевой ПЛ, вооруженной гиперзвуковыми ракетами «Циркон»."
                  "\nНа подлодках проектов 885 «Ясень» и 885М «Ясень-М» 10 торпедных аппаратов "
                  "\nкалибра 533 мм, расположенных под углом побортно в районе ограждения выдвижных "
                  "\nустройств, а за ограждением находятся 8 вертикальных ракетных шахт, в каждой из"
                  "\nкоторых размещается по 4 крылатые ракеты 3М55 «Оникс», 3М22 «Циркон» или по 5 "
                  "\nкрылатых ракет меньшего диаметра 3М14 «Калибр».");
    vbox->addWidget(lbl2);
    setLayout(vbox);
}
