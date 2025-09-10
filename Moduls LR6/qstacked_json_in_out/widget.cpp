#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(800, 600);
    setWindowTitle("Подводные лодки");
    //setWindowIcon(QIcon("./res/master_pol.ico"));
    stackedWidget = new QStackedWidget(this); // Стек виджетов окон

    home      = new Winhome();                // Главное окно
    winout    = new Winout();                // Окно вывода
    winin     = new Winin();                  // Окно ввода
    winchart  = new Winchart();               // Окно визуализации

    stackedWidget->addWidget(home);           // Отправляем в стек
    stackedWidget->addWidget(winout);
    stackedWidget->addWidget(winin);
    stackedWidget->addWidget(winchart);

    vbox = new QVBoxLayout();                // Компонуем вертикально
    vbox->addWidget(stackedWidget);          // Первой строкой стек
    hbox = new QHBoxLayout();                // Второй строкой идет горизонтальный компоновщик

    homebtn  = new QPushButton("&Главная"); // Кнопка для перехода к окну Home
    outbtn   = new QPushButton("&Ввод");    // Кнопка для перехода к окну OutFile
    inbtn    = new QPushButton("В&ывод");   // Кнопка для перехода к окну InFile
    chartbtn = new QPushButton("Г&рафик");  // Кнопка для перехода к окну InFile
    exbt = new QPushButton("&Закрыть");     // Кнопка закрытия окна программы
    hbox->addWidget(homebtn);
    hbox->addWidget(outbtn);
    hbox->addWidget(inbtn);
    hbox->addWidget(chartbtn);
    hbox->addWidget(exbt);

    vbox->addLayout(hbox);
    setLayout(vbox);

    // Обрабатываем нажатие кнопок
    // Эти слоты мы не программируем, Qt это делает сам
    // В новом стиле
    connect(homebtn,  &QPushButton::clicked, [&](){ stackedWidget->setCurrentIndex(0); });
    connect(outbtn,   &QPushButton::clicked, [&](){ stackedWidget->setCurrentIndex(1); });
    connect(inbtn,    &QPushButton::clicked, [&](){ stackedWidget->setCurrentIndex(2); });
    connect(chartbtn, &QPushButton::clicked, [&](){ stackedWidget->setCurrentIndex(3); });
    // В старом стиле
    connect(exbt, SIGNAL(clicked()), this, SLOT(close()));
}

Widget::~Widget() {}
