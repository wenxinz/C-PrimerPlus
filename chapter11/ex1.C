//ex1.C --compile with vect.cpp

#include "vect.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

int main(){
    using namespace std;
    using VECTOR::Vector;
    srand(time(0));
    ofstream output;
    output.open("ex1.txt");
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    cout << "Enter target distance (q to quit): ";
    while(cin >> target){
        cout << "Enter step length: ";
        if(!(cin >> dstep)) break;
        output << "Target Distance: " << target << ", Step Size: "
               << dstep << endl;
        while(result.magval() < target){
            direction = rand()%360;
            step.set(dstep, direction, 'p');
            result = result + step;
            output << steps << ": " << result << endl;
            steps++;
        }
        output << "After " << steps << " steps, the subject "
             "has the following location:\n";
        output << result << endl;
        result.polar_mode();
        output << "or\n" << result << endl;
        output << "Average outward distance per step = " 
               << result.magval()/steps << endl;
        steps = 0;
        result.set(0.0, 0.0);
        cout << "Enter target distance (q to quit): ";
     }
     cout << "Bye!\n";
     return 0;
}
