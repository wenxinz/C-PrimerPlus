#include "plorg.h"
#include <iostream>

int main(){
    using std::cout;
    Plorg pl1, pl2("happy plorga");
    cout << "pl1:\n";
    pl1.report();
    cout << "pl2:\n";
    pl2.report();
    cout << "change CI of pl1 to 100:\n";
    pl1.changeCI(100);
    pl1.report();
    return 0;
}   
