#include <iostream>
#include <cmath>
#include <stdexcept>

class bad_hmean: public std::logic_error {
public:
  explicit bad_hmean(const std::string& what_arg):std::logic_error(what_arg){};
};
class bad_gmean: public std::logic_error {
public:
  explicit bad_gmean(const std::string& what_arg):std::logic_error(what_arg){};
};

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
         cout << "Geometric mean of " << x << " and " << y
              << " is " << gmean(x,y) << endl;
         cout << "Enter next set of numbers <q to quit>: ";
      }
      catch(bad_hmean & bg){
         cout << bg.what();
         cout << "Try again.\n";
         continue;
      }
      catch(bad_gmean & hg){
         cout << hg.what(); 
         cout << "Sorry, you don't get to play any more.\n";
         break;
      }
    }
    cout << "Bye!\n";
    return 0;
}

double hmean(double a, double b) throw(bad_hmean){
    if(a==-b)
        throw bad_hmean("invalid arguments for hmean(a,b): a = -b\n");
    return 2.0*a*b/(a+b);
}

double gmean(double a, double b) throw(bad_gmean){
    if(a<0 || b<0)
        throw bad_gmean("gmean(a,b) arguments should be >=0\n");
    return std::sqrt(a*b);
}
