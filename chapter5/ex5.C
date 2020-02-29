#include <iostream>

int main(){
    using namespace std;
    const char * month[12]=
{ "JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
    int sale[3][12];
    int i,j,sum=0,total=0;
    cout << "Enter a year's worth of monthly sales (in terms of #books): " <<\
endl;
    for(j=0;j<3;j++){
      for(i=0;i<12;i++){
        cout << month[i] << " : ";
        cin >> sale[j][i];
      }
      for(i=0;i<12;i++) sum += sale[j][i];
      cout << "The total sales for year " << j << " is: " << sum << endl;
      total += sum;
    }
    cout << "The total sales for 3 years is: " << total << endl;
    return 0;
}  
