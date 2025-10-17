#ifndef LOGGING_H
#define LOGGING_H
#include <QCoreApplication>
#include <QLoggingCategory>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QDateTime>

Q_DECLARE_LOGGING_CATEGORY(logDebug)
Q_DECLARE_LOGGING_CATEGORY(logInfo)
Q_DECLARE_LOGGING_CATEGORY(logWarning)
Q_DECLARE_LOGGING_CATEGORY(logCritical)

class Logging
{
public:
    Logging();
    static QFile m_logFile;
    static void messageHandler(QtMsgType,
                               const QMessageLogContext &,
                               const QString &);
    void TestLog();
};

#endif // LOGGING_H
