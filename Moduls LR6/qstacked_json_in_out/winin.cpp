#include "winin.h"

Winin::Winin(QWidget *parent)
    : QWidget{parent}
{
    resize(800, 600);
    lblhd = new QLabel();
    lblhd->setText("Аналоги АПЛ \"Ясень\"");
    lblhd->setAlignment(Qt::AlignTop | Qt::AlignCenter);
    lblhd->setStyleSheet("font-size: 32px;"
                         "font-weight:bold;");
    vbox = new QVBoxLayout();
    vbox->addWidget(lblhd);
    tbl  = new QTableWidget();
    vbox->addWidget(tbl);
    btn1 = new QPushButton("Загрузить данные");
    hbox = new QHBoxLayout();
    hbox->addWidget(btn1);
    hbox->addStretch();
    vbox->addLayout(hbox);
    setLayout(vbox);

    connect(btn1, &QPushButton::clicked, this, &Winin::on_btn1_clicked);
}

void Winin::on_btn1_clicked()
{
    QFile file;
    file.setFileName("./json/db.json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Ошибка! Файл недоступен для записи!";
        // Выбрасываем исключение!!!
    } else {
        QTextStream json(&file); // Создаем файловый поток ввода
        QJsonObject obj;         // Объект JSON
        QJsonObject obj_el;      // Объект JSON - элемент массива
        QJsonArray  arr;         // Массив JSON
        QJsonDocument doc;       // Создаем JSON-документ
        QString val = json.readAll(); // Получаем содержимое файла
        QJsonParseError error;        // Переменная для хранения ошибок
        doc = QJsonDocument::fromJson(val.toUtf8(), &error); // Проверить error!!!
        // И бросаем исключение, в случае ошибки!!!
        obj = doc.object();
        arr = obj["Submarines"].toArray();
        qint32 size = arr.count(); // Получили размер массива
        // Устанавливаем размер таблицы:
        tbl->setRowCount(size);
        tbl->setColumnCount(5);
        // Устанавливаем заголовки столбцов таблицы:
        QStringList columnHeaderLabels;
        columnHeaderLabels << "Название"
                           << "Количество"
                           << "Водоизмещение"
                           << "Торпеды"
                           << "Ракеты";
        tbl->setHorizontalHeaderLabels(columnHeaderLabels);
        for (int i = 0; i < size; i++) {        // Распаковываем элементы массива
            const QJsonValue elem = arr.at(i);
            obj_el = elem.toObject();
            // Заполняем таблицу:
            tbl->setItem(i, 0, new QTableWidgetItem(obj_el["Название"].toString()));
            tbl->setItem(i, 1, new QTableWidgetItem(obj_el["Количество"].toString()));
            tbl->setItem(i, 2, new QTableWidgetItem(obj_el["Водоизмещение"].toString()));
            tbl->setItem(i, 3, new QTableWidgetItem(obj_el["Торпеды"].toString()));
            tbl->setItem(i, 4, new QTableWidgetItem(obj_el["Ракеты"].toString()));
        }
    }
    file.close(); // На этом всё!
}
