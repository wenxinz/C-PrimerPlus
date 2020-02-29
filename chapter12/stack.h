// stack.h

#include <iostream>
using std::ostream;

typedef unsigned long Item;

class Stack{
private:
     enum {MAX = 10};
     Item * pitems;
     int size;
     int top;
public:
     Stack(int n = 10);
     Stack(const Stack & st);
     ~Stack();
     bool isempty() const;
     bool isfull() const;
     // push() return false if stack already is full, true otherwise
     bool push(const Item & item);
     // pop() return false if stack already is empty, true otherwise
     bool pop(Item & item);
     Stack & operator=(const Stack & st);
};


