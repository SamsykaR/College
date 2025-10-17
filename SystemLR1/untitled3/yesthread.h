#ifndef YESTHREAD_H
#define YESTHREAD_H
#include <vector>
#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
#include <random>

class YesThread
{
public:
    YesThread(int);
    void CreateArs();
    void Minimal();
    void InsertSort();
    void Output();
    std::chrono::duration<double> totalTime;

private:
    std::vector<int> ar1;
    std::vector<int> ar2;
    void CreateArr(std::vector<int>&);
};

#endif // YESTHREAD_H
