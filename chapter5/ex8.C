#include <iostream>
#include <string>
int main(){
    using namespace std;
    string word;
    int i=0;
    cout << "Enter words (to stop, type the word done): " <<endl;
    do{
      cin >> word;
      i++;
    }
    while(word != "done");
    cout << "You entered a total of " << i-1 << " words." << endl;
    return 0;
}
