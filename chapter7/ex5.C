#include <iostream>
#include <cstdlib>
using namespace std;
int factorial(int x);

int main(){
    unsigned x;
    cout << "enter x: ";
    while((cin >> x)){
        cout << "factorial of x is: " << factorial(x) << endl;
        cout << "enter next x: (enter q to stop) ";
    }
    return 0;
}

int factorial(int x){
     int f;
     if(x == 0)
          f=1;
     else
          f = x*factorial(x-1);
    return f;
}
