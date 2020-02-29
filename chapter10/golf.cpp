#include "golf.h"
#include <cstring>
#include <iostream>

Golf::Golf(){
    std::strcpy(fullname,"\0");
    handicap = 0;
}

Golf::Golf(const char * name, int hc){
    std::strncpy(fullname,name,Len);
    handicap = hc;
}

int Golf::setgolf(){
    using std::cout;
    using std::cin;
    char name[Len];
    int hc;
    cout << "enter fullname: ";
    cin.get(name,Len);
    if(!cin.fail()){
        cout << "enter handicap: ";
        (cin >> hc).get();
        *this = Golf(name,hc);
        return 1;
    }
    else return 0;
}

void Golf::rehandicap(int hc){
     handicap = hc;
}

void Golf::showgolf() const{
     using std::cout;
     using std::endl;
     cout << "fullname: " << fullname << endl;
     cout << "handicap: " << handicap << endl;
}        
