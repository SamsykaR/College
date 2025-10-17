#ifndef REDACT_H
#define REDACT_H
#include <QWidget>
#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QLabel>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>
#include <QDataWidgetMapper>
#include <QSqlRecord>

/// \brief Класс окна редактирования записей
///
/// Предоставляет интерфейс для добавления, редактирования и навигации по записям в таблице Foods
class redact : public QWidget
{
    Q_OBJECT
public:
    /// \brief Конструктор класса
    /// \param parent родительский виджет
    redact(QWidget *parent = nullptr);

    /// \brief Загрузка данных текущей записи
    ///
    /// Загружает данные из базы данных для текущего индекса и отображает их в полях ввода
    void LoadData();

private:
    QLabel* headerLabel;         ///< Заголовок окна
    QHBoxLayout *hbox;           ///< Горизонтальный макет
    QVBoxLayout *vbox;           ///< Вертикальный макет

    QLabel *IdLbl;               ///< Поле с ID
    QLabel *CategoryLbl;         ///< Поле с категорией
    QLabel *NameLbl;             ///< Поле с названием
    QLabel *CostLbl;             ///< Поле с ценой
    QLabel *DescriptionLbl;      ///< Поле с описанием
    QLabel* infoLabel;           ///< Поле для информации

    QLineEdit *IdEdit;           ///< Поле ввода ID
    QLineEdit *CategoryEdit;     ///< Поле ввода категории
    QLineEdit *NameEdit;         ///< Поле ввода названия
    QLineEdit *CostEdit;         ///< Поле ввода цены
    QLineEdit *DescriptionEdit;  ///< Поле ввода описания

    QComboBox   *typeComboBox;   ///< Комбо-бокс
    QPushButton *nextButton;     ///< Кнопка следующей записи
    QPushButton *previousButton; ///< Кнопка предыдущей записи
    QPushButton *redactButton;   ///< Кнопка редактирования
    QPushButton *clearButton;    ///< Кнопка очистки
    QPushButton *addButton;      ///< Кнопка добавления

    QGridLayout *layout;         ///< Сеточный макет
    QHBoxLayout* headerLayout;   ///< Макет заголовка

    QSqlDatabase db;             ///< Подключение к БД
    QLabel* logotype;            ///< Логотип программы

    /// \brief Добавление новой записи
    void Add();

    /// \brief Редактирование текущей записи
    void Redact();

    /// \brief Очистка полей ввода
    void Clear();

    /// \brief Переход к следующей записи
    void Next();

    /// \brief Переход к предыдущей записи
    void Previous();
};

#endif // REDACT_H
