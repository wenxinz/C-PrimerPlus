#include "stonewt.h"
using std::cout;

Stonewt::Stonewt(double lbs){
    pounds = lbs;
    form = 'p';
    set_stone();
}

Stonewt::Stonewt(int stn, double lbs){
    stone = stn;
    pds_left = lbs;
    form = 's';
    set_pounds();
}

Stonewt::Stonewt(){
    stone = pounds = pds_left = 0;
    form = 's';
}

Stonewt::~Stonewt(){}

void Stonewt::showform() const{
     std::cout << "current display form is: " << form << std::endl;
}

void Stonewt::stone_form(){
     std::cout << "form set to stone\n";
     form = 's';
}

void Stonewt::intpounds_form(){
     std::cout << "form set to integer pounds form\n";
     form = 'i';
}

void Stonewt::pounds_form(){
     std::cout << "form set to floating-point pounds form\n";
     form = 'p';
}

Stonewt Stonewt::operator+(const Stonewt & a) const{
     return Stonewt(pounds+a.pounds);
}

Stonewt Stonewt::operator-(const Stonewt & a) const{
     return Stonewt(pounds-a.pounds);
}

Stonewt Stonewt::operator*(double mul) const{
     return Stonewt(pounds*mul);
}    

Stonewt operator*(double mul, const Stonewt & a){
     return a*mul;
}

std::ostream & operator<<(std::ostream & os, const Stonewt & a){
     if(a.form == 's')
         os << a.stone << " stone, " << a.pds_left << " pounds\n";
     else if(a.form == 'i')
         os << int(a.pounds) << " pounds\n";
     else
         os << a.pounds << " pounds\n";
     return os;
} 

