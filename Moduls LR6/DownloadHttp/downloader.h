#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QFile>
#include <QUrl>
#include <QDebug>

/// \class Downloader
/// \brief Класс для загрузки данных по HTTP
class Downloader : public QObject
{
    Q_OBJECT
public:
    /// \brief Конструктор загрузчика
    /// \param parent Родительский объект (по умолчанию nullptr)
    explicit Downloader(QObject *parent = 0);

signals:
    /// \brief Сигнал о завершении загрузки данных
    void onReady();

public slots:
    /// \brief Слот для инициализации запроса на получение данных
    void getData();

    /// \brief Слот для обработки ответа о полученных данных
    /// \param reply Указатель на объект ответа сети
    void onResult(QNetworkReply *reply);

private:
    QNetworkAccessManager *manager;         /*!< Менеджер сетевого доступа для выполнения HTTP-запросов */
};

#endif // DOWNLOADER_H
