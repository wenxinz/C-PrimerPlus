#include "stack.h"
#include <iostream>

int main(){
    using std::cout;
    using std::cin;
    Stack st=Stack();
    if(st.isempty()) cout << "empty stack!\n";
    int i;
    customer user = {"undefined",0.0};;
    for(i=0;i<5;i++){
       cout << "enter name: ";
       cin.getline(user.fullname,35);
       cout << "enter payment: ";
       (cin >> user.payment).get();
       if(st.push(user)) 
           cout << "push customer " << user.fullname << " successfully!\n";
       if(st.isfull()) {cout << "full stack!\n";break;}
    }
    cout << "pop customer: \n";
    double total = 0.0;
    for(i=0;i<5;i++){
       if(st.pop(user)){
           cout << user.fullname << "\t" << user.payment << "\n";
           total += user.payment;
           cout << "running total so far is: " << total << "\n";
       }
       if(st.isempty()) {cout << "empty stack!\n";break;}
    }
    return 0;
}
   



   
