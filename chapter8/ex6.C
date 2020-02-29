#include <iostream>
using namespace std;

template <class T>
T maxn(T array[], int n);

template <> char * maxn(char * array[], int n); //specialization

int main(){
    int testint[6] = {1,2,3,4,5,6};
    double testdouble[4] = {1.0,3.2,5.2,4.3};
    const char * teststring[5] = {"hello","chemistry","research","really long \
string","short"};
    cout << "largest item in testint: " << maxn(testint,6) << endl;
    cout << "largest item in testdouble: " << maxn(testdouble,4) << endl;
    cout << "longest string in teststring: " << maxn(teststring,5) << endl; 
    return 0;
}

template <class T>
T maxn(T array[], int n){          // general version
     T max = array[0];
     for(int i=1;i<n;i++){
        if(array[i] > max)
            max = array[i];
     }
     return max;
}

template <> char * maxn(char * array[], int n){   //specialization
     char * max = array[0];
     for(int i=0;i<n;i++){
         if(strlen(max) < strlen(array[i]))
              max = array[i];
     }
     return max;
}
