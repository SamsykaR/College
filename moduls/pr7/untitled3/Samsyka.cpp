/*************************************************************************
**************************************************************************
** Практическая работа № 7                          			**
** Задание № 1А                                     			**
** Класс Ball с полями цвет и радиус. Создать конструкторы только для 	**
** цвета, только для радиуса, для двух параметров и без параметров  	**
** Задание № 1Б                                     			**
** Уменьшить число конструкторов добавить конструкторы с параметрами по	**
** умолчанию								**
**									**
** Задание № 2А                                     			**
** Класс с тремя числами, сделать метод для заполнения этих чисел и 	**
** вывода								**
** Задание № 2Б                                     			**
** Добавить метод для определения двух экземпляров класса на равенство	**
**                                                  			**
** Выполнил: студент 3 курса ЕПК гр. И-32           			**
** Самсыка Р.                                       			**
**                                                  			**
** Проверил: преподаватель специальных дисциплин    			**
** Фомин А. Т.                                      			**
**************************************************************************
*************************************************************************/



#include <iostream>

using namespace std;

/*
Задание 1А
class Ball{
private:
    string color;
    double radius;

public:
    Ball(){
        color = "red";
        radius = 20.0;
    }
    Ball(string c){
        color = c;
        radius = 20.0;
    }
    Ball(double r){
        color = "red";
        radius = r;
    }
    Ball(string c, double r){
        color = c;
        radius = r;
    }
    void Print(){
        cout<<"color: "<< color <<"   radius: "<< radius<<endl;
    }
};*/


//Задание 1Б
class Ball{
private:
    string color;
    double radius;

public:
    Ball(string c = "red", double r = 20.0){
        color = c;
        radius = r;
    }
    Ball(double r){
        color = "red";
        radius = r;
    }
    void Print(){
        cout<<"color: "<< color <<"   radius: "<< radius<<endl;
    }
};



// Задание 2А
class Numbers{
private:
    double m_a;
    double m_b;
    double m_c;

public:
    void SetValues(double a, double b, double c){
        m_a = a;
        m_b = b;
        m_c = c;
    }

    void Print(){
        cout<< "<"<<m_a<<", "<<m_b<<", "<<m_c<<"> "<<endl;
    }

    //Задание 2Б
    bool isEqual(Numbers num2){
        if(num2.m_a == m_a && num2.m_b == m_b && num2.m_c == m_c) return true;
        else return false;
    }
};





int main()
{
    /*
    Задание 1
    Ball def;
    def.Print();

    Ball black("black");
    black.Print();

    Ball thirty(30.0);
    thirty.Print();

    Ball thirtyblack("black", 30.0);
    thirtyblack.Print();*/

    //Задание 2
    /*Numbers point;
    point.SetValues(3.0, 4.0, 5.0);
    point.Print();*/

    Numbers point;
    point.SetValues(3.0, 4.0, 5.0);
    Numbers point2;
    point2.SetValues(3.0, 4.0, 5.0);

    if(point.isEqual(point2)){
        cout<<"point1 equal point2"<<endl;
    }
    else cout<<"point1 not equal point2"<<endl;

    Numbers point3;
    point2.SetValues(7.0, 8.0, 9.0);

    if(point.isEqual(point3)){
        cout<<"point1 equal point3"<<endl;
    }
    else cout<<"point1 not equal point3"<<endl;

    return 0;
}
