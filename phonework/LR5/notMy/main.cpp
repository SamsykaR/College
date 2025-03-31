/*!
 * \brief Обработка данных в файле / Лабораторная работа №5
 * \details Программаработает с данными на подобии базы данных, способна записывать данные в файл и читать из файла
 * \author  Самсыка Р. М. / Студент И-32 группа
 * \version 0.1
 * \date 12.03.25
 * \copyright GNU Public License.
 */

#include "mainwidget.h"
#include <QApplication>

int main(int argc, char** argv) {
    QApplication a(argc, argv);
    MainWidget widget;
    widget.show();
    return a.exec();
}
