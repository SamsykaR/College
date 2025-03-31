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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Another_win
{
public:
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_2;
    QLabel *label_3;
    QPushButton *pushButton;

    void setupUi(QWidget *Another_win)
    {
        if (Another_win->objectName().isEmpty())
            Another_win->setObjectName("Another_win");
        Another_win->resize(374, 205);
        verticalLayoutWidget_3 = new QWidget(Another_win);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(0, 0, 371, 201));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_2 = new QLabel(verticalLayoutWidget_3);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        label = new QLabel(verticalLayoutWidget_3);
        label->setObjectName("label");

        verticalLayout->addWidget(label);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        lineEdit = new QLineEdit(verticalLayoutWidget_3);
        lineEdit->setObjectName("lineEdit");

        verticalLayout_2->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(verticalLayoutWidget_3);
        lineEdit_2->setObjectName("lineEdit_2");

        verticalLayout_2->addWidget(lineEdit_2);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        pushButton_2 = new QPushButton(verticalLayoutWidget_3);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout_3->addWidget(pushButton_2);

        label_3 = new QLabel(verticalLayoutWidget_3);
        label_3->setObjectName("label_3");

        verticalLayout_3->addWidget(label_3);

        pushButton = new QPushButton(verticalLayoutWidget_3);
        pushButton->setObjectName("pushButton");

        verticalLayout_3->addWidget(pushButton);


        retranslateUi(Another_win);

        QMetaObject::connectSlotsByName(Another_win);
    } // setupUi

    void retranslateUi(QWidget *Another_win)
    {
        Another_win->setWindowTitle(QCoreApplication::translate("Another_win", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("Another_win", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 2", nullptr));
        label->setText(QCoreApplication::translate("Another_win", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 1", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Another_win", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        label_3->setText(QString());
        pushButton->setText(QCoreApplication::translate("Another_win", "\320\236\320\272\320\275\320\276 \320\277\321\200\320\276\321\201\320\274\320\276\321\202\321\200\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Another_win: public Ui_Another_win {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANOTHER_WIN_H
