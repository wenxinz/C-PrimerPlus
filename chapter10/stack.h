#ifndef STACK_H_
#define STACK_H_

struct customer{
    char fullname[35];
    double payment;
};

typedef customer Item;

class Stack{
private:
    enum {MAX=3};
    Item items[MAX];
    int top;
public:
    Stack();
    int isempty() const;
    int isfull() const;
    int push(const Item & item);
    int pop(Item & item);
};

#endif
