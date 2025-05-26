#include "home.h"

/// \def Home(parent)
/// \brief Конструктор домашней страницы
///
/// \param parent Родительский виджет
Home::Home(QWidget *parent)
    : QWidget{parent}
{
    resize(800, 540);
    //setStyleSheet("background-color: black;");
    icon = new QLabel();
    icon->setPixmap(QPixmap("res/icon.ico"));
    lbl = new QLabel("Компания занимается производством и реализует свою продукцию через\n"
                     "партнеров,которыедоставляютпродукцию компаниидоконечных\n"
                     "потребителей. Для эффективного взаимодействия с партнерами и контроля их\n"
                     "работы требуется система, позволяющая обрабатывать всю информацию в\n"
                     "цифровом формате.");
    lbl->setAlignment(Qt::AlignTop | Qt::AlignCenter);
    lbl->setStyleSheet("font-size: 24px;"
                       "font-weight:bold;");

    lblname = new QLabel("компания «Мастер пол»");
    lblname->setAlignment(Qt::AlignTop | Qt::AlignCenter);
    lblname->setStyleSheet("font-size: 30px;"
                       "font-weight:bold;");
    hbox = new QHBoxLayout();
    vbox = new QVBoxLayout();
    hbox->addWidget(icon);
    hbox->addWidget(lblname);
    vbox->addLayout(hbox);
    vbox->addWidget(lbl);
    setLayout(vbox);
}
