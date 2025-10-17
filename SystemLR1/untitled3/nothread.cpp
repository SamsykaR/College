#include "nothread.h"

using namespace std;

NoThread::NoThread(int n):
    ar1(n),
    ar2(n){};

//Сформировать 2 массива М1 и М2 случайных действительных чисел
void NoThread::CreateArs(){
    auto start = chrono::high_resolution_clock::now();
    int seed = chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine rnd(seed);
    std::uniform_int_distribution<int> d(0, 10);
    for (int i = 0; i < ar1.size(); i++)
        ar1[i] = 1 + d(rnd) % 10;
    for (int i = 0; i < ar2.size(); i++)
        ar2[i] = 1 + d(rnd) % 10;
    auto end = chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    totalTime += diff;
    cout << "\nArrays ready. " <<chrono::duration_cast<chrono::microseconds>(diff).count() << "mcs";
}

// массивах М1 и М2 ко всем элементами с одинаковыми индексами попарно применить операцию из таблицы (результат записать в М2): выбор меньшего
void NoThread::Minimal(){
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < ar1.size(); i++){
        if(ar2[i]<ar1[i]) ar2[i] = ar2[i];
        else if(ar1[i]<ar2[i]) ar2[i] = ar1[i];
        else ar2[i] = ar2[i];
    }
    auto end = chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    totalTime += diff;
    cout <<"\nMinimals find. "<<chrono::duration_cast<chrono::microseconds>(diff).count() << "mcs";
}

//Полученный массив необходимо отсортировать методом, указанным в таблице: сортировка вставками
void NoThread::InsertSort(){
    int key, i, j;
    auto start = chrono::high_resolution_clock::now();
    for (i = 1; i < ar2.size(); i++) {
        key = ar2[i];
        j = i - 1;
        while (j >= 0 && ar2[j] > key) {
            ar2[j + 1] = ar2[j];
            j = j - 1;
        }
        ar2[j + 1] = key;
    }
    auto end = chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    totalTime += diff;
    cout <<"\nSorted. "<<chrono::duration_cast<chrono::microseconds>(diff).count() << "mcs";
}

void NoThread::Output(){
    cout<< "\nArray1: ";
    for(int i=0; i<ar1.size(); i++) cout<<ar1[i]<<" ";
    cout<< "\nArray2: ";
    for(int i=0; i<ar1.size(); i++) cout<<ar2[i]<<" ";
}

