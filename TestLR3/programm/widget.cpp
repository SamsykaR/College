#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QTextStream>
#include <QButtonGroup>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // Инициализация второго окна
    twin = new Another_win();

    // подключение к слоту запуска главного окна по кнопке во втором окне
    connect(twin, &Another_win::firstWindow, this, &Widget::show);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &Widget::on_pushButton_2_clicked);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &Widget::on_pushButton_3_clicked);

}


Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    twin->show();  // Показываем второе окно
    this->close(); // Закрываем основное окно
}

void Widget::on_pushButton_3_clicked()
{
    this->close();
}

void Widget::GetFileText(){
    QTextStream stream(stdout);
    QFile file(Filepath);
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        QString str = in.readLine();
        QString str1 = str.split(' ').at(0);
        QString str2 = str.split(' ').at(1);
        QString line = "1 значение: " + str1 + "\n2 значение: " + str2;
        ui ->label -> setText(line);
        stream << "Данные прочтены!" << Qt::endl;
    } else {
        stream << "Ошибка чтения!" << Qt::endl;
    }
    file.close();
}

void Widget::on_pushButton_2_clicked()
{
    if(ui -> radioButton -> isChecked()) Filepath = "./iodir/output1";
    else if(ui -> radioButton_2 -> isChecked()) Filepath = "./iodir/output2";
    GetFileText();
}

