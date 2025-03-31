#include "computer.h"

Computer::Computer()
{

}
Computer::Computer(float CPUFrequency_, float memory_, float memoryForSystem_)
    : CPUFrequency(CPUFrequency_), memory(memory_), memoryForSystem(memoryForSystem_){}

float Computer::FreememoryProcent(){
    return (memory-memoryForSystem)/100;
}
bool Computer::FreeMemoryIsCool(float Procet){
    if(FreememoryProcent()>=Procet) return true;
    else return false;
}
float Computer::Formula(int a, int b){
    if(CPUFrequency<)
}
