/*************************************************
**************************************************
** Практическая работа № 5                      **
** Вариант № 106                                **
** Продублировать элементы с чётным номером.    **
** Без условных операторов.                     **
**                                              **
** Выполнил: студент 3 курса ЕПК гр. И-32       **
** Самсыка Р.                                   **
**                                              **
** Проверил: преподаватель специальных дисциплин**
** Фомин А. Т.                                  **
**************************************************
*************************************************/


#include <iostream>
#include <vector>
#include <stdexcept>


using namespace std;

int main()
{
    try{
        int n;
        cout<<"n = ";
        cin>>n;
        if(n<1) throw logic_error("");
        vector<int> vec;
        for(int i=0; i < n; i++) vec.push_back(i);
        cout<<"Массив: ";
        for(int i=0; i < vec.size(); i++) cout<<vec[i]<<" ";
        cout<<endl;
        for(int i=2; i < n; i+=2) vec.push_back(i);
        cout<<"Массив2: ";
        for(int i=0; i < vec.size(); i++) cout<<vec[i]<<" ";
    }
    catch(out_of_range){
        cout<<"Программа вышла за пределы массива";
    }
    catch(logic_error e){
        cout<<"Недопустимая длина";
    }
    catch(...){
        cout<<"Неизвестная ошибка";
    }
    return 0;
}
/*
n = 5

Process exited with code: 0.Массив: 0 1 2 3 4
Массив2: 0 1 2 3 4 2 4


n = -1

Process exited with code: 0.Недопустимая длина
*/
