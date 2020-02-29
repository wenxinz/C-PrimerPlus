// static.cpp
#include <iostream>
#include <string>

void strcount(const std::string str);

int main(){
    using namespace std;
    string input;
    char next;
    
    cout << "enter a line:\n";
    getline(cin,input);
    while(input != ""){
        strcount(input);
        cout << "enter nex line (empty line to quit):\n";
        getline(cin,input);
    }
    cout << "Bye\n";
    return 0;
}

void strcount(const std::string str){
     using namespace std;
     static int total = 0;
     int count = 0;
     cout << "\"" << str << "\" contains ";
     while(str[count])
         count++;
     total += count;
     cout << count << " characters\n";
     cout << total << " characters total\n";
}
