#include "complex0.h"

complex::complex(double a, double b){
     real = a;
     img = b;
}

complex complex::operator+(complex & a) const{
     return complex(real+a.real, img+a.img);
}

complex complex::operator-(complex & a) const{
     return complex(real-a.real, img-a.img);
}

complex complex::operator-() const{
     return complex(-real, -img);
}

complex complex::operator*(complex & a) const{
     return complex(real*a.real-img*a.img, real*a.img+a.real*img);
}

complex operator*(double n, const complex & a){
     return complex(n*a.real, n*a.img);
}

std::ostream & operator<<(std::ostream & os, const complex & a){
     os << "(" << a.real << ", " << a.img << "i)";
     return os;
}

std::istream & operator>>(std::istream & is, complex & a){
     std::cout << "real: ";
     is >> a.real;
     std::cout << "imaginary: ";
     is >> a.img;
     return is;
}
