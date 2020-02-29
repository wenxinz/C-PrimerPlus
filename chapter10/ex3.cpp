#include "golf.h"
#include <iostream>

int main(){
    using std::cout;
    using std::endl;
    Golf obj1;
    obj1.showgolf();
    cout << endl;
    Golf obj2("Ann Birdfree",24);
    obj2.showgolf();
    cout << endl;
    obj1.setgolf();
    obj1.showgolf();
    cout << endl;
    obj2.rehandicap(54);
    obj2.showgolf();
    return 0;
}
