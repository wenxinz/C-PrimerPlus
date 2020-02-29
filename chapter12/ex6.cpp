#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "queue.h"

const int MIN_PER_HR = 60;

bool newcustomer(double x); //is there a new customer

int main(){
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;
    std::srand(std::time(0));
    
    cout << "Case Study: Bank of Heather Automatic Teller\n";
    
    long cyclelimit = MIN_PER_HR * 100; 
    double perhour = 15;
   
    double min_per_cust;
    Item temp;
    double avg_wait_time;
    long turnaways;
    long customers;
    long served;
    int wait_time1, wait_time2;
    long line_wait;
 
    while(1){
    Queue line1(10);
    Queue line2(10);
    min_per_cust = MIN_PER_HR/perhour;
    turnaways = 0;
    customers = 0;
    served = 0;
    wait_time1 = wait_time2 = 0;
    line_wait = 0;

    for(int cycle=0;cycle<cyclelimit;cycle++){
           if(newcustomer(min_per_cust)){
              if(line1.isfull() && line2.isfull()) 
                  turnaways++;
              else{
                  customers++;
                  temp.set(cycle);
                  if(line1.queuecount() > line2.queuecount())
                        line2.enqueue(temp);
                  else
                        line1.enqueue(temp);
              }
           }
           if(wait_time1 <= 0 && !line1.isempty()){
              line1.dequeue(temp);
              wait_time1 = temp.ptime();
              line_wait += cycle - temp.when();
              served++;
           }
           if(wait_time1 > 0) wait_time1--;
           if(wait_time2 <= 0 && !line2.isempty()){
              line2.dequeue(temp);
              wait_time2 = temp.ptime();
              line_wait += cycle - temp.when();
              served++;
           }
           if(wait_time2 > 0) wait_time2--;
     }
     
     avg_wait_time = (double) line_wait / served;

     if(customers > 0){
          // cout << "customers accepted: " << customers << endl;
          // cout << "  customers served: " << served << endl;
          // cout << "         turnaways: " << turnaways << endl;
           cout.precision(2);
           cout.setf(ios_base::fixed,ios_base::floatfield);
           cout.setf(ios_base::showpoint);
           cout << " average wait time: "
                << (double) line_wait / served << " minutes\n";
           cout << "customers per hour: " << perhour << endl;
     }
     else
           cout << "No customers!\n";
     
     if(fabs(avg_wait_time-1)<0.05) break;
     else if(avg_wait_time < 1)
             perhour++;
     else perhour--;
       
     cout << "\n";
     }
     return 0;
}

bool newcustomer(double x){
     return (std::rand()*x/RAND_MAX < 1);
}
        
