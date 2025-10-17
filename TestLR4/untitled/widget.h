#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QCoreApplication>
#include <QLoggingCategory>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QDateTime>
#include <QRegularExpression>

Q_DECLARE_LOGGING_CATEGORY(logDebug)
Q_DECLARE_LOGGING_CATEGORY(logInfo)
Q_DECLARE_LOGGING_CATEGORY(logWarning)
Q_DECLARE_LOGGING_CATEGORY(logCritical)
Q_DECLARE_LOGGING_CATEGORY(logFatal)

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

/// \brief Главный класс виджета приложения
class Widget : public QWidget
{
    Q_OBJECT
private slots:
    /// \brief Проверка валидности логина
    /// \param Строка с логином для проверки
    /// \return true если логин валиден, иначе false
    bool ValidLogin(const QString &);
	
    /// \brief Проверка валидности email
    /// \param Строка с email для проверки
    /// \return true если email валиден, иначе false
	bool ValidEmail(const QString &);
	
	/// \brief Проверка валидности телефона
    /// \param Строка с номером телефона для проверки
    /// \return true если телефон валиден, иначе false
    bool ValidTelephone(const QString &);

public:
    /// \brief Конструктор класса Widget
    /// \param parent Родительский виджет
    Widget(QWidget *parent = nullptr);
	
	/// \brief Деструктор класса Widget
    ~Widget();

private:
    Ui::Widget *ui;                          ///< Указатель на пользовательский интерфейс
    static QFile m_logFile;                  ///< Файл для записи логов
    static QFile m_textFile;                 ///< Файл для хранения данных
	
	/// \brief Обработчик сообщений логов
    /// \param type Тип сообщения
    /// \param context Контекст сообщения
    /// \param mes Текст сообщения
    static void messageHandler(QtMsgType,
                               const QMessageLogContext &,
                               const QString &);
    
	/// \brief Запись данных в файл
	void InFile();
	
	/// \brief Чтение данных из файла
    void OutFile();
	QRegularExpression tel;                  ///< Шаблон для проверки телефона
    QRegularExpression ema;                  ///< Шаблон для проверки email
};
#endif // WIDGET_H
