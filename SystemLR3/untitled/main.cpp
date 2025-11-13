#include <iostream>
#include <vector>
#include <thread>
#include <condition_variable>
#include <random>
#include <fstream>

using namespace std;
using namespace chrono;


vector<int> ar(10); 						///< Глобальный массив
string path = "output.txt"; 				///< Путь к файлу с результатами работы с массивом
ofstream out(path); 						///< Поток с файлом для вывода
vector<microseconds> varTimes; 				///< Массив времён условных переменных
vector<microseconds> flagTimes; 			///< Массив времён двух флагов
vector<microseconds> semTimes; 				///< Массив времён семафоров
auto start = high_resolution_clock::now();	///< Начало времени
int varCount = 5;							///< Количество замеров для условных переменных
int flagCount = 5;							///< Количество замеров для флагов
int semCount = 5;							///< Количество замеров для семафоров

/// \brief Вычисляет статистические показатели времени выполнения
/// \param v Вектор с измерениями времени
/// \return Кортеж из среднего значения, доверительного интервала и погрешности
tuple<double, double, double> method(vector<microseconds> v){
    double Sr=0;
    for (auto t : v) {
        Sr += t.count()/20;
    }

    double sumKwOtkl = 0;
    for (auto t : v) {
        double e = Sr - t.count();
        sumKwOtkl += e*e;
    }

    double srKwerr = sqrt(sumKwOtkl/(20*19));

    double koef = 2.093;

    double dovInt = srKwerr * koef;

    double x = dovInt/Sr *100;
    return {Sr, dovInt, x};

}

/// \brief Заполняет массив случайными числами
void Array() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10);

    for (int i = 0; i < ar.size(); i++) {
        ar[i] = dis(gen);
    }
}

/// \brief Функция разделения для быстрой сортировки
/// \param arr Сортируемый массив
/// \param low Нижняя граница
/// \param high Верхняя граница
/// \return Индекс опорного элемента
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

/// \brief Реализация алгоритма быстрой сортировки
/// \param arr Сортируемый массив
/// \param low Нижняя граница
/// \param high Верхняя граница
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/// \brief Записывает массив в файл в обратном порядке половин
void WriteInFile(){
    if(!out.is_open()) cout<<"Ошибка записи";

    int n = ar.size();
    int mid = n / 2;

    for (int i = mid - 1; i >= 0; i--) {
        out << ar[i] << " ";
    }

    for (int i = n - 1; i >= mid; i--) {
        out << ar[i] << " ";
    }

    out<<endl;
}



////////////////////////////////////////////////
condition_variable cv1, cv2;  ///< Условные переменные для синхронизации
bool dataReady = false;       ///< Флаг готовности данных
mutex mut;                    ///< Мьютекс для синхронизации

/// \brief Поток 1 для работы с условными переменными
void CondVarThread1(){
    start = high_resolution_clock::now();
    while(varCount != 0){
        unique_lock<std::mutex> lck(mut);
        cv1.wait(lck, []{return dataReady == false;});
        dataReady = true;
        if (varCount <= 0) break;
        Array();
        quickSort(ar, 0, ar.size()-1);
        cv2.notify_one();
    }
}

/// \brief Поток 2 для работы с условными переменными
void CondVarThread2(){
    while(varCount != 0){
        unique_lock<std::mutex> lck(mut);
        cv2.wait(lck, []{return dataReady == true;});
        if (varCount <= 0) break;
        dataReady = false;
        WriteInFile();
        varCount--;
        cv1.notify_one();
    }
    varTimes.emplace_back(duration_cast<microseconds>(high_resolution_clock::now() - start).count());

}


////////////////////////////////////////////////
atomic_flag F1{}, F2{}; ///< Атомарные флаги для синхронизации

/// \brief Поток 1 для работы с атомарными флагами
void TwoFlagThread1(){
    start = high_resolution_clock::now();
    while(flagCount != 0){
        F1.wait(false);
        F1.clear();
        if (flagCount <= 0) break;
        Array(); //заполнение массива
        quickSort(ar, 0, ar.size()-1);//сортировка
        F2.test_and_set();
        F2.notify_one();
    }
}

/// \brief Поток 2 для работы с атомарными флагами
void TwoFlagThread2(){
    while(flagCount != 0){
        F2.wait(false);
        F2.clear();
        if (flagCount <= 0) break;
        WriteInFile(); //метод 2
        flagCount--;
        F1.test_and_set();
        F1.notify_one();
    }
    flagTimes.emplace_back(duration_cast<microseconds>(high_resolution_clock::now() - start).count());

}


////////////////////////////////////////////////
binary_semaphore sem(1);  ///< Бинарный семафор для синхронизации

/// \brief Поток 1 для работы с семафорами
void SemThread1(){
    start = high_resolution_clock::now();
    while(semCount != 0){
        sem.acquire();
        if (semCount <= 0) break;
        Array();
        quickSort(ar, 0, ar.size()-1);
        sem.release();
    }
}

/// \brief Поток 2 для работы с семафорами
void SemThread2(){
    while(semCount != 0){
        sem.acquire();
        if (semCount <= 0) break;
        WriteInFile();
        semCount--;
        sem.release();
    }
    semTimes.emplace_back(duration_cast<microseconds>(high_resolution_clock::now() - start).count());
}


int main()
{
    for(int i=0; i<20; i++){
        sem.release();
        F1.test_and_set();

        jthread j1(CondVarThread1);
        jthread j2(CondVarThread2);
        j1.join();
        j2.join();


        jthread j3(TwoFlagThread1);
        jthread j4(TwoFlagThread2);
        j3.join();
        j4.join();


        jthread j5(SemThread1);
        jthread j6(SemThread2);
        j5.join();
        j6.join();

        out<<endl;
    }
    out.close();

    auto a = method(varTimes);
    auto b = method(flagTimes);
    auto c = method(semTimes);
    auto [aa, ab, ac] = a;
    auto [ba, bb, bc] = b;
    auto [ca, cb, cc] = c;
    cout<<"условная переменная\n";
    cout<<"Среднее: "<<aa<<endl
         <<"Доверительный: "<<ab<<endl
         <<"Погрешность: "<<ac<<endl<<endl;

    cout<<"Два флага\n";
    cout<<"Среднее: "<<ba<<endl
         <<"Доверительный: "<<bb<<endl
         <<"Погрешность: "<<bc<<endl<<endl;

    cout<<"Семафор\n";
    cout<<"Среднее: "<<ca<<endl
         <<"Доверительный: "<<cb<<endl
         <<"Погрешность: "<<cc<<endl<<endl;
    return 0;
}

/*

условная переменная
Среднее: 38
Доверительный: 39.9919
Погрешность: 105.242

Два флага
Среднее: 39
Доверительный: 42.654
Погрешность: 109.369

Семафор
Среднее: 28
Доверительный: 12.0669
Погрешность: 43.0961

============================

условная переменная
Среднее: 35
Доверительный: 50.1754
Погрешность: 143.358

Два флага
Среднее: 23
Доверительный: 44.7641
Погрешность: 194.626

Семафор
Среднее: 28
Доверительный: 14.1694
Погрешность: 50.605

===========================

условная переменная
Среднее: 35
Доверительный: 40.7732
Погрешность: 116.495

Два флага
Среднее: 38
Доверительный: 70.7037
Погрешность: 186.062

Семафор
Среднее: 10
Доверительный: 11.5085
Погрешность: 115.085

*/

