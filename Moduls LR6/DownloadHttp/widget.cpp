#include "widget.h"
#include "ui_widget.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    downloader = new Downloader(); // Инициализируем Downloader

    // по нажатию кнопки запускаем получение данных по http
    connect(ui->pushButton, &QPushButton::clicked, downloader, &Downloader::getData);
    // по окончанию получения данных считываем данные из файл
    connect(downloader, &Downloader::onReady, this, &Widget::readFile);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::readFile()
{
    QFile file("./file.json");
    if (!file.open(QIODevice::ReadOnly)) // Открваем файл, если это возможно
            return; // если открытие файла невозможно, выходим из слота
    // в противном случае считываем данные и устанавилваем их в textEdit
    ui->textEdit->setText(redactText(file.readAll()));
}

QString Widget::redactText(QString text){
    QString redacted = "";
    QJsonDocument d = QJsonDocument::fromJson(text.toUtf8());
    QJsonObject j = d.object();
    QJsonValue v = j.value("Valute");
    QJsonObject valutes = v.toObject();
    QStringList KeysList = valutes.keys();
    for(int i = 0; i < KeysList.count(); i++){
        QJsonValue curentValue = valutes.value(KeysList[i]);
        QJsonObject curentObject = curentValue.toObject();
        double value = curentObject.value("Value").toDouble();
        redacted += curentObject.value("Name").toString()
        + " = "
        + QString::number(value)
        + "\n";
    }
    return redacted;
}
