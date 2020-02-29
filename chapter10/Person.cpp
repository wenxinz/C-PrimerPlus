#include "Person.h"
#include <cctype>
#include <iostream>

Person::Person(const std::string & ln, const char * fn){
     lname = ln;
     std::strncpy(fname,fn,LIMIT-1);
     fname[LIMIT-1] = '\0';
}

void Person::Show() const{
     using std::cout;
     cout << "firstname lastname:\n"; 
     cout << fname << " "  << lname << std::endl;
}

void Person::FormalShow() const{
     using std::cout;
     cout << "lastname, firstname:\n";
     cout << lname << ", " << fname << std::endl;
}

