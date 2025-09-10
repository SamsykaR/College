#ifndef WINHOME_H
#define WINHOME_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QImage>

class Winhome : public QWidget
{
    Q_OBJECT
public:
    explicit Winhome(QWidget *parent = nullptr);

private:
    QVBoxLayout *vbox;
    QLabel      *lbl1;
    QLabel      *lbl2;
    QImage      *img1;

signals:
};

#endif // WINHOME_H
