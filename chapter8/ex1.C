#include <iostream>
using namespace std;
int n = 0;
void print(char * str, int sig=0);

int main(){
    char str[] = "hello world!";
    for(int i=0;i<5;i++) print(str);
    cout << endl;
    print(str,1);
    return 0;
}

void print(char * str, int sig){
    if(sig == 0) cout << str << endl;
    else for(int i=0;i<n;i++)
           cout << str << endl;
    n++;
}
