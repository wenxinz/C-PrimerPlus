//complex0.h

#include <iostream>

class complex{
private:
    double real;
    double img;
public:
    complex(double a=0.0, double b=0.0);
    ~complex(){};
    //operator overloaded
    complex operator+(complex & a) const;
    complex operator-(complex & a) const;
    complex operator-() const;
    complex operator*(complex & a) const;
    //friends
    friend complex operator*(double n, const complex & a);
    friend std::ostream & operator<<(std::ostream & os, const complex & a);
    friend std::istream & operator>>(std::istream & is, complex & a);
}; 
