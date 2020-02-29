#include <iostream>

int main(){
    using namespace std;
    int min, max, sum=0;
    cout << "Enter two integers, smaller one first, separate by space:" << endl;
    cin >> min >> max;
    for(int i=min; i <= max; i++){
         sum = sum + i;
    }
    cout << "The sum of all integers from " << min << " through " << max << \
" is " << sum << endl;
    return 0;
} 
