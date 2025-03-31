/********************************************************************************
** Form generated from reading UI file 'another_win.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANOTHER_WIN_H
#define UI_ANOTHER_WIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Another_win
{
public:
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_2;
    QLabel *label_3;

    void setupUi(QWidget *Another_win)
    {
        if (Another_win->objectName().isEmpty())
            Another_win->setObjectName("Another_win");
        Another_win->resize(640, 480);
        pushButton = new QPushButton(Another_win);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(430, 400, 181, 41));
        lineEdit = new QLineEdit(Another_win);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(170, 40, 113, 28));
        label = new QLabel(Another_win);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 40, 91, 21));
        label_2 = new QLabel(Another_win);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 80, 91, 21));
        lineEdit_2 = new QLineEdit(Another_win);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(170, 70, 113, 28));
        pushButton_2 = new QPushButton(Another_win);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(50, 140, 221, 29));
        label_3 = new QLabel(Another_win);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 210, 411, 111));

        retranslateUi(Another_win);

        QMetaObject::connectSlotsByName(Another_win);
    } // setupUi

    void retranslateUi(QWidget *Another_win)
    {
        Another_win->setWindowTitle(QCoreApplication::translate("Another_win", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("Another_win", "\320\236\320\272\320\275\320\276 \320\277\321\200\320\276\321\201\320\274\320\276\321\202\321\200\320\260", nullptr));
        label->setText(QCoreApplication::translate("Another_win", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 1", nullptr));
        label_2->setText(QCoreApplication::translate("Another_win", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 2", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Another_win", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Another_win: public Ui_Another_win {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANOTHER_WIN_H
