#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLCDNumber>
#include <QLineEdit>
#include <QLabel>

/// \class Widget
/// \brief Основной класс GUI-приложения
///
/// Наследует QWidget и реализует интерфейс для вычисления формулы
class Widget : public QWidget {
    Q_OBJECT

public:
    QLabel *imageLabel;        /*!< Отображение графической формулы */
    QLineEdit *argument1;      /*!< Поле ввода параметра a */
    QLineEdit *argument2;      /*!< Поле ввода параметра b */
    QLineEdit *argument3;      /*!< Поле ввода параметра c */
    QLineEdit *argument4;      /*!< Поле ввода переменной x */
    QPushButton *resultButton; /*!< Кнопка запуска вычислений */

    QVBoxLayout *box1;         /*!< Главный вертикальный контейнер */
    QHBoxLayout *box2;         /*!< Горизонтальный контейнер для формулы и ввода */
    QVBoxLayout *box3;         /*!< Вертикальный контейнер полей ввода */

    QLCDNumber *myLCD;         /*!< LCD-дисплей для отображения результата */
    float result;              /*!< Переменная для хранения результата вычислений */

    /// \brief Конструктор виджета
    /// \param parent Родительский виджет (по умолчанию nullptr)
    explicit Widget(QWidget *parent = nullptr);
    
    /// \brief Деструктор виджета
    ~Widget();

private slots:
    /// \brief Слот для обработки нажатия кнопки вычисления
    ///
    /// Вычисляет значение формулы по введенным параметрам:
    void ResultAction();
};

#endif // WIDGET_H