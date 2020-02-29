// golf.cpp
#include <iostream>
#include <cstring>
#include "golf.h"

// non-interactive version:
// function sets golf structure to provided name, handicap using values
// passed as arguments to the function
void setgolf(golf & g, const char * name, int hc){
    strcpy(g.fullname,name);
    g.handicap = hc;
}

// interactive version:
// function solicits name and handicap from user and sets the member of g to
// the values entered; return 1 if name is entered, 0 if name is empty string
int setgolf(golf & g){
    std::cout << "enter fullname: ";
    std::cin.get(g.fullname,40);
    if(!std::cin.fail()){
       std::cout << "enter handicap: ";
       (std::cin >> g.handicap).get();
       return 1;
    }
    else return 0;
}

// function reset handicap to new value
void handicap(golf & g, int hc){
     g.handicap = hc;
}

// function display contents of golf structure
void showgolf(const golf & g){
     std::cout << "g.fullname: " << g.fullname << std::endl;
     std::cout << "g.handicap: " << g.handicap << std::endl;
}


