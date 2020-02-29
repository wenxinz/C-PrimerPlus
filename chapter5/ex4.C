#include <iostream>

int main(){
    using namespace std;
    const char * month[12]=
{ "JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
    int sale[12];
    int i,sum=0;
    cout << "Enter a year's worth of monthly sales (in terms of #books): " <<\
endl;
    for(i=0;i<12;i++){
        cout << month[i] << " : ";
        cin >> sale[i];
    }
    for(i=0;i<12;i++) sum += sale[i];
    cout << "The total sales for the year is: " << sum << endl;
    return 0;
}  
