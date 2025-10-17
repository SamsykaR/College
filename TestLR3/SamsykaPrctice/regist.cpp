#include "regist.h"
#include "global.h"
#include <QSqlError>
#include <QDebug>
#include <QHostInfo>
#include <QTimer>


regist::regist(QWidget *parent)
    : QWidget(parent)
{
    mainLayout = new QVBoxLayout();

    logotype = new QLabel();
    logotype->setPixmap(QPixmap("../../pic/logo.png").scaledToWidth(80));
    headerLabel = new QLabel("Регистрация");
    headerLabel->setStyleSheet("font-size: 25px;");

    headerLayout = new QHBoxLayout();
    headerLayout->addWidget(logotype);
    headerLayout->addStretch();
    headerLayout->addWidget(headerLabel);

    loginRedact = new QLineEdit();
    loginRedact->setStyleSheet("font-size: 20px;");
    passwordRedact = new QLineEdit();
    passwordRedact->setStyleSheet("font-size: 20px;");
    signInButton = new QPushButton("Зарегистрироваться");
    signInButton->setStyleSheet("font-size: 16px;");
    infoLabel = new QLabel();

    centerVLayout = new QVBoxLayout();

    centerVLayout->addWidget(loginRedact, 0, Qt::AlignCenter);
    centerVLayout->addWidget(passwordRedact, 0, Qt::AlignCenter);
    centerVLayout->addWidget(signInButton, 0, Qt::AlignCenter);
    centerVLayout->addWidget(infoLabel, 0, Qt::AlignCenter);

    mainLayout->addLayout(headerLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(centerVLayout, 1);
    mainLayout->addStretch();

    connect(signInButton, &QPushButton::clicked, this, &regist::NewUserAdd);

    setLayout(mainLayout);
}

void regist::NewUserAdd(){
    QTimer::singleShot(6000, [this]() {
        infoLabel->clear();
    });

    if(loginRedact->text()=="" || passwordRedact->text()==""){
        infoLabel->setStyleSheet("font-size: 14px; color: brown");
        infoLabel->setText("Заполните все поля");
        return;
    }

    QSqlQuery Querry(GlobalClass::db());
    QString SQLQuerry =
        "IF OBJECT_ID(N'Users') IS NULL  "
        "CREATE TABLE Users("
        "id INT PRIMARY KEY IDENTITY(1,1), "
        "login NVARCHAR(50) NOT NULL, "
        "password NVARCHAR(50) NOT NULL"
        ");";

    qDebug() << "Попытка создать таблицу Users...";
    if (!Querry.exec(SQLQuerry)) {
        qDebug() << "Ошибка создания таблицы:" << Querry.lastError().text();
    } else {
        qDebug() << "Таблица Users успешно создана или уже есть!";
    }

    SQLQuerry = QString("INSERT INTO Users VALUES ('%1', %2);").arg(loginRedact->text()).arg(passwordRedact->text());
    qDebug() << "Попытка записать в таблицу Users...";
    if (!Querry.exec(SQLQuerry)) {
        qDebug() << "Ошибка записи:" << Querry.lastError().text();
    } else {
        infoLabel->setStyleSheet("font-size: 14px; color: green");
        infoLabel->setText("Пользователь добавлен");
        qDebug() << "Запись добавлена!";
        loginRedact->text()="";
        passwordRedact->text()="";
    }
}
