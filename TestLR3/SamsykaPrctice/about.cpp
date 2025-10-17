#include "about.h"

about::about(QWidget *parent)
    : QWidget{parent}
{

    QVBoxLayout *mainLayout = new QVBoxLayout();

    headerLayout = new QHBoxLayout();
    logotype = new QLabel();
    logotype->setPixmap(QPixmap("../../pic/logo.png").scaledToWidth(80));
    headerLabel = new QLabel("О программе");
    headerLabel->setStyleSheet("font-size: 25px;");
    headerLayout->addWidget(logotype);
    headerLayout->addStretch();
    headerLayout->addWidget(headerLabel);

    mainLayout->addLayout(headerLayout);

    informationlbl = new QLabel("Версия: 1.0 "
                                "\nТаблицы: "
                                "\n  Users(Id, login, password) "
                                "\n  Foods(Id, Name, Category, Cost, Description)"
                                "\nАвтор:"
                                "\n  Самсыка Р.М.");

    mainLayout->addWidget(informationlbl);

    setLayout(mainLayout);
}
