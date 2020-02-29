//QueueTp.h
#include <iostream>

template <typename Type>
class QueueTp{
private:
  struct Node{
      Type item;
      struct Node * next;
  };
  enum {Q_SIZE = 10};
  Node * front;
  Node * rear;
  int items;
  const int qsize;
  //preemptive definitions to prevent public copying
  QueueTp(const QueueTp & q) :qsize(0){}
  QueueTp & operator=(const QueueTp & q){return *this;}
public:
  QueueTp(int qs = Q_SIZE);
  ~QueueTp();
  bool isempty() const;
  bool isfull() const;
  int queuecount() const;
  bool enqueue(const Type & item);
  bool dequeue(Type &item);
};

template <typename Type>
QueueTp<Type>::QueueTp(int qs) :qsize(qs){
  front = rear = NULL;
  items = 0;
}

template <typename Type>
QueueTp<Type>::~QueueTp(){
   Node * temp;
   while(front != NULL){
      temp = front;
      front = front->next;
      delete temp;
   }
}

template <typename Type>
bool QueueTp<Type>::isempty() const{
    return items == 0;
}

template <typename Type>
bool QueueTp<Type>::isfull() const{
    return items == qsize;
}

template <typename Type>
int QueueTp<Type>::queuecount() const{
    return items;
}

template <typename Type>
bool QueueTp<Type>::enqueue(const Type & item){
    if(isfull())
        return false;
    Node * add = new Node;
    if(add == NULL)
        return false;
    add->item = item;
    add->next = NULL;
    items++;
    if(front == NULL)
        front = add;
    else
        rear->next = add;
    rear = add;
    return true;
}

template <typename Type>
bool QueueTp<Type>::dequeue(Type & item){
    if(front == NULL)
        return false;
    item = front->item;
    items--;
    Node * temp = front;
    front = front->next;
    delete temp;
    if(items == 0)
        rear = NULL;
    return true;
}
