#include "dma.h"
#include <cstring>
using std::strlen;
using std::strcpy;
using std::strncpy;
#include <iostream>
using std::cout;
using std::endl;

//ABC methods
DMAABC::DMAABC(const char * l, int r){
     label = new char[strlen(l)+1];
     strcpy(label,l);
     rating = r;
}

DMAABC::DMAABC(const DMAABC & rs){
     label = new char[strlen(rs.label)+1];
     strcpy(label, rs.label);
     rating = rs.rating;
}

DMAABC::~DMAABC(){
     delete [] label;
}

DMAABC & DMAABC::operator=(const DMAABC & rs){
      if(this == &rs) return *this;
      delete [] label;
      label = new char[strlen(rs.label)+1];
      strcpy(label, rs.label);
      rating = rs.rating;
      return *this;
}

void DMAABC::view() const{
      cout << "label: " << label << endl;
      cout << "rating: " << rating << endl;
}

//baseDMA methods
void baseDMA::view() const{
      DMAABC::view();
}

//lacksDMA methods
lacksDMA::lacksDMA(const char * c, const char * l, int r) :DMAABC(l,r){
       strncpy(color,c,COL_LEN);
}

lacksDMA::lacksDMA(const char * c, const DMAABC & rs) :DMAABC(rs){
       strncpy(color,c,COL_LEN);
}

void lacksDMA::view() const{
     DMAABC::view();  
     cout << "color: " << color << endl;
}

//hasDMA methods
hasDMA::hasDMA(const char * s, const char * l, int r) :DMAABC(l,r){
        style = new char[strlen(s)+1];
        strcpy(style,s);
}

hasDMA::hasDMA(const char * s, const DMAABC & rs) :DMAABC(rs){
        style = new char[strlen(s)+1];
        strcpy(style,s);
}

hasDMA::hasDMA(const hasDMA & hs) :DMAABC(hs){
        style = new char[strlen(hs.style)+1];
        strcpy(style,hs.style);
}

hasDMA::~hasDMA(){
        delete [] style;
}

hasDMA & hasDMA::operator=(const hasDMA & hs){
         if(this == &hs) return *this;
         DMAABC::operator=(hs); //copy base portion
         delete [] style;
         style = new char[strlen(hs.style)+1];
         strcpy(style, hs.style);
         return *this;
}

void hasDMA::view() const{
        DMAABC::view(); 
        cout << "style: " << style << endl;
}

