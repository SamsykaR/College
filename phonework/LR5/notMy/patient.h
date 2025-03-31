/// \file patient.h
/// \brief Заголовочный файл структуры Patient

#ifndef PATIENT_H
#define PATIENT_H

#include <QString>
#include <QTextStream>
#include <QStringList>

/// \struct Patient
/// \brief Данные пациента
///
/// Хранит информацию о полисе, ФИО, отделении и враче
struct Patient {
    QString policy;  /*!< Номер полиса */
    QString name;    /*!< ФИО пациента */
    QString section; /*!< Отделение */
    QString doctor;  /*!< Лечащий врачф */

    /// \brief Конструктор с параметрами
    /// \param policy_ Номер полиса
    /// \param name_ ФИО пациента
    /// \param section_ Отделение
    /// \param doctor_ Лечащий врач
    Patient(QString policy_, QString name_, QString section_, QString doctor_);

    /// \brief Конструктор по умолчанию
    Patient();

    /// \brief Загружает данные из потока
    /// \param stream Входной поток
    /// \return true, если данные загружены успешно
    bool load(QTextStream& stream);

    /// \brief Сохраняет данные в поток
    /// \param stream Выходной поток
    void save(QTextStream& stream);
};

#endif // PATIENT_H
