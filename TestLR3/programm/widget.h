#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <another_win.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

//! Класс окна для вывода из файла
/*!
  Предоставляет возможность выводить данные из файлов
*/
class Widget : public QWidget
{
    Q_OBJECT

public:
    //! Конструктор окна
    /*!
      \param parent Родительский виджет
    */
    Widget(QWidget *parent = nullptr);

    //! Метод для чтения данных из файла
    void GetFileText();

    //! Деструктор класса
    ~Widget();

private slots:
    //! Слот для открытия второго окна
    void on_pushButton_clicked();

    //! Слот для выбора файла и чтения данных
    void on_pushButton_2_clicked();

    //! Слот для закрытия приложения
    void on_pushButton_3_clicked();

private:
    Ui::Widget *ui;        /*!< Указатель на интерфейс */
    QString Filepath;      /*!< Путь к выбранному файлу */
    Another_win *twin;     /*!< Указатель на объект дополнительного окна */
};
#endif // WIDGET_H
