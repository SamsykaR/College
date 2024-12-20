/*************************************************
**************************************************
** Практическая работа № 3.2                    **
** Вариант № 17                                 **
** Ввести массив, состоящий из 15 элементов     **
** целого типа. Определить количество           **
** отрицательных, произведение положительных и  **
** количество нулевых элементов.                **
**                                              **
** Выполнил: студент 3 курса ЕПК гр. И-32       **
** Самсыка Р.                                   **
**                                              **
** Проверил: преподаватель специальных дисциплин**
** Фомин А. Т.                                  **
**************************************************
*************************************************/

#include <iostream>
#include <array>
#include "digit.h"
using namespace std;

int main()
{
    array<int, 15> arr{};
    arr = MAssive(arr);
    cout << "массив: ";
    Out(arr);
    cout << endl;
    Task17(arr);
    return 0;
}
