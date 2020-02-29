#include "move.h"
#include <iostream>

int main(){
    using std::cout;
    using std::endl;
    Move obj1;
    cout << "default constructor:\n";
    obj1.showmove();
    Move obj2(12,53), obj3(34,64);
    cout << "constructor:\n";
    obj2.showmove();
    obj3.showmove();
    obj1 = obj2.add(obj3);
    cout << "add obj3 to obj2 and assign it to obj1:\n";
    obj1.showmove();
    return 0;
}
