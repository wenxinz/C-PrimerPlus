#include <iostream>
#include <cmath>
#include "ex3.h"

double hmean(double a, double b) throw(bad_hmean);
double gmean(double a, double b) throw(bad_gmean);

int main(){
    using std::cout;
    using std::cin;
    using std::endl;
  
    double x, y, z;
    cout << "Enter two numbers: ";
    while(cin >> x >> y){
       try{
         z = hmean(x,y);
         cout << "Harmonic mean of " << x << " and " << y 
              << " is " << z << endl;
         z = gmean(x,y);
         cout << "Geometric mean of " << x << " and " << y
              << " is " << z << endl;
         cout << "Enter next set of numbers <q to quit>: ";
      }
      catch(badmean & bm){
         bm.report();
         break;
      }
    }
    cout << "Bye!\n";
    return 0;
}

double hmean(double a, double b) throw(bad_hmean){
    if(a==-b)
        throw bad_hmean(a,b,"invalid arguments for hmean(a,b): a = -b\n");
    return 2.0*a*b/(a+b);
}

double gmean(double a, double b) throw(bad_gmean){
    if(a<0 || b<0)
        throw bad_gmean(a,b,"gmean(a,b) arguments should be >=0\n");
    return std::sqrt(a*b);
}
