/*!
 * \brief Практическая работа №1
 * \details Генерация массива случайных чисел;
 *          разместить в массиве сначала чётные, затем нечётные элементы;
 *          сортировка вставками.
 *          Блокировка используя 2 атомарных флага
 * \author  Самсыка Р. М. И-42 группы
 * \version 0.1
 * \date 23.10.25
 * \copyright GNU Public License.
 */

#include <iostream>
#include <vector>
#include <thread>
#include <condition_variable>
#include <chrono>
#include <random>

using namespace std;


vector<int> ar(1000);
condition_variable cv;
atomic_flag F1{}, F2{};

void Array() {
    F1.wait(false);
    F1.clear();
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10);

    for (int i = 0; i < ar.size(); i++) {
        ar[i] = dis(gen);
    }

    cout << "Массив: ";
    //for (int num : ar) cout << num << " ";
    //cout << endl;

    F2.test_and_set();
    F2.notify_one();

    F2.wait(false);
    F1.wait(false);

    vector<int> no;
    vector<int> yes;
    for(int i=0; i<ar.size(); i++){
        if(ar[i]%2 == 0) yes.push_back(ar[i]);
        else no.push_back(ar[i]);
    }
    ar.clear();
    for(int i=0; i<yes.size(); i++){
        ar.push_back(yes[i]);
    }
    for(int i=0; i<no.size(); i++){
        ar.push_back(no[i]);
    }

    cout << "Перестановка: ";
    //for (int num : ar) cout << num << " ";
    //cout << endl;
}

void InsertionSort()
{
    F2.wait(false);
    F2.clear();
    int i, key, j;
    for (i = 1; i < ar.size(); i++) {
        key = ar[i];
        j = i - 1;
        while (j >= 0 && ar[j] > key) {
            ar[j + 1] = ar[j];
            j = j - 1;
        }
        ar[j + 1] = key;
    }

    cout << "Сортировка: ";
    //for (int num : ar) cout << num << " ";
    //cout << endl;
    F1.test_and_set();
    F1.notify_one();
}

int main()
{
    auto start = chrono::high_resolution_clock::now();
    F1.test_and_set();
    F2.clear();
    jthread j1(Array);
    jthread j2(InsertionSort);
    j1.join();
    j2.join();
    auto elapsed = std::chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start);
    cout<< elapsed << endl;
    return 0;
}

//Обычный вывод 20 элементов
/*
Массив: 2 4 10 2 10 9 9 7 5 6 4 5 10 7 5 4 4 1 2 2
Сортировка: 1 2 2 2 2 4 4 4 4 5 5 5 6 7 7 9 9 10 10 10
Перестановка: 2 2 2 2 4 4 4 4 6 10 10 10 1 5 5 5 7 7 9 9
 */

//1000 элементов
//Массив: Сортировка: Перестановка: 8051326ns
