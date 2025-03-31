/*!
 * \brief Механизм работы сигналов и слотов в Qt / Лабораторная работа №4 
 * \details Вариант 26. Программа делает расчёт по индивидуальной формуле а затем выводит резульатат по нажатию кнопки
 * \author  Самсыка Р. М. И-32 группа
 * \version 0.1
 * \date 06.03.2025
 * \copyright GNU Public License.
 */

#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
