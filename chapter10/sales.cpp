#include "sales.h"
#include <iostream>

namespace SALES{
    Sales::Sales(){
       for(int i=0;i<QUARTERS;i++)
           sales[i] = 0.0;
       average = 0.0;
       max = 0.0;
       min = 0.0;
    }
   
    Sales::Sales(const double ar[], int n){
        average = ar[0];
        max = ar[0];
        min = ar[0];
        for(int i=0;i<QUARTERS;i++){
             if(i<n){
                 sales[i] = ar[i];
                 if(i>0){
                    average += sales[i];
                    if(max < sales[i]) max = sales[i];
                    if(min > sales[i]) min = sales[i];
                 }
             }
             else sales[i] = 0.0;
        }
        if(n < QUARTERS) average /= n;
        else average /= QUARTERS;
     }

     void Sales::setSales(){
         using std::cout;
         using std::cin;
         double ar[QUARTERS];
         cout << "Enter " << QUARTERS << " quarters data (seperated by space:\n";
         for(int i=0;i<QUARTERS;i++) cin >> ar[i];
         *this = Sales(ar,QUARTERS);
     }

     void Sales::showSales() const{
         using std::cout;
         using std::endl;
         cout << "sales:\n";
         for(int i=0;i<QUARTERS;i++) cout << sales[i] << "\t";
         cout << endl;
         cout << "average: " << average << endl;
         cout << "max: " << max << endl;
         cout << "min: " << min << endl;
     }
}
                
