#ifndef PARTNERS_H
#define PARTNERS_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QSqlDatabase>
#include <QSqlQuery>

class Partners : public QWidget
{
    Q_OBJECT
public:
    explicit Partners(QWidget *parent = nullptr);

signals:

private:
    QLabel* lbl;
    QVBoxLayout *vbox;

};

#endif // PARTNERS_H
