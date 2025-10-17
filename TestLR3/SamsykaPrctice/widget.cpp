#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    registButton = new QPushButton("Регистрация");
    closeButton = new QPushButton("Закрыть");
    exitButton = new QPushButton("Выход");
    listingButton = new QPushButton("Список");
    aboutButton = new QPushButton("Информация о программе");

    loginPage = new login(aboutButton, listingButton);
    registPage = new regist();
    aboutPage = new about();

    redactPage = new redact();

    stackedWidget = new QStackedWidget(this);
    listingPage = new listing(redactPage, stackedWidget);
    stackedWidget->addWidget(loginPage);
    stackedWidget->addWidget(registPage);
    stackedWidget->addWidget(aboutPage);
    stackedWidget->addWidget(listingPage);
    stackedWidget->addWidget(redactPage);

    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(stackedWidget);


    registButton->setStyleSheet("font-size: 14px; font-weight: bold;");
    closeButton->setStyleSheet("font-size: 14px; font-weight: bold;");
    exitButton->setStyleSheet("font-size: 14px; font-weight: bold;");
    listingButton->setStyleSheet("font-size: 14px; font-weight: bold;");
    aboutPage->setStyleSheet("font-size: 14px; font-weight: bold;");

    buttonsHLayout = new QHBoxLayout();
    buttonsHLayout->addWidget(registButton);
    buttonsHLayout->addWidget(listingButton);
    buttonsHLayout->addWidget(aboutButton);
    buttonsHLayout->addWidget(exitButton);
    buttonsHLayout->addStretch();
    buttonsHLayout->addWidget(closeButton);
    mainLayout->addLayout(buttonsHLayout);

    setLayout(mainLayout);

    connect(registButton, &QPushButton::clicked, this, &Widget::RegistrButtonСlicked);
    connect(closeButton, &QPushButton::clicked, this, &Widget::CloseButtonСlicked);
    connect(exitButton, &QPushButton::clicked, this, &Widget::ExitButtonСlicked);
    connect(listingButton, &QPushButton::clicked, this, &Widget::ListingButtonСlicked);
    connect(aboutButton, &QPushButton::clicked, this, &Widget::AboutButtonСlicked);

    GlobalClass::isAutorized = false;
    aboutButton->setStyleSheet("background-color: gray; font-size: 14px; font-weight: bold;");
    listingButton->setStyleSheet("background-color: gray; font-size: 14px; font-weight: bold;");
}

Widget::~Widget() {}

void Widget::ExitButtonСlicked(){
    GlobalClass::isAutorized = false;
    aboutButton->setStyleSheet("background-color: gray; font-size: 14px; font-weight: bold;");
    listingButton->setStyleSheet("background-color: gray; font-size: 14px; font-weight: bold;");
    stackedWidget->setCurrentIndex(0);
}

void Widget::RegistrButtonСlicked(){
    stackedWidget->setCurrentIndex(1);
}

void Widget::AboutButtonСlicked(){
    if(GlobalClass::isAutorized)
        stackedWidget->setCurrentIndex(2);
}

void Widget::ListingButtonСlicked(){
    if (GlobalClass::isAutorized) {
        listingPage->Initial();
        stackedWidget->setCurrentIndex(3);
    }
}

void Widget::CloseButtonСlicked(){
    this->close();
}

