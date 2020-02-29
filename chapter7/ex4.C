// lotto.C ---probability of winning
#include <iostream>
using namespace std;
long double probability(unsigned fieldrange, unsigned secondrange, \
unsigned fieldnumber);

int main(){
    double fieldrange, secondrange, fieldnumber;
    cout << "Enter the range of the field, second range and\n"
            "number of field numbers :\n";
    while((cin >> fieldrange >> secondrange >> fieldnumber) && \
fieldnumber <= fieldrange){
         cout << "You have one chance in ";
         cout << probability(fieldrange,secondrange,fieldnumber);
         cout << " of winning.\n";
         cout << "Next three numbers (q to quit): ";
    }
    cout << "bye\n";
    return 0;
}

long double probability(unsigned fieldrange, unsigned secondrange, \
unsigned fieldnumber){
     long double result = 1.0;
     long double n;
     unsigned p;
     for(n=fieldrange,p=fieldnumber; p>0; n--,p--)
         result *= n/p;
     result *= 1.0/secondrange;
     return result;
}
