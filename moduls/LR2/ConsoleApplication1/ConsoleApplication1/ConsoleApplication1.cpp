#include "Methods.h"
#include <iostream>
#include <exception>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    int temp;
    do {
        try {
            cout << "размер массива: ";
            cin >> temp;
            if (temp <= 0)throw ArrayException("Длина не может быть меньше или равна 0");
            break;
        }
        catch (out_of_range &ex) {
            cerr << "Проблемы с границей (" << ex.what() << ")" << endl;
            continue;
        }
        catch (ArrayException& ex) {
            cerr << "Проблемы с массивом (" << ex.what() << ")" << endl;
            continue;
        }
        catch (exception& ex) {
            cerr << "Неизвестная ошибка (" << ex.what() << ")" << endl;
            continue;
        }
    } while (true);
    ArrayMethods array(temp);

    do {
        try {
            cout << "Добавьте новый элемент ";
            cin >> temp;
            break;
        }
        catch (out_of_range& ex) {
            cerr << "Проблемы с границей (" << ex.what() << ")" << endl;
            continue;
        }
        catch (ArrayException& ex) {
            cerr << "Проблемы с массивом (" << ex.what() << ")" << endl;
            continue;
        }
        catch (exception& ex) {
            cerr << "Неизвестная ошибка (" << ex.what() << ")" << endl;
            continue;
        }
    } while (true);
    array.Add(temp);

    do {
        try {
            cout << "Индекс элемента для вывода: ";
            cin >> temp;
            if (temp<0 || temp>array.Length()) throw SizeNotrange("максимальная длина: ", array.Length());
            break;
        }
        catch (SizeNotrange& ex) {
            cerr << "Исправьте ввод (" << ex.what() << ")" << endl;
            continue;
        }
        catch (exception& ex) {
            cerr << "Исправьте ввод (" << ex.what() << ")" << endl;
            continue;
        }
    } while (true);
    cout<<array.at(temp)<<endl;

    do {
        try {
            cout << "Индекс элемента для удаления: ";
            cin >> temp;
            if (temp<0 || temp>array.Length()) throw SizeNotrange("максимальная длина: ", array.Length());
            break;
        }
        catch (SizeNotrange& ex) {
            cerr << "Исправьте ввод (" << ex.what() << ")"<<endl;
            continue;
        }
        catch (exception& ex) {
            cerr << "Исправьте ввод (" << ex.what() << ")" << endl;
            continue;
        }
    } while (true);
    array.Remove(temp);

    try {
        cout << "Остальная характеристика:" << endl;
        cout << "массив: ";
        array.print();
        cout << "Длина: " << array.Length() << endl;
        cout << "Максимальное: " << array.Max() << endl;
        cout << "Минимальное: " << array.Min() << endl;
        cout << "Среднее арифметическое: " << array.Sr() << endl;
        cout << "Сортировка по возрастанию: ";
        array.SortUp();
        array.print();
        cout << "Сортировка по убыванию: ";
        array.SortDown();
        array.print();
    }
    catch (out_of_range& ex) {
        cerr << "Проблемы с границей (" << ex.what() << ")" << endl;
    }
    catch (ArrayException& ex) {
        cerr << "Проблемы с массивом (" << ex.what() << ")" << endl;
    }
    catch (exception& ex) {
        cerr << "Неизвестная ошибка (" << ex.what() << ")" << endl;
    }
    
    return 0;
}
