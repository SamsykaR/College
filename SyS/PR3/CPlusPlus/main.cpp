/*************************************************
**************************************************
** Практическая работа № 3                      **
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
#include <random>
#include <ctime>

using namespace std;

array<int, 15>& MAssive(array<int, 15>&);
void Task17(array<int, 15>&);
int Rand();

int main()
{
    array<int, 15> arr{};
    arr = MAssive(arr);
    cout << "array: ";
    for(int el:arr) cout << el << "  ";
    cout << endl;
    Task17(arr);
    return 0;
}
int Random(){
    static default_random_engine rnd(time(0));
    static uniform_int_distribution<int> d(-10, 10);
    return d(rnd);
}
array<int, 15>& MAssive(array<int, 15>& ar){
    for(size_t i{0}; i<ar.size(); ++i) ar[i] = Random();
    return ar;
}
void Task17(array<int, 15>& ar){
    size_t mins {0};
    size_t nul {0};
    int multiple {1};
    for(int el:ar){
        if(el == 0) ++nul;
        else if (el < 0) ++ mins;
        else multiple *= el;
    }
    cout << " minus: "<< mins <<"\n zero: "<<nul<<"\n multiple: "<<multiple;
}
