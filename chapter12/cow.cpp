#include "cow.h"
#include <cstring>
#include <iostream>

Cow::Cow(){
    name[0] = '\0';
    hobby = new char[1];
    hobby[0] = '\0';
    weight = 0.0;
}

Cow::Cow(const char * nm, const char * ho, double wt){
    std::strncpy(name,nm,20);
    int len = std::strlen(ho);
    hobby = new char[len+1];
    std::strcpy(hobby,ho);
    weight = wt;
}

Cow::Cow(const Cow & c){
    std::strncpy(name,c.name,20);
    int len = std::strlen(c.hobby);
    hobby = new char[len+1];
    std::strcpy(hobby,c.hobby);
    weight = c.weight;
}

Cow::~Cow(){
    delete [] hobby;
}

Cow & Cow::operator=(const Cow & c){
    if(this == &c) return *this;
    delete [] hobby;
    std::strncpy(name,c.name,20);
    int len = std::strlen(c.hobby);
    hobby = new char[len+1];
    std::strcpy(hobby,c.hobby);
    weight = c.weight;
    return *this;
}

void Cow::ShowCow() const{
    std::cout << "name: " << name << std::endl;
    std::cout << "hobby: " << hobby << std::endl;
    std::cout << "weight: " << weight << std::endl;
}


