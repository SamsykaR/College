#ifndef ANOTHER_WIN_H
#define ANOTHER_WIN_H

#include <QWidget>

namespace Ui {
class Another_win;
}

//! Класс окна для ввода данных
/*!
    Предоставляет возможность вводить значения в файл
*/
class Another_win : public QWidget
{
    Q_OBJECT

public:
    //! Конструктор окна
    /*!
      \param parent Родительский виджет
    */
    explicit Another_win(QWidget *parent = nullptr);
    //! Деструктор класса
    ~Another_win();

signals:
    //! Сигнал для запроса отображения первого окна
    void firstWindow();

private slots:
    //! Слот для обработки нажатия кнопки возврата в основное окно
    void on_pushButton_clicked();

    //! Слот для обработки нажатия кнопки записи данных в файл
    void on_pushButton_2_clicked();

    //! Слот для обработки нажатия кнопки очистки полей ввода
    void on_pushButton_3_clicked();

    //! Слот для обработки нажатия кнопки закрытия окна
    void on_pushButton_4_clicked();

private:
    Ui::Another_win *ui; /*!< Указатель на интерфейс */
};

#endif // ANOTHER_WIN_H
