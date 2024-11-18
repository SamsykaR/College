#include <iostream>
#include <ctime>
#include <random>

using namespace std;
int* InitMas(int);
int** InitMatr(int);
int* InputMas(int*, int);
int** InputMatr(int**, int);
void OutputAll(int*, int**, int);
void AddZero(int*, int);
void DeleteZero(int**, int);
int Rand();

int main()
{
    setlocale(LC_ALL, "RU");
    int* massive = nullptr;
    int** matrix = nullptr;
    int n = 5;
    int k = 0;
    do
    {
        cout << "1. Формирование массива\n";
        cout << "2. Печать массива\n";
        cout << "3. Удаление из массива\n";
        cout << "4. Добавление в массив\n";
        cout << "5. Выход\n";
        cin >> k;
        switch (k)
        {
            case 1:
            cout << "Размер массива: ";
            cin >> n;
                massive = InitMas(n);
                matrix = InitMatr(n);
                InputMas(massive, n);
                InputMatr(matrix, n);
            break; //выделение памяти и заполнение

            case 2:
                OutputAll(massive, matrix, n);
            break; //печать

            case 3: DeleteZero(matrix, n); break; //удаление

            case 4: AddZero(massive, n); break; //добавление
        }
    }while (k!=5); //выход
    delete []massive;
    for(int i=0; i<n; i++) delete matrix[i];
    delete []matrix;
    return 0;
}
///////////////////////////////////////////////////////////////////////
int Rand() {
    static default_random_engine rnd(time(0));
    static uniform_int_distribution<int> d(0, 9);
    return d(rnd);
}
int* InitMas(int n) {
    int* mas = new int[n];
    return mas;
}
int** InitMatr(int n) {
    int** matr = new int* [n];
    for (int i = 0; i < n; i++) matr[i] = new int[n];
    return matr;
}
int* InputMas(int* mas, int n) {
    for (int i = 0; i < n; i++) mas[i] = Rand();
    return mas;
}
int** InputMatr(int** mas, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) mas[i][j] = Rand();
    }
    return mas;
}
void OutputAll(int* mas, int** matr, int n) {
    cout << "Массив: ";
    for (int i = 0; i < n; i++) cout << mas[i] << " ";
    cout << endl;
    cout << "Матрица: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << matr[i][j] << " ";
        cout << endl;
    }
}
void AddZero(int* mas, int n) {
    int zero = 0;
    for (int i = 0; i < n; i++) {
        if (mas[i] % 2 == 0) {
            zero++;
        }
    }
    int* newmas = new int[n + zero];
    int j = 0; 
    for (int i = 0; i < n; i++) {
        newmas[j++] = mas[i];
        if (mas[i] % 2 == 0) {
            newmas[j++] = 0;
        }
    }

    cout << "Новый массив с нулями: ";
    for (int i = 0; i < j; i++) {
        cout << newmas[i] << " ";
    }
    cout << endl;
    delete[] newmas;
}
void DeleteZero(int** matr, int n) {
    int zeroline = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matr[i][j] == 0) {
                zeroline++;
                break;
            }
        }
    }
    int** newmatr = new int*[n-zeroline];
    for (int i = 0; i < n-zeroline; i++) {
        newmatr[i] = new int[n];
    }
    int ind = 0;
    bool temp;
    for (int i = 0; i < n; i++) {
        temp = false;
        for (int j = 0; j < n; j++) {
            if (matr[i][j] == 0) {
                temp = true;
                break;
            }
        }
        if (temp) continue;
        for (int j = 0; j < n; j++) {
            newmatr[ind][j] = matr[i][j];
        }
        ind++;
    }

    cout << "Новая матрица без нулей: \n";
    for (int i = 0; i < n-zeroline; i++) {
        for (int j = 0; j < n; j++) {
            cout << newmatr[i][j]<<" ";
        }
        cout << endl;
    }
    for (int i = 0; i < n-zeroline; i++) delete newmatr[i];
    delete[]newmatr;
}
#include <iostream>
#include <ctime>
#include <random>

using namespace std;
int* InitMas(int);
int** InitMatr(int);
int* InputMas(int*, int);
int** InputMatr(int**, int);
void OutputAll(int*, int**, int);
int Rand();

int main()
{

    int* massive = nullptr;
    int** matrix = nullptr;
    cout << "Размер массива: ";
    int n = 5;
    cin >> n;
    massive = InitMas(n);
    InputMas(massive, n);
    matrix = InitMatr(n);
    InputMatr(matrix, n);
    OutputAll(massive, matrix, n);
    int k = 0;
    /*do
    {
        cout << "1. Формирование массива\n";
        cout << "2. Печать массива\n";
        cout << "3. Удаление из массива\n";
        cout << "4. Добавление в массив\n";
        cout << "5. Выход\n";
        cin >> k;
        switch (k)
        {
            case 1:
            cout << "Размер массива: ";
            cin >> n;
                //massive = InitMas(n);
                //matrix = InitMatr(n);
                //InputMas(massive, n);
                //InputMatr(matrix, n);
            break; //выделение памяти и заполнение

            case 2:
                //OutputAll(massive, matrix, n);
            break; //печать

            case 3:  break; //удаление

            case 4:  break; //добавление
        }
    }while (k!=5); //выход*/
    /*delete []massive;
    for(int i=0; i<n; i++) delete []matrix;
    delete []matrix;*/
    return 0;
}
int Rand(){
    static default_random_engine rnd(time(0));
    static uniform_int_distribution<int> d(0, 9);
    return d(rnd);
}
int* InitMas(int n){
    int* mas = new int[n];
    return mas;
}
int** InitMatr(int n){
    int** matr = new int*[n];
    for(int i=0; i<n; i++) matr[i] = new int[n];
    return matr;
}
int* InputMas(int *mas, int n){
    for(int i=0; i<n; i++) mas[i] = Rand();
    return mas;
}
int** InputMatr(int **mas, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) mas[i][j] = Rand();
    }
    return mas;
}
void OutputAll(int* mas, int** matr, int n){
    cout<<"Массив: ";
    for(int i=0; i<n; i++) cout<<mas[i]<<" ";
    cout<<endl;
    cout<<"Матрица: \n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cout<<matr[i][j]<<" ";
        cout<<endl;
    }
}
