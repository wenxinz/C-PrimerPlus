#include <iostream>
#include <cstring>
int main(){
    using namespace std;
    cout << "Enter words (to stop, type the word done):" << endl;
    char word[100];
    int j=0;
    while(1){
       for(int i=0;i<100;i++){
            cin.get(word[i]);
           // cout << word[i];
            if(word[i] == ' ' || word[i] == '\n') {
                  word[i] = '\0';
                  break;
             }
       }
       if(!strcmp(word,"done")) break;
       j++;
    }
    cout << "You entered a total of " << j << " words." << endl;
    return 0;
}
