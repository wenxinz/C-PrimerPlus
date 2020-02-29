#include "sales.h"
#include <iostream>

int main(){
    using SALES::Sales;
    using std::cout;
    Sales sale1;
    cout << "sale1:\n";
    sale1.showSales();
    cout << "set sale1 with setSales():\n";
    sale1.setSales();
    sale1.showSales();
    double ar1[3] = {12.4,231.4,932.1};
    Sales sale2(ar1,3);
    cout << "sale2:\n";
    sale2.showSales();
    return 0;
}
    
