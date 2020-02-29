#include <iostream>
using namespace std;

double add(double x, double y);
double multiply(double x, double y);
double calculate(double val1,double val2,double (*p)(double,double));

int main(){
     double x,y;
     double (*pf[2])(double,double)={add,multiply};
     cout << "calculate functions: add, multiply\n";
     while(1){
        cout << "enter a pair of numbers: \n";
        if(!(cin >> x >> y)) break;
        for(int i=0;i<2;i++)
            cout << calculate(x,y,pf[i]) << endl;
    }
    return 0;
}

double add(double x, double y){
       return x+y;
}
double multiply(double x, double y){
       return x*y;
}
double calculate(double val1,double val2,double (*p)(double val1,double val2)){
       return (*p)(val1,val2);
}

