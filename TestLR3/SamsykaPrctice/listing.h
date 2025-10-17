#ifndef LISTING_H
#define LISTING_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QPushButton>
#include <QCheckBox>
#include <QStackedWidget>
#include "redact.h"

/// \brief Класс окна списка блюд
///
/// Отображает список блюд из базы данных с возможностью навигации и перехода к редактированию
class listing : public QWidget
{
    Q_OBJECT
public:
    /// \brief Конструктор класса
    /// \param red Указатель на форму редактирования
    /// \param stackedWidget Указатель на виджет переключения страниц
    /// \param parent Родительский виджет
    listing(redact* red, QStackedWidget* stackedWidget, QWidget *parent = nullptr);

    /// \brief Инициализация списка
    ///
    /// Загружает данные из базы данных и обновляет интерфейс
    void Initial();

private:
    QLineEdit* textEdit;            ///< Текстовое поле
    QVBoxLayout* mainLayout;        ///< Главный макет
    QHBoxLayout* headerLayout;      ///< Макет заголовка
    QStackedWidget* StackedWidget;  ///< Виджет для переключения страниц
    redact* R;                      ///< Указатель на форму редактирования
    QLabel* logotype;               ///< Логотип программы
    QLabel* headerLabel;            ///< Заголовок окна

    QScrollArea* scrollArea;        ///< Область прокрутки
    QWidget* contentWidget;         ///< Виджет содержимого
    QVBoxLayout* contentLayout;     ///< Макет содержимого

    /// \brief Обработчик нажатия кнопки
    /// \param index Индекс выбранного элемента
    void ButtonPress(int index);
};

#endif // LISTING_H
