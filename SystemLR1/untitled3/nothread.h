#ifndef NOTHREAD_H
#define NOTHREAD_H
#include <vector>
#include <chrono>
#include <iostream>
#include <random>

class NoThread
{
public:
    NoThread(int);
    void CreateArs();
    void Minimal();
    void InsertSort();
    void Output();
    std::chrono::duration<double> totalTime;

private:
    std::vector<int> ar1;
    std::vector<int> ar2;
};

#endif // NOTHREAD_H
