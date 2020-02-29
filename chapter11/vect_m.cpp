// vect.cpp --modified version

#include "vect_m.h"

using std::sin;
using std::cos;
using std::atan2;
using std::cout;

namespace VECTOR{
    const double Rad_to_deg = 57.2957795130823;
    // private methods
    void Vector::set_x(double mag, double ang){
        x = mag*cos(ang);
    }
    void Vector::set_y(double mag, double ang){
        y = mag*sin(ang);
    }
    // public methods
    Vector::Vector(){
        x = y = 0.0;
        mode = 'r';
    }
    Vector::Vector(double n1, double n2, char form){
        mode = form;
        if(form == 'r'){
            x = n1;
            y = n2;
        }
        else if(form == 'p'){
            set_x(n1,n2/Rad_to_deg);
            set_y(n1,n2/Rad_to_deg);
        }
        else{
            cout << "Incorrect 3rd argument to Vector() -- ";
            cout << "vector set to 0\n";
            x = y = 0.0;
            mode = 'r';
        }
     }
     void Vector::set(double n1, double n2, char form){
         mode = form;
         if(form == 'r'){
             x = n1;
             y = n2;
         }
         else if(form == 'p'){
             set_x(n1,n2/Rad_to_deg);
             set_y(n1,n2/Rad_to_deg);
         }
         else{
             cout << "Incorrect 3rd argument to Vector() -- ";
             cout << "vector set to 0\n";
             x = y = 0.0;
             mode = 'r';
         }
     }
     Vector::~Vector(){}
     void Vector::polar_mode(){
         mode = 'p';
     }
     void Vector::rect_mode(){
         mode = 'r';
     }
     // operator overloading
     Vector Vector::operator+(const Vector & b) const{
         return Vector(x+b.x, y+b.y);
     }
     Vector Vector::operator-(const Vector & b) const{
         return Vector(x-b.x, y-b.y);
     }
     Vector Vector::operator-() const{
         return Vector(-x, -y);
     }
     Vector Vector::operator*(double n) const{
         return Vector(n*x, n*y);
     }
     // friend method
     Vector operator*(double n, const Vector & a){
         return a*n;
     }
     std::ostream & operator<<(std::ostream & os, const Vector & v){
         if(v.mode == 'r')
             os << "(x,y) = (" << v.x << ", " << v.y << ")";
         else if(v.mode == 'p')
             os << "(m,a) = (" << v.magval() << "," << v.angval()*Rad_to_deg
                << ")";
         else
             os << "Vector object mode is invalid";
         return os;
     }
}
