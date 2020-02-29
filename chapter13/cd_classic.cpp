//cd_classic.cpp
#include "classic.h"
#include <cstring>
using std::strncpy;
using std::strcpy;
#include <iostream>
using std::cout;
using std::endl;

//Cd methods
Cd::Cd(const char * s1, const char * s2, int n, double x){
     strncpy(performers,s1,50);
     strncpy(label,s2,20);
     selections = n;
     playtime = x;
}

Cd::Cd(const Cd & d){
     strcpy(performers,d.performers);
     strcpy(label,d.label);
     selections = d.selections;
     playtime = d.playtime;
}

Cd::Cd(){
    performers[0] = '\0';
    label[0] = '\0';
    selections = 0;
    playtime = 0.0;
}

void Cd::Report() const{
    cout << "performers: " << performers << endl;
    cout << "label: " << label << endl;
    cout << "number of selections: " << selections << endl;
    cout << "playing time in minutes: " << playtime << endl;
}

Cd & Cd::operator=(const Cd & d){
    if(this == &d) return *this;
    strcpy(performers,d.performers);
    strcpy(label,d.label);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}

//Classic methods
Classic::Classic(const char * s0, const char * s1, const char * s2, int n, double x) :Cd(s1,s2,n,x){
    strncpy(primarywork,s0,50);
}

Classic::Classic(const Cd & d, const char * s0) :Cd(d){
    strncpy(primarywork,s0,50);
}

Classic::Classic() :Cd(){
    primarywork[0] = '\0';
}

void Classic::Report() const{
    Cd::Report();
    cout << "primary work on this cd: " << primarywork << endl;
}

Classic & Classic::operator=(const Classic & c){
    if(this == &c) return *this;
    Cd::operator=(c);
    strncpy(primarywork,c.primarywork,50);
    return *this;
}
