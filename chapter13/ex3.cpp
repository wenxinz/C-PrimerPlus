#include "dma.h"
#include <iostream>

const int TESTNUM = 4;
const int LEN = 40;

int main(){
     using std::cin;
     using std::cout;
     using std::endl;
     
     DMAABC * p_test[TESTNUM];
     int i;
     for(i=0;i<TESTNUM;i++){
        char templabel[LEN];
        char tempcolor[LEN];
        int temprating;
        cout << "Enter label: ";
        cin.getline(templabel,LEN);
        cout << "Enter rating: ";
        cin >> temprating;
        char kind;
        cout << "Enter 1 for baseDMA, 2 for lacksDMA or 3 for hasDMA: ";
        while(cin >> kind && (kind != '1' && kind != '2' && kind != '3'))
             cout << "Enter 1, 2 or 3: ";
        cin.get();
        if(kind == '1')
             p_test[i] = new baseDMA(templabel,temprating);
        else{
             cout << "Enter color: ";
             cin.getline(tempcolor,LEN);
             cout << "tempcolor: " << tempcolor << endl;
             if(kind == '2')
                  p_test[i] = new lacksDMA(tempcolor,templabel,temprating);
             else
                  p_test[i] = new hasDMA(tempcolor,templabel,temprating);
       }
     }
     cout << endl;
     for(i=0;i<TESTNUM;i++){
        p_test[i]->view();
        cout << endl;
     }
     for(i=0;i<TESTNUM;i++){
        delete p_test[i];
     }
     cout << "Done.\n";
     return 0;
} 
