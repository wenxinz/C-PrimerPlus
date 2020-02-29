#include <iostream>

using namespace std;

struct Monetary_contribution{
      char name[50];
      double contribution;
};

int main(){
    int num;
    cout << "Enter the number of contributors: ";
    cin >> num;
    Monetary_contribution* event = new  Monetary_contribution [num];
    for(int i=0;i<num;i++){
          cout << "Please enter the name and contribution of each contributor: " << endl;
          cin >> event[i].name >> event[i].contribution;
    }
    cout << "Grand Patrons: " << endl;
    for(int i=0;i<num;i++){
          if(event[i].contribution >= 10000)
             cout << event[i].name << "\t" << event[i].contribution << endl;
    }
    cout << "Patrons: " << endl;
    for(int i=0;i<num;i++){
          if(event[i].contribution < 10000)
             cout << event[i].name << "\t" << event[i].contribution << endl;
    }
    delete [] event;
    return 0;
}
