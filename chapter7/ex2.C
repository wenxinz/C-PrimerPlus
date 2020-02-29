#include <iostream>
using namespace std;
void Input (double golfscore[], int num);
void Display (const double golfscore[], int num);
void Average (const double golfscore[], int num);

int main(){
    int num=10;
    double golfscore[num];
    Input(golfscore, num);
    Display(golfscore, num);
    Average(golfscore, num);
    return 0;
}

void Input(double golfscore[], int num){
     int i;
     for(i=0;i<num;i++){
        cout << "Enter golf score #" << i << " : \
(enter negative value to stop) \n";
        cin >> golfscore[i];
        if(golfscore[i] < 0) break;
     }
}

void Display(const double golfscore[], int num){
     int i;
     for(i=0;i<num;i++){
          if(golfscore[i] < 0) break; 
          cout << golfscore[i] << ' ';
     }
}

void Average(const double golfscore[], int num){
     int i;
     double avg = 0.0;
     for(i=0;i<num;i++){
          if(golfscore[i] < 0) break;
          avg += golfscore[i];
     }
     if(i==0) cout << "null\n";
     cout << "average is: " << avg/i << endl;
}
