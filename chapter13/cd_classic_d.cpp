//cd_classic_d.cpp
#include "classic_d.h"
#include <cstring>
using std::strcpy;
using std::strlen;
#include <iostream>
using std::cout;
using std::endl;

//Cd methods
Cd::Cd(const char * s1, const char * s2, int n, double x){
     performers = new char[strlen(s1)+1];
     strcpy(performers,s1);
     label = new char[strlen(s2)+1];
     strcpy(label,s2);
     selections = n;
     playtime = x;
}

Cd::Cd(const Cd & d){
     performers = new char[strlen(d.performers)+1];
     strcpy(performers,d.performers);
     label = new char[strlen(d.label)+1];
     strcpy(label,d.label);
     selections = d.selections;
     playtime = d.playtime;
}

Cd::Cd(){
    performers = 0;
    label = 0;
    selections = 0;
    playtime = 0.0;
}

Cd::~Cd(){
    delete [] performers;
    delete [] label;
}

void Cd::Report() const{
    cout << "performers: " << performers << endl;
    cout << "label: " << label << endl;
    cout << "number of selections: " << selections << endl;
    cout << "playing time in minutes: " << playtime << endl;
}

Cd & Cd::operator=(const Cd & d){
    if(this == &d) return *this;
    delete [] performers;
    performers = new char[strlen(d.performers)+1];
    strcpy(performers,d.performers);
    delete [] label;
    label = new char[strlen(d.label)+1];
    strcpy(label,d.label);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}

//Classic methods
Classic::Classic(const char * s0, const char * s1, const char * s2, int n, double x) :Cd(s1,s2,n,x){
    primarywork = new char[strlen(s0)+1];
    strcpy(primarywork,s0);
}

Classic::Classic(const Cd & d, const char * s0) :Cd(d){
    primarywork = new char[strlen(s0)+1];
    strcpy(primarywork,s0);
}

Classic::Classic() :Cd(){
    primarywork = 0;
}

Classic::~Classic(){
    delete [] primarywork;
}

void Classic::Report() const{
    Cd::Report();
    cout << "primary work on this cd: " << primarywork << endl;
}

Classic & Classic::operator=(const Classic & c){
    if(this == &c) return *this;
    Cd::operator=(c);
    delete [] primarywork;
    primarywork = new char[strlen(c.primarywork)+1];
    strcpy(primarywork,c.primarywork);
    return *this;
}
