#include "winchart.h"

Winchart::Winchart(QWidget *parent)
    : QWidget{parent}
{
    resize(800, 600);
    lblhd = new QLabel();
    lblhd->setText("Визуализация данных");
    lblhd->setAlignment(Qt::AlignTop | Qt::AlignCenter);
    lblhd->setStyleSheet("font-size: 32px;"
                         "font-weight:bold;");
    // Настройки гистограммы
    chart     = new QChart();          // Диаграмма (в первом приближении - это модель),
    chartView = new QChartView(chart); // а это её представление
    chartView->setRenderHint(QPainter::Antialiasing);

    vbox = new QVBoxLayout();
    vbox->addWidget(lblhd);
    vbox->addWidget(chartView); // Добавляем не чарт, а его представление

    btn1 = new QPushButton("Загрузить данные");
    hbox = new QHBoxLayout();
    hbox->addWidget(btn1);
    hbox->addStretch();

    vbox->addLayout(hbox);
    setLayout(vbox);

    connect(btn1, &QPushButton::clicked, this, &Winchart::on_btn1_clicked);
}

void Winchart::on_btn1_clicked()
{
    if (axisX || axisY) // Ругется (но не сильно) в консоли, что удаляются несуществующие оси
    {                   // Не придумал как удалить все, в случае повторного нажатия
        chart->removeAllSeries(); // остановился на этом решении
        chart->removeAxis(axisX);
        chart->removeAxis(axisY);
    }
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
        // И бросаем исключение в случае ошибки!!!
        obj = doc.object();
        arr = obj["Submarines"].toArray();
        qint32 size = arr.count(); // Получили размер массива

        rocket = new QBarSet("Ракеты");  // набор столбцов в гистограмме
        torped = new QBarSet("Торпеды"); // другой набор
        series = new QBarSeries(); // отображает данные в виде серии столбцов, сгруппированных по
        // категориям, с одним столбцом на категорию из каждого набора столбцов, добавленного в серию.
        // Он также поддерживает горизонтальные столбцы и группировку столбцов в виде стопки.
        axisX  = new QBarCategoryAxis();  // Добавляет категории к осям графика.
        for (int i = 0; i < size; i++) {  // Распаковываем элементы массива
            const QJsonValue elem = arr.at(i);
            obj_el = elem.toObject();
            QString roc = obj_el["Ракеты"].toString();   // Многоходовка
            QString tor = obj_el["Торпеды"].toString();  // для получения преобразования
            categories << obj_el["Название"].toString(); // (здесь остается строка)
            *rocket << roc.toDouble();                   // из QString -> Double
            *torped << tor.toDouble();     // Разыменование указателя - в норме!
        }
        series->append(rocket);  // 1-й эл-т серии
        series->append(torped);  // 2-й эл-т
        chart->addSeries(series);// устанавливаем серию в чарт
        chart->setAnimationOptions(QChart::SeriesAnimations); // плавный рост столбцов
        axisX->append(categories); // устанавливаем категории на ось Х
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);
        axisY = new QValueAxis();
        axisY->setRange(0, 60); // ранжироване значений по оси Y
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);
        chart->legend()->setVisible(true); // показать легенду
        chart->legend()->setAlignment(Qt::AlignRight);
    }
    file.close(); // На этом всё!
}
