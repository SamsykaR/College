#ifndef WINCHART_H
#define WINCHART_H

#include <QWidget>
#include <QtCharts>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QJsonParseError>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QLabel>
#include <QStringList>

class Winchart : public QWidget
{
    Q_OBJECT
public:
    explicit Winchart(QWidget *parent = nullptr);

private:
    QVBoxLayout *vbox;
    QTableWidget *tbl;
    QHBoxLayout *hbox;
    QPushButton *btn1;
    QLabel      *lblhd;
    QBarSet     *rocket;
    QBarSet     *torped;
    QBarSeries  *series;
    QChart      *chart;
    QStringList categories;
    QBarCategoryAxis *axisX;
    QValueAxis       *axisY;
    QChartView  *chartView;

private slots:
    void on_btn1_clicked();

signals:
};

#endif // WINCHART_H
