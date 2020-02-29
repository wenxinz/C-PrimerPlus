#include <iostream>

int main(){
    using namespace std;
    cout << "Please enter one of the following choices:\n"
            "c) carnivore      p) pianist \n"
            "t) tree           g) game \n";
    char ch;
    int i = 1;
    while(i){
       cin.get(ch);
       switch(ch){
          case 'c': cout << "A maple is a carnivore.\n";i=0;break;
          case 'p': cout << "A maple is a pianist.\n";i=0;break;
          case 't': cout << "A maple is a tree.\n";i=0;break;
          case 'g': cout << "A maple is a game.\n";i=0;break;
          default: cout << "Please enter a c, p, t, or g: ";
       }
    }
    return 0;
} 
