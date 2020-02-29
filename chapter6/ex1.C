#include <iostream>
#include <cctype>
int main(){
    using namespace std;
    char ch;
    cin.get(ch);
    while(ch!='@'){
       if(!isdigit(ch)){
            if(isalpha(ch)){
                if(islower(ch)) cout.put(toupper(ch));
                else cout.put(tolower(ch));
            }
            else cout.put(ch);
       }
       cin.get(ch);
    }
    cout << endl;
    return 0;
}
      
