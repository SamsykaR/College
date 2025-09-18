#include <iostream>
#include <thread>
#include <chrono>
#include <windows.h>

using namespace std;

class NotWithThread{
public:
    std::chrono::duration<double> totalTime;
    //Сформировать 2 массива М1 и М2 случайных действительных чисел
    int* RandomArray(int m[], int n){
        auto start = chrono::steady_clock::now();
        int* M = new int[n];
        for (int i = 0; i < n; i++)
            M[i] = 1 + rand() % 10;
        auto end = chrono::steady_clock::now();
        std::chrono::duration<double> diff = end - start;
        cout << "\nМассив заполнен. " <<chrono::duration_cast<chrono::milliseconds>(diff).count() << "ms";
        totalTime += diff;
        return M;
    }

    // массивах М1 и М2 ко всем элементами с одинаковыми индексами попарно применить операцию из таблицы (результат записать в М2): выбор меньшего
    int* Minimal(int m1[], int m2[], int n){
        auto start = chrono::steady_clock::now();
        for (int i = 0; i < n; i++){
            if(m2[i]<m1[i]) m2[i] = m2[i];
            else if(m1[i]<m2[i]) m2[i] = m1[i];
            else m2[i] = m2[i];
        }
        auto end = chrono::steady_clock::now();
        std::chrono::duration<double> diff = end - start;
        cout<< "\nМинимальные элементы: ";
        for(int i=0; i<n; i++) cout<<m2[i]<<" ";
        cout <<"  "<<chrono::duration_cast<chrono::milliseconds>(diff).count() << "ms";
        totalTime += diff;
        return m2;
    }

    //Полученный массив необходимо отсортировать методом, указанным в таблице: сортировка вставками
    int* InsertSort(int m2[], int n){
        auto start = chrono::steady_clock::now();
        int* m = new int[n];
        for (int i = 0; i < n; i++)
            m[i] = m2[i];
        for(int i=1;i<n;i++)
            for(int j=i;j>0 && m[j-1]>m[j];j--)
                swap(m[j-1],m[j]);
        auto end = chrono::steady_clock::now();
        std::chrono::duration<double> diff = end - start;
        cout<< "\nОтсортированный массив: ";
        for(int i=0; i<n; i++) cout<<m[i]<<" ";
        cout <<"  "<<chrono::duration_cast<chrono::milliseconds>(diff).count() << "ms";
        totalTime += diff;
        return m;
    }
};

class WithThread{
public:
    std::chrono::duration<double> totalTime;
    //Сформировать 2 массива М1 и М2 случайных действительных чисел
    int* RandomArray(int m[], int n){
        auto start = chrono::steady_clock::now();
        int* M = new int[n];
        for (int i = 0; i < n; i++)
            M[i] = 1 + rand() % 10;
        auto end = chrono::steady_clock::now();
        std::chrono::duration<double> diff = end - start;
        cout << "\nМассив заполнен. " <<chrono::duration_cast<chrono::milliseconds>(diff).count() << "ms";
        totalTime += diff;
        return M;
    }

    // массивах М1 и М2 ко всем элементами с одинаковыми индексами попарно применить операцию из таблицы (результат записать в М2): выбор меньшего
    int* Minimal(int m1[], int m2[], int n){
        auto start = chrono::steady_clock::now();
        for (int i = 0; i < n; i++){
            if(m2[i]<m1[i]) m2[i] = m2[i];
            else if(m1[i]<m2[i]) m2[i] = m1[i];
            else m2[i] = m2[i];
        }
        auto end = chrono::steady_clock::now();
        std::chrono::duration<double> diff = end - start;
        cout<< "\nМинимальные элементы: ";
        for(int i=0; i<n; i++) cout<<m2[i]<<" ";
        cout <<"  "<<chrono::duration_cast<chrono::milliseconds>(diff).count() << "ms";
        totalTime += diff;
        return m2;
    }

    //Полученный массив необходимо отсортировать методом, указанным в таблице: сортировка вставками
    int* InsertSort(int m2[], int n){
        auto start = chrono::steady_clock::now();
        int* m = new int[n];
        for (int i = 0; i < n; i++)
            m[i] = m2[i];
        for(int i=1;i<n;i++)
            for(int j=i;j>0 && m[j-1]>m[j];j--)
                swap(m[j-1],m[j]);
        auto end = chrono::steady_clock::now();
        std::chrono::duration<double> diff = end - start;
        cout<< "\nОтсортированный массив: ";
        for(int i=0; i<n; i++) cout<<m[i]<<" ";
        cout <<"  "<<chrono::duration_cast<chrono::milliseconds>(diff).count() << "ms";
        totalTime += diff;
        return m;
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

    cout<< "--------Без потоков--------"<<endl;

    M1 = NWT.RandomArray(M1, n);
    cout<<"\nM1: ";
    for(int i=0; i<n; i++) cout<<M1[i]<<" ";
    M2 = NWT.RandomArray(M2, n);
    cout<<"\nM2: ";
    for(int i=0; i<n; i++) cout<<M2[i]<<" ";

    M2 = NWT.Minimal(M1, M2, n);

    M2 = NWT.InsertSort(M2, n);

    cout<< "\nВсего времени:" <<  chrono::duration_cast<chrono::milliseconds>(NWT.totalTime).count() << "ms" <<endl;

    return 0;
}
