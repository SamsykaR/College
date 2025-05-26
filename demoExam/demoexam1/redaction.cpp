#include "redaction.h"
#include "myexceptions.h"
#include <QSqlError>

/// \def Redaction(parents)
/// \brief Конструктор для окна редактирования записей
///
/// \param parent Родительский виджет
Redaction::Redaction(QWidget *parent)
    : QWidget{parent}
{
    resize(800, 540);
    setStyleSheet("QLineEdit { background-color: #FFFFFF; color: black; border: 2px solid #67BA80; }"
                  "QTextEdit { background-color: #FFFFFF; color: black; border: 2px solid #67BA80; }");
    lbl = new QLabel("Это окно для редактирования партнеров");
    lbl->setAlignment(Qt::AlignTop | Qt::AlignCenter);
    lbl->setStyleSheet("font-size: 24px;"
                       "font-weight:bold;");
    vbox = new QVBoxLayout(this);

    vbox->addWidget(lbl);

    typeLbl    = new QLabel("Тип: ");
    nameLbl    = new QLabel("Название: ");
    addressLbl = new QLabel("Юридический адрес: ");
    innLbl     = new QLabel("ИНН: ");
    fioLbl     = new QLabel("ФИО директора: ");
    telLbl     = new QLabel("Телефон: ");
    emailLbl   = new QLabel("Email: ");
    ratLbl     = new QLabel("Райтинг: ");
    prodLbl    = new QLabel("История реализации: ");

    typeEdit = new QLineEdit();
    nameEdit = new QLineEdit();
    addressEdit = new QTextEdit();
    innEdit = new QLineEdit();
    fioEdit = new QLineEdit();
    telEdit = new QLineEdit();
    emailEdit = new QLineEdit();
    ratEdit   = new QLineEdit();
    //prodEdit  = new QLineEdit();

    typeComboBox = new QComboBox;
    nextButton = new QPushButton("&Вперед");
    previousButton = new QPushButton("&Назад");
    redactButton = new QPushButton("&Изменить");
    clearButton = new QPushButton("&Очистить");
    addButton = new QPushButton("&Добавить");

    layout = new QGridLayout();
    layout->addWidget(typeLbl, 0, 0, 1, 1);
    layout->addWidget(typeEdit, 0, 1, 1, 1);
    layout->addWidget(previousButton, 0, 2, 1, 1);

    layout->addWidget(nameLbl, 1, 0, 1, 1);
    layout->addWidget(nameEdit, 1, 1, 1, 1);
    layout->addWidget(nextButton, 1, 2, 1, 1);

    layout->addWidget(addressLbl, 2, 0, 1, 1);
    layout->addWidget(addressEdit, 2, 1, 1, 1);
    layout->addWidget(redactButton, 2, 2, 1, 1);

    layout->addWidget(innLbl, 3, 0, 1, 1);
    layout->addWidget(innEdit, 3, 1, 1, 1);
    layout->addWidget(clearButton, 3, 2, 1, 1);

    layout->addWidget(fioLbl, 4, 0, 1, 1);
    layout->addWidget(fioEdit, 4, 1, 1, 1);
    layout->addWidget(addButton, 4, 2, 1, 1);

    layout->addWidget(telLbl, 5, 0, 1, 1);
    layout->addWidget(telEdit, 5, 1, 1, 1);

    layout->addWidget(emailLbl, 6, 0, 1, 1);
    layout->addWidget(emailEdit, 6, 1, 1, 1);

    layout->addWidget(ratLbl, 7, 0, 1, 1);
    layout->addWidget(ratEdit, 7, 1, 1, 1);

    //layout->addWidget(prodLbl, 0, 16, 1, 1);
    //layout->addWidget(prodEdit, 0, 17, 1, 1);
    //layout->addWidget(previousButton, 0, 18, 1, 1);
    // Продолжить заполнение грида
    //...

    vbox->addLayout(layout);
    //vbox->setStretch(0, 0);
    //vbox->setStretch(1, 1);
    //vbox->setStretchFactor(layout, 5);

    setLayout(vbox);

    // Соединяемся с базой данных
    try{
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("./res/database");
        if (!db.open()) {
            throw myExceptions::dbOpenException("Невозможно открыть базу данных. \nПроверьте путь");
            qDebug() << "Невозможно открыть db!";
        } else {
            qDebug() << "Соединение с DB установлено!";
        }

        // Создаем модель для работы с одной таблицей
        model = new QSqlTableModel();
        model->setTable("Partners"); // конкретно с этой
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);
        model->select();

        typeComboBox->setModel(model);
        typeComboBox->setModelColumn(model->fieldIndex("Наименование партнера"));
        typeComboBox->setCurrentIndex(0);

        mapper = new QDataWidgetMapper;
        mapper->setModel(model);
        mapper->addMapping(typeComboBox, model->fieldIndex("Наименование партнера"));
        mapper->addMapping(typeEdit,    0);
        mapper->addMapping(nameEdit,    1);
        mapper->addMapping(fioEdit,     2);
        mapper->addMapping(emailEdit,   3);
        mapper->addMapping(telEdit,     4);
        mapper->addMapping(addressEdit, 5);
        mapper->addMapping(innEdit,     6);
        mapper->addMapping(ratEdit,     7);

        connect(previousButton, &QPushButton::clicked, mapper, &QDataWidgetMapper::toPrevious);
        connect(nextButton, &QPushButton::clicked, mapper, &QDataWidgetMapper::toNext);
        connect(clearButton, &QPushButton::clicked, this, &Redaction::ClearBtn_clicked);
        connect(addButton, &QPushButton::clicked, this, &Redaction::AddBtn_clicked);
        connect(redactButton, &QPushButton::clicked, this, &Redaction::RedactBtn_clicked);

        connect(mapper, &QDataWidgetMapper::currentIndexChanged, this, &Redaction::updateButtons);
        connect(typeComboBox, SIGNAL(activated(int)), this, SLOT(partChoose()));

        mapper->toFirst();
    }
    catch(myExceptions::queryReadException& ex){
        QMessageBox::critical(0, tr("Проблемы с запросом"), ex.getMessage(), QMessageBox::Cancel);
    }
    catch(std::exception& ex){
        QMessageBox::critical(0, tr("Проблемы"), ex.what(), QMessageBox::Cancel);
    }
}


