#include <iostream>
#include "sales.h"

namespace SALES{
   void setSales(Sales & s, const double ar[], int n){
        s.average = ar[0];
        s.max = ar[0];
        s.min = ar[0];
        int i;
        for(i=0;i<QUARTERS;i++){
           if(i<n){
              s.sales[i] = ar[i];
              if(i>0){
                 s.average += s.sales[i];
                 if(s.max < s.sales[i]) s.max = s.sales[i];
                 if(s.min > s.sales[i]) s.min = s.sales[i];
              }
           }
           else s.sales[i] = 0.0;
        } 
        if(n<QUARTERS) s.average /= n;
        else s.average /= QUARTERS;
   }

   void setSales(Sales & s){
        using std::cout;
        using std::cin;
        cout << "Enter " << QUARTERS << " quaters data (seperated by space):\n";
        int i;
        for(i=0;i<QUARTERS;i++) cin >> s.sales[i];
        s.average = s.sales[0];
        s.max = s.sales[0];
        s.min = s.sales[0]; 
        for(i=1;i<QUARTERS;i++){
             if(s.max < s.sales[i]) s.max = s.sales[i];
             if(s.min > s.sales[i]) s.min = s.sales[i];
             s.average += s.sales[i];
        }
        s.average = s.average/QUARTERS;
   }
   
   void showSales(const Sales & s){
         using std::cout;
         using std::endl;
         cout << "s.sales: \n";
         int i;
         for(i=0;i<QUARTERS;i++){
               cout << s.sales[i] << "\t";
         }
         cout << endl;
         cout << "s.average: " << s.average << endl;
         cout << "s.max: " << s.max << endl;
         cout << "s.min: " << s.min << endl;
   }
}
