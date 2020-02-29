// string2.h

#include <iostream>
using std::ostream;
using std::istream;

#ifndef STRING2_H_
#define STRING2_H_

class String{
private:
    char * str;
    int len;
    static int num_strings;
    static const int CINLIM = 80;
public:
 // constructors and other methods
    String(const char * s);
    String();
    String(const String &);
    ~String();
    int length() const {return len;}
    void stringlow();       // added feature
    void stringup();        // added feature
    int has(char c);  // added feature
 // overloaded operator methods
    String & operator=(const String & st);
    String & operator=(const char * s);
    char & operator[](int i);
    const char & operator[](int i) const;
    String operator+(const String & st) const; // added feature
    String operator+(const char * s) const;    // added feature
 // overloaded operator friends
    friend String operator+(const char * s, const String &st);
    friend bool operator<(const String &st, const String &st2);
    friend bool operator>(const String &st1, const String &st2);
    friend bool operator==(const String &st, const String &st2);
    friend ostream & operator<<(ostream & os, const String & st);
    friend istream & operator>>(istream & is, String & st);
 // static function
    static int HowMany();
};

#endif
