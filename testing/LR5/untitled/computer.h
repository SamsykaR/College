#ifndef COMPUTER_H
#define COMPUTER_H
class Computer {
private:
    float CPUFrequency;
    float memory;
    float memoryForSystem;
public:
    Computer(float CPUfrequency_, float memory_, float memoryForSystem_);
    Computer();
    ~Computer();

    float FreememoryProcent();
    bool FreeMemoryIsCool(float procent);
    float Formula(int a, int b);
};
#endif // COMPUTER_H
