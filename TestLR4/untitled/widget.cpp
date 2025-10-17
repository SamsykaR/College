#include "widget.h"
#include "ui_widget.h"

Q_LOGGING_CATEGORY(logDebug,    "Debug")
Q_LOGGING_CATEGORY(logInfo,     "Info")
Q_LOGGING_CATEGORY(logWarning,  "Warning")
Q_LOGGING_CATEGORY(logCritical, "Critical")
Q_LOGGING_CATEGORY(logFatal,    "Fatal")

QFile Widget::m_logFile("../log/logs.txt");
QFile Widget::m_textFile("../text/text.txt");


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    qInstallMessageHandler(Widget::messageHandler);

    QDir logDir("../log");
    if (!logDir.exists()) {
        logDir.mkpath(".");
    }

    QDir textDir("../text");
    if (!textDir.exists()) {
        textDir.mkpath(".");
    }

    tel.setPattern("^\\+7\\s?\\(?[0-9]{3}\\)?\\s?[0-9]{3}[-\\s]?[0-9]{2}[-\\s]?[0-9]{2}$");
    ema.setPattern("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");

    connect(ui->InFile, &QPushButton::clicked, this, &Widget::InFile);
    connect(ui->OutFile, &QPushButton::clicked, this, &Widget::OutFile);

    connect(ui->Login, &QLineEdit::textChanged, this, &Widget::ValidLogin);
    connect(ui->Telephone, &QLineEdit::textChanged, this, &Widget::ValidTelephone);
    connect(ui->Email, &QLineEdit::textChanged, this, &Widget::ValidEmail);
    messageHandler(QtInfoMsg, {}, "Приложение запущено");
}

Widget::~Widget()
{
    messageHandler(QtInfoMsg, {}, "Приложение закрыто");
    delete ui;
}

void Widget::messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &mes)
{
    if (m_logFile.open(QFile::Append | QFile::Text)) {
        QTextStream out(&m_logFile);
        out << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz ");
        switch (type)
        {
        case QtInfoMsg:     out << "Info "; break;
        case QtDebugMsg:    out << "Debug "; break;
        case QtWarningMsg:  out << "Warning "; break;
        case QtCriticalMsg: out << "Critical "; break;
        case QtFatalMsg:    out << "FTL "; break;
        }
        out << context.category
            << ": "
            << mes << Qt::endl;
        out.flush();
        m_logFile.close();
    }
    else qDebug() << "Не удалось открыть файл";
}

void Widget::InFile(){
    QString login = ui->Login->text();
    QString phone = ui->Telephone->text();
    QString email = ui->Email->text();

    messageHandler(QtDebugMsg, {}, "Проверка валидности логина");
    if(!ValidLogin(login)){
        messageHandler(QtWarningMsg, {}, "Неверный формат логина (поле не должно быть пустым)");
        qDebug() << "Неверный формат логина";
        return;
    }

    messageHandler(QtDebugMsg, {}, "Проверка валидности телефона");
    if(!ValidTelephone(phone)){
        messageHandler(QtWarningMsg, {}, "Неверный формат телефона (+7 XXX XXX XX XX)");
        qDebug() << "Неверный формат телефона";
        return;
    }

    messageHandler(QtDebugMsg, {}, "Проверка валидности почты");
    if(!ValidEmail(email)){
        messageHandler(QtWarningMsg, {}, "Неверный формат почты (nnn@nnn.nnn)");
        qDebug() << "Неверный формат почты";
        return;
    }

    if (!m_textFile.open(QFile::Append | QFile::Text)) {
        messageHandler(QtWarningMsg, {}, "Не удалось открыть файл для записи");
        qDebug() << "Не удалось открыть файл для записи";
    }
    else messageHandler(QtDebugMsg, {}, "Файл для записи открыт");
    QTextStream out(&m_textFile);
    out << ui->Login->text() << "\n"
        << ui->Email->text() << "\n"
        << ui->Telephone->text();
    out.flush();
    m_textFile.close();
}

void Widget::OutFile(){
    if (!m_textFile.open(QFile::ReadOnly | QFile::Text)) {
        messageHandler(QtWarningMsg, {}, "Не удалось открыть файл для чтения");
        qDebug() << "Не удалось открыть файл для чтения";
    }
    else messageHandler(QtDebugMsg, {}, "Файл для записи открыт");
    QTextStream out(&m_textFile);
    ui->textEdit->setText(out.readAll());
    out.flush();
    m_textFile.close();
}

bool Widget::ValidLogin(const QString & t){
    return !t.isEmpty();
}

bool Widget::ValidEmail(const QString & t){
    return ema.match(t).hasMatch();
}
bool Widget::ValidTelephone(const QString & t){
    return tel.match(t).hasMatch();
}
