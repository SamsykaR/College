#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFile>

#include <downloader.h>

namespace Ui {
class Widget;
}
/// \class Widget
/// \brief Главное окно приложения
class Widget : public QWidget
{
    Q_OBJECT

public:
    /// \brief Конструктор виджета
    /// \param parent Родительский виджет (по умолчанию nullptr)
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    /// \brief Слот для чтения данных из файла
    void readFile();

private:
    Ui::Widget *ui;             /*!< Указатель на интерфейс */
    Downloader *downloader;     /*!< Объект для скачивания данных по HTTP */
    /// \brief Метод для форматирования текста с курсами валют
    /// \param text Исходный JSON-текст с данными о валютах
    /// \return Отформатированная строка с информацией о валютах
    QString redactText(QString);
};

#endif // WIDGET_H
