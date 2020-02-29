#include <iostream>
using namespace std;
int Fill_array(double array[], int size);
void Show_array(const double array[], int size);
void Reverse_array(double array[], int size);

int main(){
    const int limit = 10;
    double array[limit];
    int size;
    size = Fill_array(array,limit);
    Show_array(array,size);
    Reverse_array(array,size);
    Show_array(array,size);
    return 0;
}

int Fill_array(double array[], int size){
       int i;
       cout << "enter double values:\n";
       for(i=0;i<size;i++){
           if(!(cin >> array[i])){
                break;
           }
       }
       cout << "actual number of entries: " << i << endl;
       return i;
}

void Show_array(const double array[], int size){
        int i;
        cout << "array content: \n";
        for(i=0;i<size;i++){
             cout << array[i] << endl;
        }
}

void Reverse_array(double array[], int size){
         int i,j;
         double temp;
         for(i=0,j=(size-1);j>i;i++,j--){
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
         }
}    
