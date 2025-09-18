#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QTcpServer>
#include <QTextEdit>
#include <QTcpSocket>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QLabel>
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

/// \class MainWindow
/// \brief Основной класс сервера
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
	/// \def MainWindow
    /// \brief Конструктор главного окна сервера
    /// \param nPort Порт для подключения
    /// \param pwgt Родительский виджет
    MainWindow(int nPort, QMainWindow* pwgt = 0);
	/// \def ~MainWindow
    /// \brief Деструктор окна
    ~MainWindow();

private:
    QTcpServer* m_ptcpServer;               /*!< Указатель на TCP-сервер */
    QTextEdit* m_ptxt;                      /*!< Текстовое поле для отображения сообщений */
    quint16 m_nNextBlockSize;               /*!< Размер следующего блока данных */
    Ui::MainWindow *ui;                     /*!< Указатель на интерфейс */
	/// \def sendToClient
    /// \brief Отправляет данные клиенту
    /// \param pSocket Указатель на TCP-сокет клиента
    /// \param str Строка для отправки клиенту
    void sendToClient(QTcpSocket* pSocket, const QString& str);

public slots:
	/// \def slotNewConnection
    /// \brief Слот обработки нового подключения
    virtual void slotNewConnection();
    
    /// \def slotReadClient
    /// \brief Слот чтения данных от клиента
    void slotReadClient();
};
#endif // MAINWINDOW_H
