#include "login.h"
#include "global.h"
#include <QHostInfo>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QTimer>

login::login(QPushButton* btn1, QPushButton* btn2, QWidget *parent)
    : QWidget(parent), btn1(btn1), btn2(btn2)
{
    mainLayout = new QVBoxLayout();

    logotype = new QLabel();
    logotype->setPixmap(QPixmap("../../pic/logo.png").scaledToWidth(80));
    headerLabel = new QLabel("Вход в систему");
    headerLabel->setStyleSheet("font-size: 25px;");

    headerLayout = new QHBoxLayout();
    headerLayout->addWidget(logotype);
    headerLayout->addStretch();
    headerLayout->addWidget(headerLabel);

    loginRedact = new QLineEdit();
    loginRedact->setStyleSheet("font-size: 20px;");
    passwordRedact = new QLineEdit();
    passwordRedact->setStyleSheet("font-size: 20px;");
    passwordRedact->setEchoMode(QLineEdit::Password);
    signInButton = new QPushButton("Войти");
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

    connect(signInButton, &QPushButton::clicked, this, &login::loginUser);

    setLayout(mainLayout);
}

void login::loginUser(){
    QTimer::singleShot(6000, [this]() {
        infoLabel->clear();
    });

    if(GlobalClass::isAutorized){
        infoLabel->setStyleSheet("font-size: 14px; color: brown");
        infoLabel->setText("вы уже авторизованы");
        return;
    }
    if(loginRedact->text()=="" || passwordRedact->text()==""){
        infoLabel->setStyleSheet("font-size: 14px; color: brown");
        infoLabel->setText("Заполните все поля");
        return;
    }
    QSqlQuery Querry(GlobalClass::db());
    QString SQLQuerry = QString("SELECT * FROM Users WHERE login = '%1';").arg(loginRedact->text());
    Querry.exec(SQLQuerry);
    if (!Querry.next()) {
        infoLabel->setStyleSheet("font-size: 14px; color: red");
        infoLabel->setText("Пользователь не найден");
        qDebug() << "Пользователь не найден ";
        qDebug() << "Ошибка запроса:" << Querry.lastError().text();
        qDebug() << "Ошибка базы:" << GlobalClass::db().lastError().text();
    } else {
        SQLQuerry = QString("SELECT * FROM Users WHERE login = '%1' AND password = '%2';").arg(loginRedact->text()).arg(passwordRedact->text());
        Querry.exec(SQLQuerry);
        if (!Querry.next()) {
            infoLabel->setStyleSheet("font-size: 14px; color: red");
            infoLabel->setText("Пароль неверный");
            qDebug() << "Пароль неверный";
            qDebug() << "Ошибка запроса:" << Querry.lastError().text();
            qDebug() << "Ошибка базы:" << GlobalClass::db().lastError().text();
        }
        else {
            GlobalClass::isAutorized = true;
            infoLabel->setStyleSheet("font-size: 14px; color: green");
            infoLabel->setText("вы успешно вошли");
            btn1->setStyleSheet("background-color: none; font-size: 14px; font-weight: bold;");
            btn2->setStyleSheet("background-color: none; font-size: 14px; font-weight: bold;");
            loginRedact->clear();
            passwordRedact->clear();
        }
    }
}
