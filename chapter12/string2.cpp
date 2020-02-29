// string2.cpp

#include <cstring>
#include <cctype>
#include "string2.h"
using std::cin;
using std::cout;

//initializing static class member
int String::num_strings = 0;

//static method
int String::HowMany(){
    return num_strings;
}

//class methods
String::String(const char * s){
    len = std::strlen(s);
    str = new char[len+1];
    std::strcpy(str,s);
    num_strings++;
}

String::String(){
    len = 4;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}

String::String(const String & st){
    num_strings++;
    len = st.len;
    str = new char[len+1];
    std::strcpy(str,st.str);
}

String::~String(){
     --num_strings;
     delete [] str;
}

void String::stringlow(){
     for(int i=0;i<len;i++){
        if(isalpha(str[i]))
            str[i] = tolower(str[i]);
     }
}

void String::stringup(){
      for(int i=0;i<len;i++){
         if(isalpha(str[i]))
            str[i] = toupper(str[i]);
      }
}

int String::has(char c){
      int count=0;
      for(int i=0;i<len;i++){
          if(str[i] == c)
             count++;
      }
      return count;
}          
 
//overloaded operator methods
//---assign a String to a String
String & String::operator=(const String & st){
    if(this == &st) return *this;
    delete [] str;
    len = st.len;
    str = new char[len+1];
    std::strcpy(str,st.str);
    return *this;
}

//---assign a C string to a String
String & String::operator=(const char * s){
    delete [] str;
    len = std::strlen(s);
    str = new char [len+1];
    std::strcpy(str,s);
    return *this;
}

//---read-write char access for non-const String
char & String::operator[](int i){
     return str[i];
}

//---read-only char access for const String
const char & String::operator[](int i) const{
     return str[i];
}

//---join two strings into one
String String::operator+(const String & st) const{
     char * temp = new char[len + st.len + 1];
     std::strcpy(temp,str); 
     std::strcat(temp,st.str);
     String joint(temp);
     delete [] temp;
     return joint;
}

String String::operator+(const char * s) const{
     char * temp = new char[len + std::strlen(s) + 1];
     std::strcpy(temp,str);
     std::strcat(temp,s);
     String joint(temp);
     delete [] temp;
     return joint;
}

//overloaded operator friends
String operator+(const char * s, const String &st){
      char * temp = new char[std::strlen(s) + st.len + 1];
      std::strcpy(temp,s);
      std::strcat(temp,st.str);
      String joint(temp);
      delete [] temp;
      return joint;
}

bool operator<(const String &st1, const String &st2){
     return (std::strcmp(st1.str,st2.str)<0);
}

bool operator>(const String &st1, const String &st2){
     return st2.str < st1.str;
}

bool operator==(const String &st1, const String &st2){
     return (std::strcmp(st1.str,st2.str)==0);
}

//---simple String output
ostream & operator<<(ostream & os, const String & st){
     os << st.str;
     return os;
}

//---quick and dirty String input
istream & operator>>(istream & is, String & st){
     char temp[String::CINLIM];
     is.get(temp, String::CINLIM);
     if(is) st = temp;
     while(is && is.get()!='\n') continue;
     return is;
}
