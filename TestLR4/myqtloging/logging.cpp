#include "logging.h"

Q_LOGGING_CATEGORY(logDebug,    "Debug")
Q_LOGGING_CATEGORY(logInfo,     "Info")
Q_LOGGING_CATEGORY(logWarning,  "Warning")
Q_LOGGING_CATEGORY(logCritical, "Critical")

QFile Logging::m_logFile("/media/develop/DEV/Qt_projects/myqtloging/log/error.txt");

Logging::Logging() {
    // Устанавливаем обработчик
    qInstallMessageHandler(Logging::messageHandler);
}

void Logging::messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    // Открываем файл логирования
    if (!m_logFile.open(QFile::Append | QFile::Text)) {
        qDebug() << "Не удалось открыть файл.";
    }
    // Открываем поток записи в файл
    QTextStream out(&m_logFile);
    // Записываем дату записи
    out << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz ");
    // По типу определяем, к какому уровню относится сообщение
    switch (type)
    {
        case QtInfoMsg:     out << "INF "; break;
        case QtDebugMsg:    out << "DBG "; break;
        case QtWarningMsg:  out << "WRN "; break;
        case QtCriticalMsg: out << "CRT "; break;
        case QtFatalMsg:    out << "FTL "; break;
    }
    // Записываем в вывод категорию сообщения и само сообщение
    out << context.category
        << ": "
        << msg << Qt::endl;
    out.flush();    // Очищаем буферизированные данные
    m_logFile.close();
}

void Logging::TestLog() {
    qCritical(logCritical()) << "Тестируем запись";
}
