#include <iostream>
#include "sales.h"

int main(){
    using std::cout;
    using SALES::Sales;
    Sales sale1,sale2;
    setSales(sale1);
    cout << "sales1:\n";
    showSales(sale1);
    double value1[3] = {12.4,231.4,932.1};
    double value2[5] = {23.3,54.4,12.4,53.0,31.3};
    setSales(sale2,value1,3);
    cout << "sales2,value1:\n";
    showSales(sale2);
    setSales(sale2,value2,5);
    cout << "sales2,value2:\n";
    showSales(sale2);
    return 0;
}
