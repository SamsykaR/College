#ifndef HOME_H
#define HOME_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

class Home : public QWidget
{
    Q_OBJECT
public:
    explicit Home(QWidget *parent = nullptr);

signals:

private:
    QLabel* lbl;
    QLabel* lblname;
    QLabel *icon;
    QVBoxLayout *vbox;
    QHBoxLayout *hbox;

};

#endif // HOME_H
