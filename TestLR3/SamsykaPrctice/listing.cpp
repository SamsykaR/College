#include "listing.h"
#include "global.h"
#include <QHostInfo>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>


listing::listing( redact* red, QStackedWidget* stackedWidget, QWidget *parent)
    : QWidget(parent), StackedWidget(stackedWidget), R(red)
{
    mainLayout = new QVBoxLayout();
    logotype = new QLabel();
    logotype->setPixmap(QPixmap("../../pic/logo.png").scaledToWidth(80));
    headerLabel = new QLabel("Меню ресторана");
    headerLabel->setStyleSheet("font-size: 25px;");

    headerLayout = new QHBoxLayout();
    headerLayout->addWidget(logotype);
    headerLayout->addStretch();
    headerLayout->addWidget(headerLabel);

    mainLayout->addLayout(headerLayout);

    scrollArea = new QScrollArea();
    scrollArea->setWidgetResizable(true);

    contentWidget = new QWidget;
    contentLayout = new QVBoxLayout(contentWidget);



    QSqlQuery Querry(GlobalClass::db());
    QString SQLQuerry = QString("IF OBJECT_ID(N'Foods') IS NULL "
                                "Create table Foods("
                                "id INT PRIMARY KEY IDENTITY(1,1),"
                                "Category NVARCHAR(50) NOT NULL,"
                                "Name NVARCHAR(50) NOT NULL,"
                                "Cost DECIMAL(10,2) NOT NULL,"
                                "Description NVARCHAR(200) NOT NULL"
                                ");");
    Querry.exec(SQLQuerry);
    if (!Querry.next()) {
        qDebug() << "Не получилось создать таблицу еды (возможно она уже есть) ";
        qDebug() << "Ошибка:" << Querry.lastError().text();
    }

    scrollArea->setWidget(contentWidget);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    mainLayout->addWidget(scrollArea);

    setLayout(mainLayout);

    Initial();
}


void listing::ButtonPress(int index){
    GlobalClass::CurentIndex = index;
    qDebug() << GlobalClass::CurentIndex;
    qDebug() << "Передан индекс в Redacted:" << index;
    R->LoadData();
    listing::StackedWidget->setCurrentIndex(4);
}

void listing::Initial(){

    QLayoutItem* item;
    while ((item = contentLayout->takeAt(0)) != nullptr) {
        if (item->widget()) {
            item->widget()->deleteLater();
        }
        delete item;
    }

    QSqlQuery Querry(GlobalClass::db());
    QString SQLQuerry = QString("SELECT * FROM Foods ORDER BY Category, Id;");
    Querry.exec(SQLQuerry);
    if (!Querry.next()) {
        qDebug() << "Не получается вывести лист ";
        qDebug() << "Ошибка:" << Querry.lastError().text();
    } else {
        Querry.previous();
        while(Querry.next()){
            QPushButton *button = new QPushButton();
            button->setStyleSheet("background-color: orange; font-size: 14px; font-weight: bold;");
            button->setText(Querry.value(0).toString() + "\t | \t" + Querry.value(1).toString() + "\t | \t" + Querry.value(2).toString());
            connect(button, &QPushButton::clicked, [=]() {
                listing::ButtonPress(button->text().split(' ').at(0).toInt());
            });
            contentLayout->addWidget(button);
        }
    }
    QPushButton *button = new QPushButton();
    button->setStyleSheet("background-color: orange; font-size: 14px; font-weight: bold; color: gray;");
    button->setText("Новая запись");
    connect(button, &QPushButton::clicked, [=]() {
        listing::ButtonPress(-1);
    });
    contentLayout->addWidget(button);

}
