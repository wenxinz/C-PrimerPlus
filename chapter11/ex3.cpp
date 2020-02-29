#include <iostream>
#include <cstdlib>
#include <ctime>
#include "vect.h"

int main(){
    using namespace std;
    using VECTOR::Vector;
    srand(time(0));
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    double N;
    cout << "Enter target distance (q to quit): ";
    cin >> target;
    cout << "Enter step length: ";
    cin >> dstep;
    cout << "Enter # trails: ";
    cin >> N;
    double max, min, average = 0.0;
    for(int i=0;i<N;i++){
        while(result.magval() < target){
            direction = rand()%360;
            step.set(dstep, direction, 'p');
            result = result + step;
            steps++;
        }
        cout << "After " << steps << " steps, the subject "
             "has the following location:\n";
        cout << result << endl;
        result.polar_mode();
        cout << " or\n" << result << endl;
        cout << "Average outward distance per step = "
             << result.magval()/steps << endl;
        if(i==0){min = steps; max = steps;}
        else{
           if(min > steps) min = steps;
           if(max < steps) max = steps;
        }
        average += steps;
        steps = 0;
        result.set(0.0, 0.0);
    }
    cout << "max: " << max << endl;
    cout << "min: " << min << endl;
    cout << "average: " << average/N << endl;
    return 0;
}

