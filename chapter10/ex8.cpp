#include "list.h"
#include <iostream>

void show(ElemType & elem);

int main(){
    using std::cout;
    int intitems[12] = {12,43,23,64,76,96,16,41,47,70,32,62};
    List list;
    if(list.isempty()) cout << "empty list!\n";
    for(int i=0;i<12;i++){
         if(list.additem(intitems[i]))
              cout << "add " << intitems[i] << " successfully!\n";
         if(list.isfull()) {cout << "full list!\n"; break;}
    }
    list.visit(show);
    return 0;
}

void show(ElemType & elem){
    std::cout << elem << std::endl;
}
