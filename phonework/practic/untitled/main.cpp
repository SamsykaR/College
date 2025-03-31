/*!
 * \brief Работа с файлами/ Практическая работа №7
 * \details 8.1 1) Здание. Вывести здания которым больше 50 лет
 *          8.1 2)
 *          8.2 1)
 * / Вариант 17
 * \author  Самсыка Р. М. / И-32 группа
 * \version 0.1
 * \date 27.03.2025
 * \copyright GNU Public License.
 */
#include <QFile>
#include <QTextStream>
#include <iostream>

int main()
{
    QString filename1 = "./inputs/input811";
    QString filename2 = "./inputs/input812";
    QString filename3 = "./inputs/input821";
    QString filenameOut = "./outputs/output";

    QFile file1(filename1);
    QFile file2(filename2);
    QFile file3(filename3);
    QFile fileOut(filenameOut);

    //задание 8.1 1 - Здания
    if(file1.open(QIODevice::ReadOnly)){
        std::cout << "2";
        QString homes;
        QString line;
        QTextStream in(&file1);
        while(!in.atEnd()){
            line = in.readLine();
            if(line.split(';').at(4).split(' ').at(0).toInt() >= 50) homes += line + "\n";
            std::cout << "3";
        }
        if(fileOut.open(QIODevice::WriteOnly | QIODevice::Text)){
            QTextStream out(&fileOut);
            out << "Здания старше 50 лет"<< Qt::endl<<homes;
        }
    }
    file1.close();
    return 0;
}
