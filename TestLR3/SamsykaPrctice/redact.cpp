#include "redact.h"
#include "global.h"
#include <QSqlError>
#include <QDebug>
#include <QHostInfo>
#include <QTimer>

redact::redact(QWidget *parent)
    : QWidget{parent}
{
    vbox = new QVBoxLayout(this);
    hbox = new QHBoxLayout();

    logotype = new QLabel();
    logotype->setPixmap(QPixmap("../../pic/logo.png").scaledToWidth(80));
    headerLabel = new QLabel("Редактирование и \nдобавление записей");
    headerLabel->setStyleSheet("font-size: 25px;");
    headerLayout = new QHBoxLayout();
    headerLayout->addWidget(logotype);
    headerLayout->addStretch();
    headerLayout->addWidget(headerLabel);


    vbox->addLayout(headerLayout);

    IdLbl               = new QLabel("ID: ");
    CategoryLbl         = new QLabel("Категория: ");
    NameLbl             = new QLabel("Название: ");
    CostLbl             = new QLabel("Цена: ");
    DescriptionLbl      = new QLabel("Описание: ");
    infoLabel = new QLabel();

    IdLbl->setStyleSheet("font-size: 16px;");
    CategoryLbl->setStyleSheet("font-size: 16px;");
    NameLbl->setStyleSheet("font-size: 16px;");
    CostLbl->setStyleSheet("font-size: 16px;");
    DescriptionLbl->setStyleSheet("font-size: 16px;");

    IdEdit = new QLineEdit();
    CategoryEdit = new QLineEdit();
    NameEdit = new QLineEdit();
    CostEdit = new QLineEdit();
    DescriptionEdit = new QLineEdit();

    IdEdit->setStyleSheet("font-size: 18px;");
    CategoryEdit->setStyleSheet("font-size: 18px;");
    NameEdit->setStyleSheet("font-size: 18px;");
    CostEdit->setStyleSheet("font-size: 18px;");
    DescriptionEdit->setStyleSheet("font-size: 18px;");

    QDoubleValidator* costValidator = new QDoubleValidator(this);
    costValidator->setBottom(0);
    costValidator->setDecimals(2);
    CostEdit->setValidator(costValidator);

    typeComboBox = new QComboBox;
    nextButton = new QPushButton("&Вперед");
    previousButton = new QPushButton("&Назад");
    redactButton = new QPushButton("&Изменить");
    clearButton = new QPushButton("&Очистить");
    addButton = new QPushButton("&Добавить");

    nextButton->setStyleSheet("font-size: 16px;");
    previousButton->setStyleSheet("font-size: 16px;");
    redactButton->setStyleSheet("font-size: 16px;");
    clearButton->setStyleSheet("font-size: 16px;");
    addButton->setStyleSheet("font-size: 16px;");

    layout = new QGridLayout();
    layout->addWidget(IdLbl, 0, 0, 1, 1);
    layout->addWidget(IdEdit, 0, 1, 1, 1);
    layout->addWidget(previousButton, 0, 2, 1, 1);

    layout->addWidget(CategoryLbl, 1, 0, 1, 1);
    layout->addWidget(CategoryEdit, 1, 1, 1, 1);
    layout->addWidget(nextButton, 1, 2, 1, 1);

    layout->addWidget(NameLbl, 2, 0, 1, 1);
    layout->addWidget(NameEdit, 2, 1, 1, 1);
    layout->addWidget(addButton, 2, 2, 1, 1);

    layout->addWidget(CostLbl, 4, 0, 1, 1);
    layout->addWidget(CostEdit, 4, 1, 1, 1);
    layout->addWidget(redactButton, 4, 2, 1, 1);

    layout->addWidget(DescriptionLbl, 3, 0, 1, 1);
    layout->addWidget(DescriptionEdit, 3, 1, 1, 1);
    layout->addWidget(clearButton, 3, 2, 1, 1);


    vbox->addLayout(layout);
    vbox->addWidget(infoLabel);

    setLayout(vbox);


    connect(addButton, &QPushButton::clicked, this, &redact::Add);
    connect(redactButton, &QPushButton::clicked, this, &redact::Redact);
    connect(clearButton, &QPushButton::clicked, this, &redact::Clear);
    connect(nextButton, &QPushButton::clicked, this, &redact::Next);
    connect(previousButton, &QPushButton::clicked, this, &redact::Previous);
}


