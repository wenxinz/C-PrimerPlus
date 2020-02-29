#include <iostream>
const int NUM = 10;
int main(){
    using namespace std;
    double donation[NUM]={0.0};
    int i;
    for(i=0;i<NUM;i++){
        cout << "#" << i+1 << " : ";
        while(!(cin >> donation[i])){
            cin.clear();
            while(cin.get() != '\n') continue;
            cout << "Please enter a number: ";
        }
    }
    double avg=0.0;
    for(i=0;i<NUM;i++){
         avg += donation[i];
    }
    avg = avg / NUM;
    int j=0;
    for(i=0;i<NUM;i++){
       if(donation[i]>avg) j++;
    }
    cout << "average: " << avg << endl;
    cout << j << " numbers in the array are larger than the average \n";
    return 0;
}
