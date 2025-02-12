/*************************************************************************
**************************************************************************
** Практическая работа № 8                                              **
** Задание № 1А                                                         **
** Класс point с двумя точками и выводом значений точек               	**
** Задание № 1Б                                                         **
** Создать метод для вычисления расстояния между двумя точками          **
** Задание № 1С                                                         **
** Изменить предыдущий метод что бы он стал дружественным и принимал    **
** два аргумента                                                        **
**                                                                      **
** Задание № 2                                                       	**
** Создать деструктор для приведённого в задании класса                 **
**                                                                      **
** Выполнил: студент 3 курса ЕПК гр. И-32                               **
** Самсыка Р.                                                           **
**                                                                      **
** Проверил: преподаватель специальных дисциплин                        **
** Фомин А. Т.                                                          **
**************************************************************************
*************************************************************************/




#include <iostream>
#include <cmath>
using namespace std;

class Point{ //№1a
private:
    double m_a;
    double m_b;
public:
    Point(double a, double b){
        m_a = a;
        m_b = b;
    }
    Point(){
        m_a = 0;
        m_b = 0;
    }
    void Print(){
        cout<<"Point("<<m_a<<", "<<m_b<<")"<<endl;
    }
    double distanceTo(Point p2){ //b
        return sqrt((m_a - p2.m_a) * (m_a - p2.m_a) + (m_b - p2.m_b) * (m_b - p2.m_b));
    }
    friend double distanceFrom(Point p1, Point p2){ //c
        return sqrt((p1.m_a - p2.m_a) * (p1.m_a - p2.m_a) + (p1.m_b - p2.m_b) * (p1.m_b - p2.m_b));
    }
};

class Welcome{
private:
    char *m_data;

public:
    Welcome(){
        m_data = new char[14];
        const char *init = "Hello, World!";
        for(int i=0; i<14; ++i)
            m_data[i] = init[i];
    }
    void print(){
        cout<<m_data<<endl;
    }
    ~Welcome(){
        delete[] m_data;
        cout<<"all objects have deleted"<<endl;
    }
};

int main()
{
    cout<<"№1"<<endl;
    Point first;
    Point second(2.0, 5.0);
    first.Print();
    second.Print();
    cout << "DistanceTo = "<< first.distanceTo(second)<<endl; //b
    cout << "DistanceFrom = "<< distanceFrom(first, second)<<endl; //c

    cout<<"\n№2"<<endl;
    Welcome hello;
    hello.print();

    return 0;
}

/*
№1
Point(0, 0)
Point(2, 5)
DistanceTo = 5.38516
DistanceFrom = 5.38516

№2
Hello, World!
all objects have deleted
*/
