#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

void strtoupper(string & str);

int main(){
    string str;
    cout << "Enter a string (q to quit): ";
    getline(cin,str);
    while(str != "q"){
        strtoupper(str);
        cout << str << endl;
        cout << "Next string (q to quit): ";
        getline(cin,str);
    }
    cout << "Bye.\n";
    return 0;
}
  
void strtoupper(string & str){
     int i=0;
     while(str[i] != '\0'){
        str[i] = toupper(str[i]);
        i++;
     }
}
