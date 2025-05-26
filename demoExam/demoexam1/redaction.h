#ifndef REDACTION_H
#define REDACTION_H

#include <QWidget>
#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QLabel>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>
#include <QDataWidgetMapper>
#include <QSqlRecord>

class Redaction : public QWidget
{
    Q_OBJECT
public:
    explicit Redaction(QWidget *parent = nullptr);

signals:

private:
    QLabel* lbl;
    QVBoxLayout *vbox;

    QLabel *typeLbl;
    QLabel *nameLbl;
    QLabel *addressLbl;
    QLabel *innLbl;
    QLabel *fioLbl;
    QLabel *telLbl;
    QLabel *emailLbl;
    QLabel *ratLbl;
    QLabel *prodLbl;


    QLineEdit *typeEdit;
    QLineEdit *nameEdit;
    QTextEdit *addressEdit;
    QLineEdit *innEdit;
    QLineEdit *fioEdit;
    QLineEdit *telEdit;
    QLineEdit *emailEdit;
    QLineEdit *ratEdit;
    QLineEdit *prodEdit;

    QComboBox   *typeComboBox;
    QPushButton *nextButton;
    QPushButton *previousButton;
    QPushButton *redactButton;
    QPushButton *clearButton;
    QPushButton *addButton;

    QGridLayout *layout;

    QSqlDatabase db;
    QSqlTableModel *model;
    QDataWidgetMapper *mapper;

    QSqlRecord record;

private slots:
    void partChoose();
    void updateButtons(int row);
    void ClearBtn_clicked();
    void AddBtn_clicked();
    void RedactBtn_clicked();
};

#endif // REDACTION_H
