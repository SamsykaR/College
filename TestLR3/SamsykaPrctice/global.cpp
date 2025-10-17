#include <QSqlDatabase>
#include <QSqlQuery>
#include <QHostInfo>
#include <QSqlError>
#include "global.h"

bool GlobalClass::isAutorized = false;
int GlobalClass::CurentIndex = -1;
QSqlDatabase GlobalClass::data;

GlobalClass::GlobalClass(){}

QString server = QHostInfo::localHostName() + "\\SQLEXPRESS";
const QString dbName = "MyDataBase";
const QString user = "SA";
const QString password = "123";

void GlobalClass::Initial(){
    if (data.isOpen())
        return;
    GlobalClass::data = QSqlDatabase::addDatabase("QODBC");

    QString effectiveServer = server;

    data.setUserName(user);
    data.setPassword(password);

    QString connectionString = QString(
                                   "DRIVER={ODBC Driver 18 for SQL Server};"
                                   "SERVER=%1;"
                                   "TrustServerCertificate=yes;"
                                   ).arg(effectiveServer);

    data.setDatabaseName(connectionString);
    qDebug() << "\n\nПопытка подключения к серверу:" << effectiveServer;

    if (!data.open()) {
        effectiveServer = QHostInfo::localHostName();
        connectionString = QString(
                               "DRIVER={ODBC Driver 18 for SQL Server};"
                               "SERVER=%1;"
                               "TrustServerCertificate=yes;"
                               ).arg(effectiveServer);

        data.setDatabaseName(connectionString);
        qDebug() << "Повторная попытка:" << effectiveServer;

        if(!data.open()){
            qDebug() << "Ошибка:" << data.lastError().text();
            return;
        }
    }

    QSqlQuery checkDb(data);
    if (!checkDb.exec(QString("SELECT DB_ID('%1')").arg(dbName))) {
        qDebug() << "Ошибка проверки БД:" << checkDb.lastError().text();
        return;
    }

    if (checkDb.next() && checkDb.value(0).isNull()) {
        qDebug() << "Создаем БД...";
        if (!checkDb.exec(QString("CREATE DATABASE %1").arg(dbName))) {
            qDebug() << "Ошибка создания БД:" << checkDb.lastError().text();
            return;
        }
    }
    data.close();

    connectionString = QString(
                           "DRIVER={ODBC Driver 18 for SQL Server};"
                           "SERVER=%1;"
                           "DATAboutPageASE=%2;"
                           "TrustServerCertificate=yes;"
                           ).arg(effectiveServer, dbName);

    data.setDatabaseName(connectionString);
    qDebug() << "Попытка подключения к базе данных...";
    if (!data.open(user, password)) {
        qDebug() << "Ошибка подключения к БД:" << data.lastError().text();
    }
    else {
        qDebug() << "Успешное подключение к БД!";
    }
}

QSqlDatabase& GlobalClass::db()
{
    if (!data.isOpen())
        Initial();
    return data;
}

