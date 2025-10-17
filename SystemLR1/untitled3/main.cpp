#include <iostream>
#include "nothread.h"
#include "yesthread.h"

using namespace std;

int main()
{
    int n;
    std::mutex mut;
    cout<<"Length: ";
    cin>>n;
    NoThread NT(n);
    YesThread YT(n);

    cout<<"\nNo threads: ";
    NT.CreateArs();
    //NT.Output();
    NT.Minimal();
    NT.InsertSort();
    //NT.Output();
    cout << "\nTime: " << chrono::duration_cast<chrono::microseconds>(NT.totalTime).count() << "mcs";

    cout<<"\n\nYes threads: ";
    YT.CreateArs();
    //YT.Output();
    YT.Minimal();
    YT.InsertSort();
    //YT.Output();
    cout << "\nTime: " << chrono::duration_cast<chrono::microseconds>(YT.totalTime).count() << "mcs";
    return 0;
}
