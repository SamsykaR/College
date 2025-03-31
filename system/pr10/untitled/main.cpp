/*!
 * \brief Работа с базой данных/ Практическая работа №10
 * \details Спроектировать структуру базы данных об автомобилях: номер, год выпуска, марка, цвет, состояние, фамилия владельца, адрес.
 * / Вариант 2
 * \author  Самсыка Р. М. / И-32 группа
 * \version 0.1
 * \date 31.03.2025
 * \copyright GNU Public License.
 */
#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream stream(stdout);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("base.db");
    if (!db.open()) {
        stream << "Что-то пошло не так!" << Qt::endl;
        return -1;
    }

    QSqlQuery a_query;
    QString str = "CREATE TABLE Car ("
                  "number VARCHAR(255) PRIMARY KEY NOT NULL, "
                  "year integer, "
                  "marka VARCHAR(255), "
                  "color VARCHAR(255), "
                  "status VARCHAR(255), "
                  "lastName VARCHAR(255), "
                  "adres VARCHAR(255)"
                  ");";
    bool b = a_query.exec(str);
    if (!b) {
        stream  << "Не удается создать таблицу" << Qt::endl;
    }
/////////////////////
    QString str_insert = "INSERT INTO Car(number, year, marka, color, status, lastname, adres) "
                         "VALUES ('%1', %2, '%3', '%4', '%5', '%6', '%7');";
    str = str_insert.arg("a444aa")
                    .arg("2000")
                    .arg("tayota")
                    .arg("green")
                    .arg("Good")
                    .arg("Petrov")
                    .arg("Moscow-City");
    b = a_query.exec(str);
    if (!b) {
        stream << "Данные не вставляются" << Qt::endl;
    }
    str = str_insert.arg("b999bb")
              .arg("2010")
              .arg("Mercedes")
              .arg("black")
              .arg("Very Good")
              .arg("Sidorov")
              .arg("Eysk-City");
    b = a_query.exec(str);
    if (!b) {
        stream << "Данные не вставляются" << Qt::endl;
    }
//////////////////////
    if (!a_query.exec("SELECT * FROM Car")) {
        stream << "Выборку сделать не получается" << Qt::endl;
        return -2;
    }
    QSqlRecord rec = a_query.record();
    stream << "========До удаления:"
        << Qt::endl;
    while (a_query.next()) {
        stream << "number is " << a_query.value(0).toString()
               << ". year is "  << a_query.value(1).toString()
               << ". marka is "  << a_query.value(2).toString()
                << ". color is "  << a_query.value(3).toString()
               << ". status is "  << a_query.value(4).toString()
               << ". lastname is "  << a_query.value(5).toString()
               << ". adres is "  << a_query.value(6).toString()
               << Qt::endl;
    }
///////////////////////////////////
    QString del_str = "DELETE FROM Car WHERE marka = 'Mercedes'";
    b = a_query.exec(del_str);
    if (!b) {
        stream << "Данные не удаляются" << Qt::endl;
    }
//////////////////////////////////
    if (!a_query.exec("SELECT * FROM Car")) {
        stream << "Выборку сделать не получается" << Qt::endl;
        return -2;
    }
    rec = a_query.record();
    stream << "========После удаления:"
        << Qt::endl;
    while (a_query.next()) {
        stream << "number is " << a_query.value(0).toString()
        << ". year is "  << a_query.value(1).toString()
        << ". marka is "  << a_query.value(2).toString()
        << ". color is "  << a_query.value(3).toString()
        << ". status is "  << a_query.value(4).toString()
        << ". lastname is "  << a_query.value(5).toString()
        << ". adres is "  << a_query.value(6).toString()
        << Qt::endl;
    }
    return a.exec();
}
