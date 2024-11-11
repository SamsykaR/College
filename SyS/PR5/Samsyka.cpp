/*****************************************************
******************************************************
** Практическая работа № 5                          **
** Вариант № 17                                     **
** Дано целое число в двоичной системе счисления,   **
** т.е. последовательность цифр  0 и 1. Осуществить **
** циклический сдвиг элементов массива вправо на    **
** одну позицию. Определить сумму исходного и       **
** полученного после сдвига числа.   		        **
**                                                  **
** Выполнил: студент 3 курса ЕПК гр. И-32           **
** Самсыка Р.                                       **
**                                                  **
** Проверил: преподаватель специальных дисциплин    **
** Фомин А. Т.                                      **
******************************************************
*****************************************************/

using namespace std;
using namespace chrono;

int Rand();
void InputArr(array<int, 5>&);
void InputCArr(int*, int);
void DoubleToTen(array<int, 5>&, int&);
void CDoubleToTen(int*, int, int&);
array<int, 5>& Sdvig(array<int, 5>&);
int* CSdvig(int*, int);

int main()
{
    int arsum = 0;
    int& arsumt = arsum;
    array<int, 5> ar;
    InputArr(ar);
    DoubleToTen(ar, arsumt);
    array<int, 5> ar2;
    ar2 = Sdvig(ar);
    DoubleToTen(ar2, arsumt);
    cout << "Сумма: " << arsum;

    cout << endl << endl;

    int carsum = 0;
    int& carsumt = carsum;
    int* arr = new int[5];
    InputCArr(arr, 5);
    CDoubleToTen(arr, 5, carsumt);
    int* arr2 = new int[5];
    arr2 = CSdvig(arr, 5);
    CDoubleToTen(arr2, 5, carsumt);
    cout << "Сумма: " << carsum;
    return 0;
}
int Rand() {
    static int seed = system_clock::now().time_since_epoch().count();
    static default_random_engine rnd(seed);
    static uniform_int_distribution<int> d(0, 1);
    return d(rnd);
}
void InputArr(array<int, 5>& mas) {
    cout << "Массив: ";
    for (size_t i{ 0 }; i < mas.size(); i++) {
        mas[i] = Rand();
        cout << mas[i] << " ";
    }
    cout << endl;
}
void InputCArr(int* mas, int n) {
    cout << "СиМассив: ";
    for (size_t i{ 0 }; i < n; i++) {
        mas[i] = Rand();
        cout << mas[i] << " ";
    }
    cout << endl;
}
void DoubleToTen(array<int, 5>& mas, int& a) {
    int total = 0;
    int power = mas.size() - 1;
    for (int el : mas) {
        total += el * pow(2, power);
        power--;
    }
    cout << "Двоичное число: " << total;
    cout << endl;
    a += total;
}
void CDoubleToTen(int* mas, int n, int& a) {
    int total = 0;
    int power = n - 1;
    for (int i{ 0 }; i < n; i++) {
        total += mas[i] * pow(2, power);
        power--;
    }
    cout << "СиДвоичное число: " << total;
    cout << endl;
    a += total;
}
array<int, 5>& Sdvig(array<int, 5>& mas) {
    int last = mas[mas.size() - 1];
    for (size_t i = mas.size() - 1; i > 0; --i) {
        mas[i] = mas[i - 1];
    }
    mas[0] = last;
    cout << "Сдвинутый массив: ";
    for (size_t i{ 0 }; i < mas.size(); i++) {
        cout << mas[i] << " ";
    }
    cout << endl;
    return mas;
}
int* CSdvig(int* mas, int n) {
    int last = mas[n - 1];
    for (size_t i = n - 1; i > 0; --i) {
        mas[i] = mas[i - 1];
    }
    mas[0] = last;
    cout << "Сдвинутый массив: ";
    for (size_t i{ 0 }; i < n; i++) {
        cout << mas[i] << " ";
    }
    cout << endl;
    return mas;
}