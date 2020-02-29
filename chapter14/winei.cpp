//winei.cpp

#include "winei.h"
#include <iostream>

void Wine::GetBottles(){
    std::cout << "Enter " << Wine::Label() << " data for " << years << " years(s):\n";
    for(int i=0;i<years;i++){
        std::cout << "Enter years: ";
        std::cin >> PairArray::first()[i];
        std::cout << "Enter bottles for that year: ";
        std::cin >> PairArray::second()[i];
    }
}

const std::string & Wine::Label() const{
     return (const std::string &) *this;
}

int Wine::sum(){
     return PairArray::second().sum();
}

void Wine::Show() const{
     std::cout << "Wine: " << Wine::Label() << std::endl;
     std::cout << "\t\tYear\tBottles\n";
     for(int i=0;i<years;i++){
          std::cout << "\t\t" << PairArray::first()[i] << '\t' << PairArray::second()[i]
                    << std::endl;
     }
}

