#include "plorg.h"
#include <cctype>
#include <iostream>

Plorg::Plorg(char * str){
    std::strncpy(name,str,19);
    name[19] = '\0';
    CI = 50;
}

void Plorg::changeCI(int n){
     CI = n;
}

void Plorg::report() const{
     using std::cout;
     using std::endl;
     cout << "name: " << name << endl;
     cout << "CI: " << CI << endl;
}     
