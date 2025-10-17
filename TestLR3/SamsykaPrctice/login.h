#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>


/// \brief Класс окна авторизации
///
/// Предоставляет интерфейс для входа в систему с проверкой учетных записей в базе данных
class login : public QWidget
{
    Q_OBJECT
public:
    /// \brief Конструктор класса
    /// \param btn1 Кнопка для изменения стиля после авторизации
    /// \param btn2 Кнопка для изменения стиля после авторизации
    /// \param parent Родительский виджет
    login(QPushButton* btn1, QPushButton* btn2, QWidget *parent = nullptr);

private:
    QVBoxLayout* mainLayout;     ///< Главный макет
    QHBoxLayout* headerLayout;   ///< Макет заголовка
    QVBoxLayout* centerVLayout;  ///< Центральный макет
    QLabel* logotype;            ///< Логотип программы
    QLabel* headerLabel;         ///< Заголовок окна
    QLineEdit* loginRedact;      ///< Поле ввода логина
    QLineEdit* passwordRedact;   ///< Поле ввода пароля
    QPushButton* signInButton;   ///< Кнопка входа
    QLabel* infoLabel;           ///< Поле для информации

    QPushButton* btn1;           ///< Кнопка 1 для изменения стиля
    QPushButton* btn2;           ///< Кнопка 2 для изменения стиля

    /// \brief Авторизация пользователя
    ///
    /// Проверяет логин и пароль в базе данных, устанавливает флаг авторизации при успехе
    void loginUser();
};

#endif // LOGIN_H
