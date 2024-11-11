#include <iostream>
#include <array>
#include <random>
#include <ctime>
#include "digit.h"

using namespace std;

int Random(){
    static default_random_engine rnd(time(0));
    static uniform_int_distribution<int> d(-10, 10);
    return d(rnd);
}
array<int, 15>& MAssive(array<int, 15>& ar){
    for(size_t i{0}; i<ar.size(); ++i) ar[i] = Random();
    return ar;
}
void& Out(array<int, 15>& ar){
    for(size_t i{0}; i<ar.size(); ++i) cout<< ar[i] << " ";
}
void Task17(array<int, 15>& ar){
    size_t mins {0};
    size_t nul {0};
    int multiple {1};
    for(int el:ar){
        if(el == 0) ++nul;
        else if (el < 0) ++ mins;
        else multiple *= el;
    }
    cout << " отрицательные: "<< mins <<"\n нули: "<<nul<<"\n произведение: "<<multiple;
}
