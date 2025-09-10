#ifndef WINOUT_H
#define WINOUT_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QJsonParseError>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class Winout : public QWidget
{
    Q_OBJECT
public:
    explicit Winout(QWidget *parent = nullptr);

private:
    QVBoxLayout *vbox;
    QGridLayout *grid;
    QHBoxLayout *hbox;
    QLabel      *lblhd;
    QLabel      *lbl1;
    QLabel      *lbl2;
    QLabel      *lbl3;
    QLabel      *lbl4;
    QLabel      *lbl5;
    QLineEdit   *ledit1;
    QLineEdit   *ledit2;
    QLineEdit   *ledit3;
    QLineEdit   *ledit4;
    QLineEdit   *ledit5;
    QPushButton *btnclr;
    QPushButton *btnadd;

private slots:
    void on_btnadd_clicked();
    void on_btnclr_clicked();

signals:
};

#endif // WINOUT_H
