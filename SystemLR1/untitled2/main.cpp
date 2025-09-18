#include <iostream>
#include <thread>
#include <chrono>
#include <windows.h>

using namespace std;

/// \class NotWithThread
/// \brief Класс для выполнения операций с массивами без использования потоков
class NotWithThread{
public:
    std::chrono::duration<double> totalTime; /*!< Общее время выполнения всех операций */

    /// \def operator()
    /// \brief Оператор вызова функции для заполнения массива
    /// \param n Размер массива
    /// \return Указатель на новый массив со случайными числами
    int* operator()(int n) {
        auto start = chrono::steady_clock::now();
        int* result = new int[n];
        for (int i = 0; i < n; i++)
            result[i] = 1 + rand() % 10;
        auto end = chrono::steady_clock::now();
        cout << "\n(Функтор) Массив заполнен за "
             << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms";
        totalTime += end - start;
        return result;
    }

    /// \def Minimal
    /// \brief Находит минимальные элементы между двумя массивами без потоков
    /// \param m1 Первый массив
    /// \param m2 Второй массив
    /// \param n Размер массивов
    /// \return Указатель на измененный второй массив
    int* Minimal(int m1[], int m2[], int n) {
        auto start = chrono::steady_clock::now();
        for (int i = 0; i < n; i++)
            if(m1[i] < m2[i]) m2[i] = m1[i];
            else m2[i] = m2[i];
        auto end = chrono::steady_clock::now();
        cout << "\n(Метод) Минимальные элементы выбраны за "
             << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms";
        totalTime += end - start;
        return m2;
    }

    /// \def InsertSort
    /// \brief Сортирует массив методом вставок не используя потоки
    /// \param arr Массив для сортировки
    /// \param n Размер массива
    /// \return Указатель на отсортированный массив
    int* InsertSort(int arr[], int n) {
        auto start = chrono::steady_clock::now();
        auto lambda = [arr, n]() {
            int* sorted = new int[n];
            for (int i = 0; i < n; i++) sorted[i] = arr[i];
            for (int i = 1; i < n; i++)
                for (int j = i; j > 0 && sorted[j - 1] > sorted[j]; j--)
                    swap(sorted[j - 1], sorted[j]);
            return sorted;
        };
        int* res = lambda(); // последовательный вызов лямбды
        auto end = chrono::steady_clock::now();
        cout << "\n(Лямбда) Сортировка завершена за "
             << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms";
        totalTime += end - start;
        return res;
    }

};

/// \class WithThread
/// \brief Класс для выполнения операций с массивами с использованием потоков
class WithThread{
public:
    std::chrono::duration<double> totalTime; /*!< Общее время выполнения всех операций */

    /// \def operator()
    /// \brief Оператор вызова функции для заполнения массива
    /// \param n Размер массива
    /// \return Указатель на новый массив со случайными числами
    int* operator()(int n) {
        auto start = chrono::steady_clock::now();
        int* result = new int[n];
        for (int i = 0; i < n; i++)
            result[i] = 1 + rand() % 10;
        auto end = chrono::steady_clock::now();
        cout << "\n(Функтор) Массив заполнен за "
             << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;
        totalTime += end - start;
        return result;
    }

    /// \def Minimal
    /// \brief Находит минимальные элементы между двумя массивами с потоками
    /// \param m1 Первый массив
    /// \param m2 Второй массив
    /// \param n Размер массивов
    /// \return Указатель на измененный второй массив
    int* Minimal(int m1[], int m2[], int n) {
        auto start = chrono::steady_clock::now();
        thread t([&]() {
            for (int i = 0; i < n; i++)
                m2[i] = (m1[i] < m2[i]) ? m1[i] : m2[i];
        });
        t.join();
        auto end = chrono::steady_clock::now();
        cout << "\n(Метод) Минимальные элементы выбраны за "
             << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms";
        totalTime += end - start;
        return m2;
    }

    /// \def InsertSort
    /// \brief Сортирует массив методом вставок используя потоки
    /// \param arr Массив для сортировки
    /// \param n Размер массива
    /// \return Указатель на отсортированный массив
    int* InsertSort(int arr[], int n) {
        int* sorted = new int[n];
        for (int i = 0; i < n; i++) sorted[i] = arr[i];

        auto start = chrono::steady_clock::now();
        auto lambda = [sorted, n]() {
            for (int i = 1; i < n; i++)
                for (int j = i; j > 0 && sorted[j - 1] > sorted[j]; j--)
                    swap(sorted[j - 1], sorted[j]);
        };
        thread t(lambda);
        t.join();
        auto end = chrono::steady_clock::now();
        cout << "\n(Лямбда) Сортировка завершена за "
             << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms";
        totalTime += end - start;
        return sorted;
    }
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    srand(time(0));
    NotWithThread NWT;
    WithThread WT;
    int n;

    cout<<"Размер массива: ";
    cin>>n;
    int* M1 = new int[n];
    int* M2 = new int[n];
    int* M1t = new int[n];
    int* M2t = new int[n];

    cout << "\n--------Без потоков--------" << endl;
    M1 = NWT(n);
    cout << "\nM1: ";
    for (int i = 0; i < n; i++) cout << M1[i] << " ";
    M2 = NWT(n);
    cout << "\nM2: ";
    for (int i = 0; i < n; i++) cout << M2[i] << " ";
    M2 = NWT.Minimal(M1, M2, n);
    cout << "\nM2: ";
    for (int i = 0; i < n; i++) cout << M2[i] << " ";
    M2 = NWT.InsertSort(M2, n);
    cout << "\nM2: ";
    for (int i = 0; i < n; i++) cout << M2[i] << " ";
    cout << "\nВсего времени: "
         << chrono::duration_cast<chrono::milliseconds>(NWT.totalTime).count() << "ms\n";

    cout << "\n--------С потоками--------" << endl;
    thread t1([&]() { M1t = WT(n); });
    cout << "\nM1: ";
    t1.join();
    for (int i = 0; i < n; i++) cout << M1t[i] << " ";
    thread t2([&]() { M2t = WT(n); });
    cout << "\nM2: ";
    t2.join();
    for (int i = 0; i < n; i++) cout << M2t[i] << " ";
    M2t = WT.Minimal(M1t, M2t, n);
    cout << "\nM2: ";
    for (int i = 0; i < n; i++) cout << M2t[i] << " ";
    M2t = WT.InsertSort(M2t, n);
    cout << "\nM2: ";
    for (int i = 0; i < n; i++) cout << M2t[i] << " ";
    cout << "\nВсего времени: "
         << chrono::duration_cast<chrono::milliseconds>(WT.totalTime).count() << "ms\n";

    return 0;
}
