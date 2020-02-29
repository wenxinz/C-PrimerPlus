#include <iostream>

int main(){
    using namespace std;
    int num;
    cout << "Enter number of rows: ";
    cin >> num;
    for(int i=0;i<num;i++){
          int j;
          for(j=0;j<(num-i-1);j++){
              cout << '.';
           }
          for(j=(num-i-1);j<num;j++){
              cout << '*';
          }
          cout << endl;
    }
    return 0;
}
