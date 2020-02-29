#include <iostream>

int main(){
    using std::cout;
    using std::cin;
    
    int count=0;
    char ch;
    while(cin.get(ch)){
        if(ch != '$')
            count++;
        else{
            cin.putback(ch);
            break;
        }
    } 
    cout << "there're(s) " << count 
         << " characters up to the first $ in input\n";
    return 0;
}
