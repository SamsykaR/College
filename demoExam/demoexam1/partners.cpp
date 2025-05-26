#include "partners.h"
#include "myexceptions.h"
#include <QTableView>
#include <QSqlTableModel>
#include <QScrollArea>
#include <QMessageBox>

/// \def Partners(parents)
/// \brief Конструктор для окна с выводом партнёров
///
/// \param parent Родительский виджет
Partners::Partners(QWidget *parent)
    : QWidget{parent}
{
    resize(800, 540);
    setStyleSheet("background-color: #F4E8D3; color: black; border: 2px solid #67BA80;");
    lbl = new QLabel();
    lbl->setAlignment(Qt::AlignTop | Qt::AlignCenter);
    lbl->setStyleSheet("font-size: 24px;"
                       "font-weight:bold;");
    vbox = new QVBoxLayout();

    try{
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("./res/database");
        if(!db.open()){
            throw myExceptions::dbOpenException("Невозможно открыть базу данных. \nПроверьте путь");
        };
        QSqlQuery querry;
        if(!querry.exec("SELECT * FROM Partners")){
            throw myExceptions::queryReadException("Запрос не читается", "Таблица Partners");
        }
        while(querry.next()){
            QLabel *lab = new QLabel();
            lab->setText(QString("<big>%1 | %2  %3 "
                                 "<br>%4 <br>%5 <br>Рейтинг: %6")
                             .arg(querry.value(0).toString())
                             .arg(querry.value(1).toString())
                             .arg("10%")
                             .arg(querry.value(2).toString())
                             .arg(querry.value(4).toString())
                             .arg(querry.value(7).toString()));
            vbox->addWidget(lab);
        }
        db.close();
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
    setLayout(vbox);
}
