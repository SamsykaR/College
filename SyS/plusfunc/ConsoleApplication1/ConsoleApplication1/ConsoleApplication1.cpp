/*****************************************************
******************************************************
**                                                  **
**  Программа заполнения и вывода элементов массива **
**                                                  **
**  Выполнил: студент 3 курса ЕПК гр. И-32          **
**            Самсыка Родион                        **
**  Проверил: преподаватель Системного              **
**  программирования Фомин А. Т.                    **
**                                                  **
******************************************************
*****************************************************/

#include <iostream>
using namespace std;

int* MasIn(int);
void MasOut(int* , int);

int main(){
    int length = 10;
    int* array = MasIn(length);
    MasOut(array, length);
    return 1;
}

int* MasIn(int l) {
    int* mas = new int[l];
    for (int i = 0; i < l;i++) {
        mas[i] = rand() % 10;
    }
    return mas;
}
void MasOut(int* mas, int l) {
    for (int i = 0; i < l; i++) {
        cout << mas[i] << " ";
    }
}