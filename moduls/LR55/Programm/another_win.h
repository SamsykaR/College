#ifndef ANOTHER_WIN_H
#define ANOTHER_WIN_H

#include <QWidget>

namespace Ui {
class Another_win;
}

class Another_win : public QWidget
{
    Q_OBJECT

public:
    explicit Another_win(QWidget *parent = nullptr);
    ~Another_win();

signals:
    void firstWindow(); // Сигнал для первого окна на открытие

private slots:
    // Слот-обработчик нажатия кнопки открытия окна
    void on_pushButton_clicked();
    // Слот-обработчик нажатия кнопки записи данных в файл
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();

private:
    Ui::Another_win *ui;
};

#endif // ANOTHER_WIN_H
