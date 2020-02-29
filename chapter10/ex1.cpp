#include <iostream>
#include "bankaccount.h"

int main(){
    using std::cout;
    using std::endl;
    bankaccount def;
    def.display();
    cout << endl;
    bankaccount test1("test1","x00000");
    test1.display();
    cout << endl;
    bankaccount test2("test2","x00001",34.0);
    test2.display();
    test2.deposit(12.0);
    test2.display();
    test2.withdraw(24.0);
    test2.display();
    test2.withdraw(54.0);
    return 0;
}

