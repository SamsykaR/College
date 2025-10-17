#include "logging.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Logging mylog;

    // Вызываем функцию, которая что-то пишет в лог
    mylog.TestLog();

    // Пробуем откуда угодно
    Logging::messageHandler(QtDebugMsg, {}, "Сообщение уровня отладки");
    Logging::messageHandler(QtInfoMsg,  {}, "Что-то произошло в системе");
    Logging::messageHandler(QtWarningMsg,  {}, "Ошибка в программе");
    Logging::messageHandler(QtCriticalMsg, {}, "Фатальная ошибка");
    //Второй аргумент — это ссылка на объект QMessageLogContext, который обычно
    //оставляется пустым, если вам не нужна дополнительная информация о контексте
    //(категория, номер строки, название файла и т.д.).

    return a.exec();
}
