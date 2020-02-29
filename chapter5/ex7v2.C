#include <iostream>
#include <cstring>
int main(){
    using namespace std;
    cout << "Enter words (to stop, type the word done):" << endl;
    char word[100];
    int j=0;
    while(1){
       cin >> word;
       if(!strcmp(word,"done")) break;
       j++;
    }
    cout << "You entered a total of " << j << " words." << endl;
    return 0;
}
