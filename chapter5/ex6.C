#include <iostream>
using namespace std;
struct car{
    char make[50];
    int year;
};

int main(){
    int num;
    cout << "How many cars do you wish to catalog? ";
    (cin >> num).get();
    car * cars = new car [num];
    for(int i=0;i<num;i++){
       cout << "Car #" << i+1 << ":" << endl;
       cout << "Please enter the make: ";
       cin.getline(cars[i].make,50);
       cout << "Please enter the year: ";
       (cin >> cars[i].year).get();
    }
    cout << "Here is your collection:" << endl;
    for (int i=0;i<num;i++){
        cout << cars[i].year << " " << cars[i].make << endl;
    }
    return 0;
    delete [] cars;
}     
