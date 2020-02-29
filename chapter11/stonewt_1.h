// stonewt.h

#ifndef STONEWT_H_
#define STONEWT_H_
#include <iostream>

class Stonewt{
private:
   enum {Lbs_per_stn = 14};  
   int stone;                // whole stones
   double pds_left;          // fractional pounds
   double pounds;            // entire weight in pounds
   char form;
   void set_stone(){
       stone = int(pounds) / Lbs_per_stn;
       pds_left = int(pounds) % Lbs_per_stn + pounds - int(pounds);
   }
   void set_pounds(){pounds = stone * Lbs_per_stn + pds_left;} 
public:
   Stonewt(double lbs);
   Stonewt(int stn, double lbs); 
   Stonewt();
   ~Stonewt();
   void showform() const;
   void stone_form();
   void intpounds_form();
   void pounds_form();
   //operator overloading
   Stonewt operator+(const Stonewt & a) const;
   Stonewt operator-(const Stonewt & a) const;
   Stonewt operator*(double mul) const;
   //friends
   friend Stonewt operator*(double mul, const Stonewt & a);
   friend std::ostream & operator<<(std::ostream & os, const Stonewt & a);
};

#endif
