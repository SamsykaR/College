/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QGridLayout *gridLayout;
    QPushButton *save;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_5;
    QLineEdit *find_doctor;
    QLineEdit *find_name;
    QLabel *label_7;
    QLabel *label_9;
    QLineEdit *find_section;
    QLabel *label_6;
    QLineEdit *find_policy;
    QLabel *label_8;
    QPushButton *find;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_3;
    QTableWidget *tableWidget;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLineEdit *add_name;
    QLineEdit *add_doctor;
    QLabel *label_3;
    QLineEdit *add_section;
    QLineEdit *add_policy;
    QLabel *label_4;
    QLabel *label_2;
    QPushButton *add;
    QPushButton *load;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_4;
    QPushButton *rem;
    QLabel *label_5;
    QLineEdit *rem_policy;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName("MainWidget");
        MainWidget->resize(482, 413);
        gridLayout = new QGridLayout(MainWidget);
        gridLayout->setObjectName("gridLayout");
        save = new QPushButton(MainWidget);
        save->setObjectName("save");

        gridLayout->addWidget(save, 2, 0, 1, 1);

        groupBox_3 = new QGroupBox(MainWidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setEnabled(true);
        gridLayout_5 = new QGridLayout(groupBox_3);
        gridLayout_5->setObjectName("gridLayout_5");
        find_doctor = new QLineEdit(groupBox_3);
        find_doctor->setObjectName("find_doctor");

        gridLayout_5->addWidget(find_doctor, 3, 1, 1, 1);

        find_name = new QLineEdit(groupBox_3);
        find_name->setObjectName("find_name");

        gridLayout_5->addWidget(find_name, 1, 1, 1, 1);

        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName("label_7");

        gridLayout_5->addWidget(label_7, 1, 0, 1, 1);

        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName("label_9");

        gridLayout_5->addWidget(label_9, 2, 0, 1, 1);

        find_section = new QLineEdit(groupBox_3);
        find_section->setObjectName("find_section");

        gridLayout_5->addWidget(find_section, 2, 1, 1, 1);

        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName("label_6");

        gridLayout_5->addWidget(label_6, 0, 0, 1, 1);

        find_policy = new QLineEdit(groupBox_3);
        find_policy->setObjectName("find_policy");

        gridLayout_5->addWidget(find_policy, 0, 1, 1, 1);

        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName("label_8");

        gridLayout_5->addWidget(label_8, 3, 0, 1, 1);

        find = new QPushButton(groupBox_3);
        find->setObjectName("find");

        gridLayout_5->addWidget(find, 4, 0, 1, 2);


        gridLayout->addWidget(groupBox_3, 0, 3, 1, 1);

        groupBox_4 = new QGroupBox(MainWidget);
        groupBox_4->setObjectName("groupBox_4");
        gridLayout_3 = new QGridLayout(groupBox_4);
        gridLayout_3->setObjectName("gridLayout_3");
        tableWidget = new QTableWidget(groupBox_4);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setEnabled(true);
        tableWidget->horizontalHeader()->setVisible(true);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(120);
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setStretchLastSection(false);

        gridLayout_3->addWidget(tableWidget, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_4, 1, 0, 1, 4);

        groupBox = new QGroupBox(MainWidget);
        groupBox->setObjectName("groupBox");
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName("gridLayout_2");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        add_name = new QLineEdit(groupBox);
        add_name->setObjectName("add_name");

        gridLayout_2->addWidget(add_name, 1, 1, 1, 1);

        add_doctor = new QLineEdit(groupBox);
        add_doctor->setObjectName("add_doctor");

        gridLayout_2->addWidget(add_doctor, 3, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        add_section = new QLineEdit(groupBox);
        add_section->setObjectName("add_section");

        gridLayout_2->addWidget(add_section, 2, 1, 1, 1);

        add_policy = new QLineEdit(groupBox);
        add_policy->setObjectName("add_policy");

        gridLayout_2->addWidget(add_policy, 0, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");

        gridLayout_2->addWidget(label_4, 3, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        add = new QPushButton(groupBox);
        add->setObjectName("add");

        gridLayout_2->addWidget(add, 4, 0, 1, 2);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        load = new QPushButton(MainWidget);
        load->setObjectName("load");

        gridLayout->addWidget(load, 2, 2, 1, 2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 1, 1, 1);

        groupBox_2 = new QGroupBox(MainWidget);
        groupBox_2->setObjectName("groupBox_2");
        gridLayout_4 = new QGridLayout(groupBox_2);
        gridLayout_4->setObjectName("gridLayout_4");
        rem = new QPushButton(groupBox_2);
        rem->setObjectName("rem");

        gridLayout_4->addWidget(rem, 2, 0, 1, 2);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName("label_5");

        gridLayout_4->addWidget(label_5, 0, 0, 1, 1);

        rem_policy = new QLineEdit(groupBox_2);
        rem_policy->setObjectName("rem_policy");

        gridLayout_4->addWidget(rem_policy, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 1, 0, 1, 2);


        gridLayout->addWidget(groupBox_2, 0, 1, 1, 2);


        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QCoreApplication::translate("MainWidget", "Form", nullptr));
        save->setText(QCoreApplication::translate("MainWidget", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWidget", "\321\204\320\270\320\273\321\214\321\202\321\200", nullptr));
        label_7->setText(QCoreApplication::translate("MainWidget", "\320\244\320\230\320\236", nullptr));
        label_9->setText(QCoreApplication::translate("MainWidget", "\320\236\321\202\320\264\320\265\320\273\320\265\320\275\320\270\320\265", nullptr));
        label_6->setText(QCoreApplication::translate("MainWidget", "\320\237\320\276\320\273\320\270\321\201", nullptr));
        label_8->setText(QCoreApplication::translate("MainWidget", "\320\222\321\200\320\260\321\207", nullptr));
        find->setText(QCoreApplication::translate("MainWidget", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWidget", "\320\224\320\260\320\275\320\275\321\213\320\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWidget", "\320\237\320\276\320\273\320\270\321\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWidget", "\320\244\320\230\320\236", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWidget", "\320\236\321\202\320\264\320\265\320\273\320\265\320\275\320\270\320\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWidget", "\320\222\321\200\320\260\321\207", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWidget", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265", nullptr));
        label->setText(QCoreApplication::translate("MainWidget", "\320\237\320\276\320\273\320\270\321\201", nullptr));
        label_3->setText(QCoreApplication::translate("MainWidget", "\320\236\321\202\320\264\320\265\320\273\320\265\320\275\320\270\320\265", nullptr));
        label_4->setText(QCoreApplication::translate("MainWidget", "\320\222\321\200\320\260\321\207", nullptr));
        label_2->setText(QCoreApplication::translate("MainWidget", "\320\244\320\230\320\236", nullptr));
        add->setText(QCoreApplication::translate("MainWidget", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        load->setText(QCoreApplication::translate("MainWidget", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWidget", "\321\203\320\264\320\260\320\273\320\265\320\275\320\270\320\265", nullptr));
        rem->setText(QCoreApplication::translate("MainWidget", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        label_5->setText(QCoreApplication::translate("MainWidget", "\320\237\320\276\320\273\320\270\321\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
