/// \file mainwidget.h
/// \brief Заголовочный файл главного виджета

#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "doublelinkedlist.h"

namespace Ui {
class MainWidget;
}

/// \class MainWidget
/// \brief Главный виджет приложения
///
/// Наследует QWidget и реализует логику взаимодействия с двусвязным списком
class MainWidget : public QWidget {
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private slots:
    void load();                /*!< Загружает данные из файла */
    void save();                /*!< Сохраняет данные в файл */
    void itemChanged();         /*!< Обрабатывает изменение данных в таблице */
    void add();                 /*!< Добавляет нового пациента */
    void rem();                 /*!< Удаляет пациента по полису */
    void update_table_data();   /*!< Обновляет таблицу с учетом фильтров */

private:
    Ui::MainWidget *ui;         /*!< Указатель на интерфейс */
    list_nsp::DoubleLinkedList list; /*!< Двусвязный список пациентов */
};

#endif // MAINWIDGET_H
