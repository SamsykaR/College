#include "widget.h"
#include <QtMath>

/// \brief Конструктор инициализирует GUI-элементы
Widget::Widget(QWidget *parent) : QWidget(parent) {
    // Инициализация элементов
    imageLabel = new QLabel(this);
    imageLabel->setPixmap(QPixmap("formula.png")); /*!< Загрузка изображения */
    
    resultButton = new QPushButton("Result");
    myLCD = new QLCDNumber();
    
    // Создание полей ввода
    argument1 = new QLineEdit(this);
    argument2 = new QLineEdit(this);
    argument3 = new QLineEdit(this);
    argument4 = new QLineEdit(this);

    // Настройка компоновки
    box1 = new QVBoxLayout(this);
    box2 = new QHBoxLayout(this);
    box3 = new QVBoxLayout(this);
    
    // Добавление элементов в контейнеры
    box3->addWidget(argument1);
    box3->addWidget(argument2);
    box3->addWidget(argument3);
    box3->addWidget(argument4);
    box3->addWidget(resultButton);

    box2->addWidget(imageLabel);
    box2->addLayout(box3);

    box1->addWidget(myLCD);
    box1->addLayout(box2);

    setLayout(box1);

    /// \brief соединение сигнала и слота
    QObject::connect(resultButton, &QPushButton::clicked, 
                    this, &Widget::ResultAction);
}

Widget::~Widget() { }

/// \brief Вычисление значения формулы
void Widget::ResultAction() {
    // Получение значений из полей ввода
    float a = argument1->text().toFloat();
    float b = argument2->text().toFloat();
    float c = argument3->text().toFloat();
    float x = argument4->text().toFloat();

    // Вычисление формулы
    result = (qSqrt(a + c*x) + qLn(x)) / (qAbs(a * qPow(x, 2) + x + b));
    
    // Обновление дисплея
    myLCD->display(result);
}