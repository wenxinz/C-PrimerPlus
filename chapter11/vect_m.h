// vect_m.h -- modified version, mag and ang are no longer stored as data 
// components; they are calculated on demand when the magval() and angval()
// methods are called

#ifndef VECTOR_M_H_
#define VECTOR_M_H_
#include <iostream>
#include <cmath>

namespace VECTOR{
    class Vector{
    private:
        double x;
        double y;
        char mode;
        // private method
        void set_x(double mag, double ang);
        void set_y(double mag, double ang);
    public:
        Vector();
        Vector(double n1, double n2, char form = 'r');
        void set(double n1, double n2, char form = 'r');
        ~Vector();
        double xval() const {return x;}
        double yval() const {return y;}
        double magval() const {return sqrt(x*x + y*y);}
        double angval() const {
            if(x==0.0 && y==0.0) return 0.0;
            else return atan2(y,x);
        }
        void polar_mode();
        void rect_mode();
        // operator overloading
        Vector operator+(const Vector & b) const;
        Vector operator-(const Vector & b) const;
        Vector operator-() const;
        Vector operator*(double n) const;
        // friends
        friend Vector operator*(double n, const Vector & a);
        friend std::ostream & operator<<(std::ostream & os, const Vector & v);
    };
}

#endif
