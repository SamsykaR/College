#include "myexceptions.h"

/// \def myExceptions()
/// \brief Класс с пользовательскими исключениями
myExceptions::myExceptions(){}

/// \def dbOpenException()
/// \brief Конструктор исключения при работе с БД
///
/// \param message Сообщение об ошибке
myExceptions::dbOpenException::dbOpenException(const QString& message): message(message){}
/// \def getMessage()
/// \brief Получение сообщения
QString myExceptions::dbOpenException::getMessage() const {return message;}

/// \def queryReadException()
/// \brief Конструктор исключения при работе с запросами
///
/// \param message Сообщение об ошибке
/// \param addMessage дополнительное сообщение об ошибке
myExceptions::queryReadException::queryReadException(const QString& message, const QString& addMessage):
    message(message), addMessage(addMessage){}
/// \def getMessage()
/// \brief Получение сообщения
QString myExceptions::queryReadException::getMessage() const {return message+"\n"+addMessage;}
