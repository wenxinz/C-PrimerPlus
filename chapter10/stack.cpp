#include "stack.h"
#include <iostream>

Stack::Stack(){
    top = 0;
}

int Stack::isempty() const{
    return (top == 0);
}

int Stack::isfull() const{
    return (top == MAX);
}

int Stack::push(const Item & item){
    if(top < MAX){
        items[top++] = item;
        return 1;
    }
    else return 0;
}

int Stack::pop(Item & item){
     if(top > 0){
          item = items[--top];
          return 1;
     }
     else return 0;
}
