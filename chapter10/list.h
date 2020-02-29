typedef int ElemType;

class List{
private:
    enum {MAX = 10};
    ElemType items[MAX];
    int num;
public:
    List();
    bool additem(ElemType & item);
    bool isempty();
    bool isfull();
    void visit(void (*pf)(ElemType &));
}; 
