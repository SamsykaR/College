#ifndef WININ_H
#define WININ_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableWidget>
#include <QPushButton>
#include <QJsonParseError>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QLabel>

class Winin : public QWidget
{
    Q_OBJECT
public:
    explicit Winin(QWidget *parent = nullptr);

private:
    QVBoxLayout *vbox;
    QTableWidget *tbl;
    QHBoxLayout *hbox;
    QPushButton *btn1;
    QLabel      *lblhd;

private slots:
    void on_btn1_clicked();

signals:
};

#endif // WININ_H
