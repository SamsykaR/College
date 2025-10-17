#include <QSqlDatabase>
#include <QSqlQuery>
#include <QHostInfo>
#ifndef GLOBAL_H
#define GLOBAL_H

/// \brief Глобальный класс для управления состоянием приложения и базой данных
///
/// Содержит статические методы и поля для работы с БД и управления авторизацией
class GlobalClass
{
public:
    /// \brief Конструктор класса
    GlobalClass();

    /// \brief Получить подключение к базе данных
    /// \return Ссылка на объект базы данных
    static QSqlDatabase& db();

    /// \brief Инициализация подключения к базе данных
    ///
    /// Создает подключение к SQL Server, проверяет существование БД, при необходимости создает новую базу данных и таблицы
    static void Initial();

    static int CurentIndex;    ///< Текущий выбранный индекс записи
    static bool isAutorized;   ///< Флаг авторизации пользователя

private:
    static QSqlDatabase data;  ///< Подключение к базе данных
};

#endif // GLOBAL_H
