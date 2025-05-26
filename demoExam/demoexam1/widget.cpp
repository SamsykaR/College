#include "widget.h"

/// \def Widget(parents)
/// \brief Конструктор для главного окна приложения
///
/// \param parent Родительский виджет
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(800, 600);
    setStyleSheet("Widget { background-color: #FFFFFF; color: black; font-family: 'Segoe UI'; }"
                  "QLabel { color: black; }"
                  "QPushButton { background-color: #F4E8D3; color: black; border: 2px solid #67BA80; border-radius: 5px }");
    setWindowTitle("Описание предметной области");
    setWindowIcon(QIcon("res/icon.ico"));
    stackedWidget = new QStackedWidget(this); // Стек для объединения этих страниц
    home      = new Home();             // Главная страница
    partners  = new Partners();         // Страница партнеров
    redaction = new Redaction();        // Страница для изменения/ввода партнеров
    stackedWidget->addWidget(home);     // Отправляем в стек
    stackedWidget->addWidget(partners);
    stackedWidget->addWidget(redaction);

    vbox = new QVBoxLayout();           // Компонуем вертикально
    vbox->addWidget(stackedWidget);     // Первой строкой идет стек

    hbox = new QHBoxLayout();                           // Второй строкой идет горизонтальный компоновщик
    hbtn = new QPushButton("&Главная");                  // Кнопка для перехода к окну Home
    pbtn = new QPushButton("&Список партнеров");         // Кнопка для перехода к окну Partners
    rbtn = new QPushButton("&Редактирование партнеров"); // Кнопка для перехода к окну Redaction
    exbt = new QPushButton("&Закрыть окно");             // Кнопка закрытия окна программы


    hbox->addWidget(hbtn);
    hbox->addWidget(pbtn);
    hbox->addWidget(rbtn);
    hbox->addWidget(exbt);

    vbox->addLayout(hbox);
    setLayout(vbox);

    // Обрабатываем нажатие кнопок
    // Эти слоты мы не программируем, Qt это делает сам
    // В новом стиле
    connect(hbtn, &QPushButton::clicked, [&](){ stackedWidget->setCurrentIndex(0); });
    connect(pbtn, &QPushButton::clicked, [&](){ stackedWidget->setCurrentIndex(1); });
    connect(rbtn, &QPushButton::clicked, [&](){ stackedWidget->setCurrentIndex(2); });
    // В старом стиле
    connect(exbt, SIGNAL(clicked()), this, SLOT(close()));
}

/// \def ~Widget()
/// \brief Деструктор главного окна
Widget::~Widget() {}
