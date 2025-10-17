#include <iostream>
#include <future>
#include <vector>
#include <random>
#include <map>
#include <sstream>

using namespace std;

//Задание 1
//Вариант 18
//Ввести в Memo вещественные числа. Создать из них массив. Вычислить
//произведение минимального и максимального элементов
/// \brief Генерирует вектор случайных вещественных чисел
/// \param size Размер вектора
/// \return Вектор случайных вещественных чисел
vector<double> RandomVector(int size){
    vector<double> arr;
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dist(1.0, 100.0);

    for (int i = 0; i < size; i++) {
        arr.push_back(dist(gen));
    }
    return arr;
}

/// \brief Находит минимальный элемент в векторе
/// \param vec Вектор вещественных чисел
/// \return Минимальное значение
double Min(const vector<double> &vec){
    double m = vec[0];
    for(int i=1; i<vec.size(); i++) m = std::min(m, vec[i]);
    return m;
}

/// \brief Находит максимальный элемент в векторе
/// \param vec Вектор вещественных чисел
/// \return Максимальное значение
double Max(const vector<double> &vec){
    double m = vec[0];
    for(int i=1; i<vec.size(); i++) m = std::max(m, vec[i]);
    return m;
}


//Задание 2
//Дана строка с числами введёнными латиницей, определить наибольшее число по числовому значению

map<string, int> Nums {
    {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}, {"ten", 10}
}; ///<Словарь для преобразования числительных в числа

/// \brief Находит максимальный элемент в векторе целых чисел
/// \param vec Вектор целых чисел
/// \return Максимальное значение
int Maxint(const vector<int> &vec){
    int m = vec[0];
    for(int i=1; i<vec.size(); i++) m = std::max(m, vec[i]);
    return m;
}

/// \brief Находит максимальное число в строке
/// \param str Строка с числами
/// \return Строковое представление максимального числа
string FindMaxStr(const string &str){
    vector<int> ar;
    string word;
    stringstream ss(str);
    while(ss >> word){
        ar.push_back(Nums[word]);
    }
    string max;
    for(auto el:Nums){
        if(el.second == Maxint(ar)){
            max = el.first;
            break;
        }
    }
    return max;
}

int main()
{
    vector<double> arr = RandomVector(10);
    auto minF = async(launch::async, Min, arr);
    auto maxF = async(launch::async, Max, arr);
    cout << "Массив: ";
    for (double num : arr) {
        cout << num << " ";
    }
    cout << std::endl;
    auto mi = minF.get();
    auto ma = maxF.get();
    cout << "Произведение минимального и максимального: " << mi*ma << "( " <<mi<<", "<<ma<<" )"<<endl<<endl;

    string str = "one two three five four ten";
    cout << "Массив: "<< str;
    auto maxStr = async(launch::async, FindMaxStr, str);
    cout << std::endl;
    cout << "Максимальный элемент: " << maxStr.get();
    return 0;
}
