/// \file mainwidget.cpp
/// \brief Реализация главного виджета приложения

#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QFileDialog>
#include <QFile>
#include <QString>
#include <QMessageBox>

/// \brief Конструктор главного виджета
/// \param parent Родительский виджет (по умолчанию nullptr)
MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget) {
    ui->setupUi(this);
    list_nsp::init(list);

    // Настройка соединений сигналов и слотов
    connect(ui->load, SIGNAL(clicked()), SLOT(load()));
    connect(ui->save, SIGNAL(clicked()), SLOT(save()));
    connect(ui->add, SIGNAL(clicked()), SLOT(add()));
    connect(ui->rem, SIGNAL(clicked()), SLOT(rem()));
    connect(ui->find, SIGNAL(clicked()), SLOT(update_table_data()));
    connect(ui->tableWidget, SIGNAL(itemChanged(QTableWidgetItem*)), this, SLOT(itemChanged()));
}

/// \brief Деструктор главного виджета
///
/// Освобождает ресурсы, связанные с интерфейсом
MainWidget::~MainWidget() {
    delete ui;
}

/// \brief Добавляет нового пациента в список
///
/// Считывает данные из полей ввода. Если все поля заполнены, создает объект Patient и добавляет его в конец списка.
void MainWidget::add() {
    Patient patient(
        ui->add_policy->text(),
        ui->add_name->text(),
        ui->add_section->text(),
        ui->add_doctor->text()
        );

    // Проверка на пустые поля
    if (patient.name.isEmpty() || patient.doctor.isEmpty() ||
        patient.policy.isEmpty() || patient.section.isEmpty()) {
        return;
    }

    list_nsp::push_back(list, patient);
    update_table_data();
}

/// \brief Удаляет пациента по номеру полиса
///
/// Ищет узел с указанным полисом и удаляет его из списка.
void MainWidget::rem() {
    QString policy = ui->rem_policy->text();
    list_nsp::Node* node = list.first;

    // Поиск узла с заданным полисом
    while (node != nullptr) {
        if (node->value.policy == policy) break;
        node = node->next;
    }

    if (node == nullptr) return;
    list_nsp::remove(list, node);
    update_table_data();
}

/// \brief Обрабатывает изменение данных в таблице
///
/// Обновляет данные в списке при редактировании ячеек таблицы.
void MainWidget::itemChanged() {
    int nrow = ui->tableWidget->currentIndex().row();
    if (nrow < 0) return;

    list_nsp::Node* node = list_nsp::nth0(list, nrow);
    if (node == nullptr) return;

    // Обновление данных из таблицы
    node->value.policy = ui->tableWidget->item(nrow, 0)->text();
    node->value.name = ui->tableWidget->item(nrow, 1)->text();
    node->value.section = ui->tableWidget->item(nrow, 2)->text();
    node->value.doctor = ui->tableWidget->item(nrow, 3)->text();
}

/// \brief Обновляет таблицу с учетом фильтров
///
/// Очищает таблицу и заполняет её данными из списка, применяя фильтры к полям пациента.
void MainWidget::update_table_data() {
    // Очистка таблицы
    while (ui->tableWidget->rowCount() > 0) {
        ui->tableWidget->removeRow(0);
    }

    list_nsp::Node* node = list.first;
    int nrow = 0;

    // Получение значений фильтров
    QString filter_policy = ui->find_policy->text();
    QString filter_name = ui->find_name->text();
    QString filter_doctor = ui->find_doctor->text();
    QString filter_section = ui->find_section->text();

    // Фильтрация и заполнение таблицы
    while (node != nullptr) {
        if (
            node->value.policy.indexOf(filter_policy) < 0 ||
            node->value.name.indexOf(filter_name) < 0 ||
            node->value.doctor.indexOf(filter_doctor) < 0 ||
            node->value.section.indexOf(filter_section) < 0
            ) {
            node = node->next;
            continue;
        }

        // Добавление строки в таблицу
        ui->tableWidget->insertRow(nrow);
        ui->tableWidget->setItem(nrow, 0, new QTableWidgetItem(node->value.policy));
        ui->tableWidget->setItem(nrow, 1, new QTableWidgetItem(node->value.name));
        ui->tableWidget->setItem(nrow, 2, new QTableWidgetItem(node->value.section));
        ui->tableWidget->setItem(nrow, 3, new QTableWidgetItem(node->value.doctor));

        nrow++;
        node = node->next;
    }
}

/// \brief Загружает данные из файла
///
/// Открывает диалог выбора файла и загружает данные в список.
void MainWidget::load() {
    QString path = QFileDialog::getOpenFileName(0, "Выбери файл с данными", "", "*.txt");
    if (path.isEmpty()) return;

    QFile file(path);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл");
        return;
    }

    QTextStream stream(&file);
    list_nsp::load(stream, list);
    update_table_data();
    file.close();
}

/// \brief Сохраняет данные в файл
///
/// Открывает диалог выбора файла и сохраняет данные из списка.
void MainWidget::save() {
    QString path = QFileDialog::getSaveFileName(0, "Выбери место сохранения", "", "*.txt");
    if (path.isEmpty()) return;

    QFile file(path);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось создать файл");
        return;
    }

    QTextStream stream(&file);
    list_nsp::save(stream, list);
    file.close();
}
