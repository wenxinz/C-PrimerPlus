#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

struct Monetary_contribution{
      char name[50];
      double contribution;
};

int main(){
    int num;
    ifstream infile;
    infile.open("6-9input.txt");
    if(!infile.is_open()){
         cout << "Could not open the file";
         exit(EXIT_FAILURE);
    }
    (infile >> num).get();
    Monetary_contribution* event = new  Monetary_contribution [num];
    for(int i=0;i<num;i++){
          infile.getline(event[i].name,50);
          (infile >> event[i].contribution).get();
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
