#include "stack.h"
#include <iostream>

int main(){
    using std::cout;
    using std::endl;
    cout << "creating a stack with 8 element:\n";
    Stack st1(8);
    cout << "is the stack empty?   " << st1.isempty() << endl;
    cout << "push items into the stack:\n";
    for(int i=0;i<10;i++)
        if(!st1.push(i)) 
            cout << "fail to push item " << i << " into the stack\n";
    cout << "is the stack full?   " << st1.isfull() << endl;
    cout << "test constructor:\n";
    Stack st2(14),st3(-1);
    Stack st4(st1);
    st2 = st1;
    cout << "test copy constructor and operator=:\n";
    Item temp1,temp2;
    for(int i=0;i<10;i++){
        if(!st4.pop(temp1))
            cout << "fail to pop item " << i << " from st4\n";
        else
            cout << temp1 << endl;
        if(!st2.pop(temp2))
            cout << "fail to pop item " << i << " from st2\n";
        else 
            cout << temp2 << endl;
    }
    return 0;
}
