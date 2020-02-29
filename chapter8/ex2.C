#include <iostream>
#include <string>
using namespace std;
struct CandyBar{
     string brandname;
     double weight;
     int  calories;
};

void setstruct(CandyBar & cb,const char * bn="Millennium Munch"\
, double w=2.85, int c=350);

int main(){
     CandyBar candybar;
     setstruct(candybar);
     cout << candybar.brandname << '\t' << candybar.weight << '\t'
          << candybar.calories << endl; 
     setstruct(candybar, "M&M", 1.53, 250);
     cout << candybar.brandname << '\t' << candybar.weight << '\t'
          << candybar.calories << endl;
     return 0;
}

void setstruct(CandyBar & cb, const char * bn, double w, int c){
     cb.brandname = bn;
     cb.weight = w;
     cb.calories = c;
} 
