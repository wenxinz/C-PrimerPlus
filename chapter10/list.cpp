#include "list.h"

List::List(){
     num = 0;
}

bool List::additem(ElemType & item){
     if(num <= MAX){
        items[num++] = item;
        return 1;
     }
     else return 0;
}

bool List::isempty(){
     return num == 0;
}

bool List::isfull(){
     return num == MAX;
}

void List::visit(void (*pf)(ElemType &)){
     for(int i=0;i<num;i++)
          (*pf)(items[i]);
}
