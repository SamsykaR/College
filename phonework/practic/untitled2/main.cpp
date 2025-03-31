/*!
 * \brief Работа с файлами/ Практическая работа №9
 * \details 8.1 1) Здание. Вывести здания которым больше 50 лет
 *          8.1 2) Файл с числами. Найти не делящиеся на 7 но делящиеся на 3
 *          8.2 1) Работники завода. Вывести работников подходящих под пенсионный возраст
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

    if(fileOut.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream out(&fileOut);
        //задание 8.1 1 - Здания
        if(file1.open(QIODevice::ReadOnly)){
            QString homes;
            QString line;
            QTextStream in(&file1);
            while(!in.atEnd()){
                line = in.readLine();
                if(line.split("; ").at(4).split(' ').at(0).toInt() >= 50) homes += line + "\n";
            }
            out << "Здания старше 50 лет"<< Qt::endl<<homes;
        }
        file1.close();

        //задание 8.1 2 - Числа
        if(file2.open(QIODevice::ReadOnly)){ //numbers.split(',')
            QString numbers;
            QString number;
            QTextStream in(&file2);
            numbers = in.readLine();
            foreach (QString el, numbers.split(',')) {
                if((el.toInt()%3==0 && (el.toInt()%7!=0))) number += el + ", ";
            }
            out << "\n\nДелятся на 3 а на 7 нет"<< Qt::endl<<number;
        }
        file2.close();

        //задание 8.2 1 - Работники завода
        if(file3.open(QIODevice::ReadOnly)){
            QString humans;
            QString line;
            QTextStream in(&file3);
            while(!in.atEnd()){
                line = in.readLine();
                if(line.split("; ").at(2) == "Ж")
                    if(line.split("; ").at(3).toInt() <= 2025-65) humans += line + "\n";
                if(line.split("; ").at(2) == "М")
                    if(line.split("; ").at(3).toInt() <= 2025-70) humans += line + "\n";
            }
            out << "\n\nРаботники подходящие для пенсии"<< Qt::endl<<humans;
        }
    }
    file3.close();
    fileOut.close();
    return 0;
}


