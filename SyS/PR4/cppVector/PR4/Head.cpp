#include <chrono>
#include <vector>
#include <random>
#include <iostream>
#include "Head.h"
using namespace std::chrono;

std::vector<int> MasIn(std::vector<int> vec){
    for(size_t i{0}; i<vec.size(); i++) vec[i]=Random();
    return vec;
}

int Random(){
    long seed = system_clock::now().time_since_epoch().count();
    static std::default_random_engine rnd(seed);
    static std::uniform_int_distribution<int> d(1, 9);
    //std::cout << d(rnd) << std::endl;
    return d(rnd);
}

void Out(std::vector<int>& vec){
    for(size_t i{0}; i<vec.size(); ++i) cout<< vec[i] <<" ";
}

void LocalMin(std::vector<int> vec){
    size_t c{0};
    for(size_t i{1}; i<vec.size()-1; i++){
        if(vec.at(i)<vec.at(i-1) && vec.at(i)<vec.at(i+1)) c++;
    }
    std::cout <<"\n Локальных минимумов: "<<c;
}
