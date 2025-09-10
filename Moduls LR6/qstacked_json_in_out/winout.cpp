#include "winout.h"

Winout::Winout(QWidget *parent)
    : QWidget{parent}
{
    resize(800, 600);
    lblhd = new QLabel();
    lblhd->setText("Ввод данных в файл JSON");
    lblhd->setAlignment(Qt::AlignTop | Qt::AlignCenter);
    lblhd->setStyleSheet("font-size: 32px;"
                         "font-weight:bold;");
    vbox = new QVBoxLayout();
    vbox->addWidget(lblhd);

    grid = new QGridLayout(); // Табличная компоновка
    grid->maximumSize();
    // Элементы для компоновки
    lbl1 = new QLabel();    lbl1->setText("Название: ");
    lbl2 = new QLabel();    lbl2->setText("Количество: ");
    lbl3 = new QLabel();    lbl3->setText("Водоизмещение: ");
    lbl4 = new QLabel();    lbl4->setText("Торпеды: ");
    lbl5 = new QLabel();    lbl5->setText("Ракеты: ");

    ledit1 = new QLineEdit();   ledit1->setText("");
    ledit2 = new QLineEdit();   ledit2->setText("");
    ledit3 = new QLineEdit();   ledit3->setText("");
    ledit4 = new QLineEdit();   ledit4->setText("");
    ledit5 = new QLineEdit();   ledit5->setText("");

    btnadd = new QPushButton("&Добавить");
    btnclr = new QPushButton("&Очистить");

    grid->addWidget(lbl1,   0, 0, 1, 1); // Компонуем
    grid->addWidget(ledit1, 0, 1, 1, 1);
    grid->addWidget(lbl2,   1, 0, 1, 1);
    grid->addWidget(ledit2, 1, 1, 1, 1);
    grid->addWidget(lbl3,   2, 0, 1, 1);
    grid->addWidget(ledit3, 2, 1, 1, 1);
    grid->addWidget(lbl4,   3, 0, 1, 1);
    grid->addWidget(ledit4, 3, 1, 1, 1);
    grid->addWidget(lbl5,   4, 0, 1, 1);
    grid->addWidget(ledit5, 4, 1, 1, 1);

    vbox->addLayout(grid);

    hbox = new QHBoxLayout();
    hbox->addStretch(); // Пружина
    hbox->addWidget(btnadd);
    hbox->addWidget(btnclr);

    vbox->addLayout(hbox);
    vbox->addStretch();

    setLayout(vbox); // Конец оформления окна
    // Соединение в новом стиле
    connect(btnadd, &QPushButton::clicked, this, &Winout::on_btnadd_clicked);
    connect(btnclr, &QPushButton::clicked, this, &Winout::on_btnclr_clicked);
}

// Слоты нажатия кнопок
void Winout::on_btnadd_clicked()
{
    QFile file;
    file.setFileName("./json/db.json");
    QString val;
    QJsonDocument doc; // Создаем JSON-документ
    // Сначала получаем данные из файла на случай,
    // если там уже имеется массив
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Ошибка! Файл недоступен для чтения!";
        // Выбрасываем исключение!!!
    } else {
        QTextStream json(&file); // Создаем файловый поток ввода
        val = json.readAll();
        QJsonParseError error;
        doc = QJsonDocument::fromJson(val.toUtf8(), &error); // Проверить error!!!
    }
    file.close();

    QJsonObject elObj; // Элемент массива (тоже является объектом)
    // Получаем значение элемента в полях
    elObj.insert("Название",       ledit1->text());
    elObj.insert("Количество",     ledit2->text());
    elObj.insert("Водоизмещение",  ledit3->text());
    elObj.insert("Торпеды",        ledit4->text());
    elObj.insert("Ракеты",         ledit5->text());

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Ошибка! Файл недоступен для записи!";
        // Выбрасываем исключение!!!
    } else {
        QTextStream json(&file); // Создаем файловый поток вывода
        QJsonObject obj;
        QJsonArray arr;
        QString jsonString;
        if (!doc.isObject()) {    // Если документ не содержит объекта (документ пуст),
            obj = doc.object();   // то мы его создаем,
            arr.push_back(elObj); // добавляем в массив наш элемент (он тоже объект),
            obj.insert("Submarines", arr); // добавляем массив оббъектов в объект документа
            doc.setArray(arr);
            doc.setObject(obj);
            jsonString = doc.toJson(QJsonDocument::Indented);
            json << jsonString; // Записываем в файл
        } else {                // Иначе
            obj = doc.object(); // получаем объект
            arr = obj["Submarines"].toArray(); // находим и вытаскиваем массив
            arr.push_back(elObj);              // пушбачим
            obj.insert("Submarines", arr);     // возвращаем обратно в объект
            doc.setArray(arr);
            doc.setObject(obj);
            jsonString = doc.toJson(QJsonDocument::Indented);
            json << jsonString; // и записываем (перезаписываем, если точнее)
        }
    }
    file.close(); // На этом всё!
}

void Winout::on_btnclr_clicked()
{
    ledit1->setText("");
    ledit2->setText("");
    ledit3->setText("");
    ledit4->setText("");
    ledit5->setText("");
}
