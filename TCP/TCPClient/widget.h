#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QTime>

/// \class Widget
/// \brief Основной класс клиента
class Widget : public QWidget
{
    Q_OBJECT

private:
    QTcpSocket* m_pTcpSocket;               /*!< Указатель на TCP-сокет для соединения с сервером */
    QTextEdit* m_ptxtinfo;                  /*!< Текстовое поле для отображения сообщений */
    QLineEdit* m_ptxtinput;                 /*!< Поле ввода для отправки сообщений */
    quint16 m_nNextBlockSize;               /*!< Размер следующего блока данных */

public:
    /// \def Widget
    /// \brief Конструктор клиентского окна
    /// \param strHost Адрес сервера для подключения
    /// \param nPort Порт сервера для подключения
    /// \param pwgt Родительский виджет
    Widget(const QString& strHost, int nPort, QWidget* pwgt=0);
    
    /// \def ~Widget
    /// \brief Деструктор окна
    ~Widget();

private slots:
	/// \def slotReadyRead
    /// \brief Слот обработки входящих данных
    void slotReadyRead();
    
    /// \def slotError
    /// \brief Слот обработки ошибок соединения
    /// \param err Код ошибки сокета
    void slotError(QAbstractSocket::SocketError err);
    
    /// \def slotSendToServer
    /// \brief Слот отправки сообщения серверу
    void slotSendToServer();
    
    /// \def slotConnected
    /// \brief Слот обработки успешного подключения
    void slotConnected();
};
#endif // WIDGET_H
