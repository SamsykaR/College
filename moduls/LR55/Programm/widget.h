#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <another_win.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    void GetFileText();
    ~Widget();

// Слот от кнопки главного окна
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::Widget *ui;
    QString Filepath;
    // Второе окно
    Another_win *twin;
};
#endif // WIDGET_H