/// \def updateButtons(row)
/// \brief Обновляет состояние кнопок навигации
///
/// \param row Текущий индекс строки в таблице
void Redaction::updateButtons(int row)
{
    previousButton->setEnabled(row > 0);
    nextButton->setEnabled(row < model->rowCount() - 1);
}

/// \def partChoose()
/// \brief Обрабатывает выбор элемента в комбобоксе
///
/// Синхронизирует карту с выбранной позицией
void Redaction::partChoose()
{
    mapper->setCurrentIndex(typeComboBox->currentIndex());
}

/// \def ClearBtn_clicked()
/// \brief Очищает все поля ввода
void Redaction::ClearBtn_clicked()
{
    typeEdit->clear();
    nameEdit->clear();
    fioEdit->clear();
    emailEdit->clear();
    telEdit->clear();
    addressEdit->clear();
    innEdit->clear();
    ratEdit->clear();
}

/// \def AddBtn_clicked()
/// \brief Добавляет новую запись в БД
///
/// Проверяет обязательные поля, формирует запись, обрабатывает ошибки при вставке данных
void Redaction::AddBtn_clicked()
{
    try {
            if(nameEdit->text().isEmpty() || innEdit->text().isEmpty()) {
                throw myExceptions::dbOpenException("Заполните обязательные поля: Название и ИНН");
            }
            record = model->record();
            record.setValue(0, typeEdit->text());
            record.setValue(1, nameEdit->text());
            record.setValue(2, fioEdit->text());
            record.setValue(3, emailEdit->text());
            record.setValue(4, telEdit->text());
            record.setValue(5, addressEdit->toPlainText());
            record.setValue(6, innEdit->text());
            record.setValue(7, ratEdit->text());

            if(!model->insertRecord(model->rowCount(), record)) {
                throw myExceptions::queryReadException("Ошибка добавления записи: ", model->lastError().text());
            }

            if(!model->submitAll()) {
                throw myExceptions::queryReadException("Ошибка сохранения: ", model->lastError().text());
            }

            model->select();
            mapper->toLast();
            QMessageBox::information(this, "Успех", "Запись успешно добавлена!");
        }
    catch(myExceptions::dbOpenException& ex){
        QMessageBox::critical(0, tr("Проблемы с базой данных"), ex.getMessage(), QMessageBox::Cancel);
    }
    catch(myExceptions::queryReadException& ex){
        QMessageBox::critical(0, tr("Проблемы с запросом"), ex.getMessage(), QMessageBox::Cancel);
    }
    catch(std::exception& ex){
        QMessageBox::critical(0, tr("Проблемы"), ex.what(), QMessageBox::Cancel);
    }
}

/// \def RedactBtn_clicked()
/// \brief Сохраняет изменения в текущей записи
void Redaction::RedactBtn_clicked()
{
    try {
        mapper->submit();
        if(!model->submitAll()) {
            throw myExceptions::queryReadException("Ошибка сохранения: ", model->lastError().text());
        }
        QMessageBox::information(this, "Успех", "Изменения сохранены!");
        model->select();
    }
    catch(myExceptions::queryReadException& ex){
        QMessageBox::critical(0, tr("Проблемы с запросом"), ex.getMessage(), QMessageBox::Cancel);
    }
    catch(std::exception& ex){
        QMessageBox::critical(0, tr("Проблемы"), ex.what(), QMessageBox::Cancel);
    }
}
