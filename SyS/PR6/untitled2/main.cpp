//42 Найти колво слов с одинаковой буквой в начале и конце
//63 ввести k, изменить каждую букву на букву с номером + k (k=2, а->в г->е)
#include <iostream>
#include <string>
#include <sstream>


using namespace std;

int main()
{
    string line;
    string word;
    size_t temp = 0;
    cout<<"Строка: ";
    getline(cin, line);
    istringstream is(line);
    while(is){
        is>>word;
        is.ignore();
        if(tolower(word[0]) == tolower(word[word.size()-1])) temp++;
    }
    cout<<"Слов с одинаковой буквой в начале и конце: "<<temp;
    return 0;
}
