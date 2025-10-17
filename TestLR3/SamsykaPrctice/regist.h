#ifndef REGIST_H
#define REGIST_H
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include "global.h"

/// \brief Класс окна регистрации
///
/// Предоставляет интерфейс для создания новых пользователей с сохранением в базе данных
class regist : public QWidget
{
    Q_OBJECT
public:
    /// \brief Конструктор класса
    /// \param parent родительский виджет
    regist(QWidget *parent = nullptr);

private:
    QVBoxLayout* mainLayout;     ///< Главный макет
    QHBoxLayout* headerLayout;   ///< Макет заголовка
    QVBoxLayout* centerVLayout;  ///< Центральный макет
    QLabel* logotype;            ///< Логотип программы
    QLabel* headerLabel;         ///< Заголовок окна
    QLineEdit* loginRedact;      ///< Поле ввода логина
    QLineEdit* passwordRedact;   ///< Поле ввода пароля
    QPushButton* signInButton;   ///< Кнопка регистрации
    QLabel* infoLabel;           ///< Поле для информации

    /// \brief Добавление нового пользователя
    ///
    /// Создает новую запись пользователя в базе данных после проверки введенных данных
    void NewUserAdd();

    GlobalClass *G;              ///< Указатель на глобальный класс
};

#endif // REGIST_H
