#include "stonewt_2.h"
#include <iostream>

int main(){
    using std::cout;
    using std::endl;
    using std::cin;
    Stonewt ar[6] = {Stonewt(124.0), Stonewt(54,12.0),456.93};
    for(int i=3;i<6;i++){
        cout << "enter values for object " << i << ": \n";
        int form;
        cout << "enter 2 if the value is in stone form, \
1 if in pounds form: \n";
        cin >> form;
        double lbs;
        int stn;
        switch(form){
        case 1: cin >> lbs;
                ar[i] = Stonewt(lbs);
                break;
        case 2: cin >> stn >> lbs;
                ar[i] = Stonewt(stn,lbs);
                break;
        }
    }
    Stonewt compare(11,0.0);
    Stonewt max, min;
    int num=0;
    for(int i=0;i<6;i++){
        if(i==0){
            max = ar[i];
            min = ar[i];
        }
        if(ar[i] >= compare) num++;
        if(ar[i] > max) max = ar[i];
        if(ar[i] < min) min = ar[i];
    }
    cout << "largest element: ";
    max.show_lbs();
    max.show_stn();
    cout << "smarllest element: ";
    min.show_lbs();
    min.show_stn();
    cout << num << " elements are greater or equal to 11\n";
    return 0;
}
