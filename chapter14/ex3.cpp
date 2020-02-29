#include <iostream>
#include "queuetp.h"
#include "worker.h"

const int SIZE = 3;

int main(){
    using std::cout;
    using std::cin;
    using std::endl;

    QueueTp<Worker *> test(SIZE);
    Worker * in[SIZE];
    Worker * out[SIZE];
    int i;
    for(i=0;i<SIZE;i++){
       in[i] = new Worker;
       in[i]->Set();
    }
    for(i=0;i<SIZE;i++){
       test.enqueue(in[i]);
    }
    cout << "Here are workers in the queue:\n";
    for(i=0;i<SIZE;i++){   
       test.dequeue(out[i]);
       out[i]->Show();
       delete in[i];
    }
    return 0;
} 
            
