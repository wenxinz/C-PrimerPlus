#include <iostream>
using namespace std;

template <class Any>
Any max5(Any array[]){
    Any max = array[0];
    for(int i=1;i<5;i++){
       if(array[i] > max)
           max = array[i];
    }
    return max;
}

int main(){
    int testint[5] = {1,2,3,4,5};
    double testdouble[5] = {1.0,3.20,3.12,42.0,4.3};
    cout << "largest item in testint: " << max5(testint) << endl;
    cout << "largest item in testdouble: "<< max5(testdouble) << endl;
    return 0;
}
