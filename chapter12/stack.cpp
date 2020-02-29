#include "stack.h"
#include <cstring>

Stack::Stack(int n){
    if(n < 0){
        std::cerr << "stack size can't be negative\n"
                  << "stack size set to 10\n";
        size = 10;
    }
    else if(n > MAX){ 
            std::cerr << "stack size can't be larger than " << MAX << std::endl
                      << "stack size set to 10\n";
            size = 10;
         }
        else
            size = n;
    pitems = new Item[size];
    top = 0;  
}

Stack::Stack(const Stack & st){
    size = st.size;
    pitems = new Item[size];
    for(int i=0;i<size;i++)
         pitems[i] = st.pitems[i];
    top = st.top;
}

Stack::~Stack(){
    delete [] pitems;
}

bool Stack::isempty() const{
    return top == 0;
}

bool Stack::isfull() const{
    return top == size;
}

bool Stack::push(const Item & item){
    if(top < size){
       pitems[top++] = item;
       return true;
    }
    else return false;
}

bool Stack::pop(Item & item){
    if(top > 0){
       item = pitems[--top];
       return true;
    }
    else return false;
}

Stack & Stack::operator=(const Stack & st){
    if(this == &st)
        return *this;
    else{
        delete [] pitems;
        size = st.size;
        pitems = new Item[size];
        for(int i=0;i<size;i++)
            pitems[i] = st.pitems[i];
        top = st.top;
        return *this;
    }
}

        
