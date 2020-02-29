#include <iostream>

int main(){
    using namespace std;
    float number, sum=0.0;
    while(1){
      cout << "Enter a number: " << endl;
      cin >> number;
      if(number == 0.0) break;
      sum = sum + number;
      cout << "The cumulative sum is: " << sum << endl;
    } 
    return 0;
}
