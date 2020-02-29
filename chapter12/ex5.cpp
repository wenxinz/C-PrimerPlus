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
    
   // cout << "Enter the number of simulation hours: ";
    long cyclelimit = MIN_PER_HR * 100;
 
    cout << "Enter the average number of customers per hour: ";
    double perhour;
    cin >> perhour;
   
    double min_per_cust;
    Item temp;
    double avg_wait_time;
    long turnaways = 0;
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    int wait_time = 0;
    long line_wait = 0;
 
    while(1){
    Queue line(10); //every trial, create a new line -- this statement should 
//be included in the while loop!!! 
    min_per_cust = MIN_PER_HR/perhour;
    turnaways = 0;
    customers = 0;
    served = 0;
    sum_line = 0;
    wait_time = 0;
    line_wait = 0;

    for(int cycle=0;cycle<cyclelimit;cycle++){
           if(newcustomer(min_per_cust)){
              if(line.isfull()) 
                  turnaways++;
              else{
                  customers++;
                  temp.set(cycle);
                  line.enqueue(temp);
              }
           }
           if(wait_time <= 0 && !line.isempty()){
              line.dequeue(temp);
              wait_time = temp.ptime();
              line_wait += cycle - temp.when();
              served++;
           }
           if(wait_time > 0) wait_time--;
           sum_line += line.queuecount();
           if(line_wait < 0) exit(1);
     }
     
     avg_wait_time = (double) line_wait / served;

     if(customers > 0){
          // cout << "customers accepted: " << customers << endl;
          // cout << "  customers served: " << served << endl;
          // cout << "         turnaways: " << turnaways << endl;
          // cout << "average queue size: ";
           cout.precision(2);
           cout.setf(ios_base::fixed,ios_base::floatfield);
           cout.setf(ios_base::showpoint);
          // cout << (double) sum_line / cyclelimit << endl;
           cout << " average wait time: "
                << (double) line_wait / served << " minutes\n";
           cout << "customers per hour: " << perhour << endl;
     }
     else
           cout << "No customers!\n";
     
     if(fabs(avg_wait_time-1)<0.01) break;
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
        
