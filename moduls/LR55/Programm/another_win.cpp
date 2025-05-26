#include "another_win.h"
#include "ui_another_win.h"
#include <QFile>
#include <QTextStream>

Another_win::Another_win(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Another_win)
{
    ui->setupUi(this);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &Another_win::on_pushButton_4_clicked);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &Another_win::on_pushButton_3_clicked);
}

Another_win::~Another_win()
{
    delete ui;
}

void Another_win::on_pushButton_clicked()
{
    this->close();         // Закрываем окно
    emit firstWindow();    // Вызываем сигнал на открытие главного окна
}

// Запись данных в файл
void Another_win::on_pushButton_2_clicked()
{
    QTextStream stream(stdout);
    QString filename = "./iodir/output";
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        // получаем данные из форм
        QString str1 = ui -> lineEdit   -> text();
        QString str2 = ui -> lineEdit_2 -> text();
        out << str1 << " " << str2 << Qt::endl;
        stream << "Данные были записаны в файл!" << Qt::endl;
        // Можно вывести на метке:
        ui -> label_3 -> setText("Данные были записаны в файл!");
    } else {
        stream << "Ошибка записи!" << Qt::endl;
        // Бросаем исключение
    }
    file.close();
}

void Another_win::on_pushButton_3_clicked()
{
    ui -> lineEdit -> clear();
    ui -> lineEdit_2 -> clear();
}

void Another_win::on_pushButton_4_clicked()
{
    this->close();
}
