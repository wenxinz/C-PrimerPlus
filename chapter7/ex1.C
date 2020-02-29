#include <iostream>

using namespace std;

double HarmonicMean(double x, double y);

int main(){
    double x,y;
    cout << "Enter pairs of numbers: \n";
    cin >> x >> y;
    cout << "harmonic mean: " << HarmonicMean(x,y) << endl;
    return 0;
}

double HarmonicMean(double x, double y){
      return 2.0*x*y/(x+y);
}
