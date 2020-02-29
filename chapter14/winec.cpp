//winec.cpp

#include <iostream>
#include "winec.h"

void Wine::GetBottles(){
    std::cout << "Enter " << name << " data for " << years << " year(s):\n";
    for(int i=0;i<years;i++){
       std::cout << "Enter year: ";
       std::cin >> info.first()[i];
       std::cout << "Enter bottles for that year: ";
       std::cin >> info.second()[i];
    }
}

std::string & Wine::Label(){
     return name;
}

int Wine::sum(){
     return info.second().sum();
}

void Wine::Show() const{
     std::cout << "Wine: " << name << std::endl;
     std::cout << "\t\tYear\tBottles\n";
     for(int i = 0;i<years;i++){
        std::cout << "\t\t" << info.first()[i] << '\t' 
                  << info.second()[i] << std::endl;
     }
}