void redact::Add(){
    QTimer::singleShot(6000, [this]() {
        infoLabel->clear();
    });
    if(CategoryEdit->text()=="" || NameEdit->text()=="" || CostEdit->text()=="" || DescriptionEdit->text()==""){
        infoLabel->setStyleSheet("font-size: 14px; color: brown");
        infoLabel->setText("Заполните все поля");
        return;
    }

    QSqlQuery Querry(GlobalClass::db());
    QString SQLQuerry = QString("INSERT INTO Foods(Category, Name, Cost, Description) VALUES('%1', '%2', %3, '%4');")
                            .arg(CategoryEdit->text())
                            .arg(NameEdit->text())
                            .arg(CostEdit->text())
                            .arg(DescriptionEdit->text());
    Querry.exec(SQLQuerry);
    SQLQuerry = QString("SELECT COUNT(*) FROM Foods;");
    Querry.exec(SQLQuerry);
    int count = 0;
    if(Querry.next())
        count = Querry.value(0).toInt();
    GlobalClass::CurentIndex = count;
    infoLabel->setStyleSheet("font-size: 14px; color: green");
    infoLabel->setText("Запись добавлена");
    LoadData();
}

void redact::Redact(){
    QTimer::singleShot(6000, [this]() {
        infoLabel->clear();
    });
    if(CategoryEdit->text()=="" || NameEdit->text()=="" || CostEdit->text()=="" || DescriptionEdit->text()==""){
        infoLabel->setStyleSheet("font-size: 14px; color: brown");
        infoLabel->setText("Заполните все поля");
        return;
    }
    QSqlQuery Querry(GlobalClass::db());
    QString SQLQuerry = QString("Update Foods SET Category = '%1', Name = '%2', Cost = %3, Description = '%4' WHERE Id = %5;")
                            .arg(CategoryEdit->text())
                            .arg(NameEdit->text())
                            .arg(CostEdit->text())
                            .arg(DescriptionEdit->text())
                            .arg(GlobalClass::CurentIndex);
    Querry.exec(SQLQuerry);
    infoLabel->setStyleSheet("font-size: 14px; color: green");
    infoLabel->setText("Запись обновлена");
    LoadData();
}

void redact::Clear(){
    IdEdit->clear();
    CategoryEdit->clear();
    NameEdit->clear();
    CostEdit->clear();
    DescriptionEdit->clear();
}

void redact::Next(){
    QTimer::singleShot(6000, [this]() {
        infoLabel->clear();
    });
    infoLabel->setStyleSheet("font-size: 14px; color: green");
    infoLabel->setText("Если записи не меняются, значит это \nпоследняя или у вас неправильно идёт индексация");
    QSqlQuery Querry(GlobalClass::db());
    QString SQLQuerry = QString("SELECT COUNT(*) FROM Foods;");
    Querry.exec(SQLQuerry);
    int count = 0;
    if(Querry.next())
        count = Querry.value(0).toInt();
    if(GlobalClass::CurentIndex<count)
        GlobalClass::CurentIndex +=1;
    LoadData();
}

void redact::Previous(){
    QTimer::singleShot(6000, [this]() {
        infoLabel->clear();
    });
    infoLabel->setStyleSheet("font-size: 14px; color: green");
    infoLabel->setText("Если записи не меняются, значит это \nпоследняя или у вас неправильно идёт индексация");
    if(GlobalClass::CurentIndex>1)
        GlobalClass::CurentIndex -=1;
    LoadData();
}

void redact::LoadData(){
    QSqlQuery Querry(GlobalClass::db());
    QString SQLQuerry = QString("SELECT * FROM Foods WHERE Id = %1;").arg(GlobalClass::CurentIndex);
    Querry.exec(SQLQuerry);
    if(GlobalClass::CurentIndex>0){
        if (!Querry.next()) {
            qDebug() << "Не получилось вывести данные";
            qDebug() << "Ошибка запроса:" << Querry.lastError().text();
            qDebug() << "Ошибка базы:" << db.lastError().text();
            qDebug() << "Запрос:" << SQLQuerry;
        } else {
            IdEdit->setText(Querry.value(0).toString());
            CategoryEdit->setText(Querry.value(1).toString());
            NameEdit->setText(Querry.value(2).toString());
            CostEdit->setText(Querry.value(3).toString());
            DescriptionEdit->setText(Querry.value(4).toString());
        }
    }
    else Clear();
}
