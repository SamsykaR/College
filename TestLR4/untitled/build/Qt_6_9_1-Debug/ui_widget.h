/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *InFile;
    QPushButton *OutFile;
    QVBoxLayout *verticalLayout;
    QLineEdit *Login;
    QLineEdit *Email;
    QLineEdit *Telephone;
    QTextEdit *textEdit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(719, 160);
        gridLayoutWidget = new QWidget(Widget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, 10, 701, 140));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        InFile = new QPushButton(gridLayoutWidget);
        InFile->setObjectName("InFile");

        gridLayout->addWidget(InFile, 1, 0, 1, 1);

        OutFile = new QPushButton(gridLayoutWidget);
        OutFile->setObjectName("OutFile");

        gridLayout->addWidget(OutFile, 1, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        Login = new QLineEdit(gridLayoutWidget);
        Login->setObjectName("Login");

        verticalLayout->addWidget(Login);

        Email = new QLineEdit(gridLayoutWidget);
        Email->setObjectName("Email");

        verticalLayout->addWidget(Email);

        Telephone = new QLineEdit(gridLayoutWidget);
        Telephone->setObjectName("Telephone");

        verticalLayout->addWidget(Telephone);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        textEdit = new QTextEdit(gridLayoutWidget);
        textEdit->setObjectName("textEdit");

        gridLayout->addWidget(textEdit, 0, 1, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        InFile->setText(QCoreApplication::translate("Widget", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        OutFile->setText(QCoreApplication::translate("Widget", "\320\222\321\213\320\262\320\265\321\201\321\202\320\270", nullptr));
        Login->setPlaceholderText(QCoreApplication::translate("Widget", "Login", nullptr));
        Email->setPlaceholderText(QCoreApplication::translate("Widget", "Email", nullptr));
        Telephone->setPlaceholderText(QCoreApplication::translate("Widget", "Telephone", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
