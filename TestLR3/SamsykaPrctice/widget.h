#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <QStackedWidget>
#include <QPushButton>
#include "login.h"
#include "regist.h"
#include "about.h"
#include "listing.h"
#include "redact.h"

/// \brief Главный виджет приложения
///
/// Управляет основным интерфейсом и навигацией между окнами
class Widget : public QWidget
{
    Q_OBJECT

public:
    /// \brief Конструктор класса
    /// \param parent родительский виджет
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QVBoxLayout *mainLayout;        ///< Главный макет
    QStackedWidget* stackedWidget;  ///< Виджет переключения страниц

    login* loginPage;               ///< Страница авторизации
    regist* registPage;             ///< Страница регистрации
    about* aboutPage;               ///< Страница "О программе"
    listing* listingPage;           ///< Страница списка блюд
    redact* redactPage;             ///< Страница редактирования

    QPushButton* registButton;      ///< Кнопка перехода к регистрации
    QPushButton* closeButton;       ///< Кнопка закрытия приложения
    QPushButton* exitButton;        ///< Кнопка выхода из системы
    QPushButton* listingButton;     ///< Кнопка перехода к списку
    QPushButton* aboutButton;       ///< Кнопка перехода к "О программе"
    QHBoxLayout* buttonsHLayout;    ///< Макет кнопок навигации

    /// \brief Обработчик кнопки регистрации
    void RegistrButtonСlicked();

    /// \brief Обработчик кнопки закрытия
    void CloseButtonСlicked();

    /// \brief Обработчик кнопки выхода
    void ExitButtonСlicked();

    /// \brief Обработчик кнопки списка
    void ListingButtonСlicked();

    /// \brief Обработчик кнопки "О программе"
    void AboutButtonСlicked();
};
#endif // WIDGET_H
