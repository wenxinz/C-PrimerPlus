#include "tv.h"
#include <iostream>

int main(){
    Tv tv;
    Remote remote;
   
    remote.showstate();
    tv.onoff();
    if(tv.set_state(remote))
        remote.showstate();
    tv.onoff();
    if(tv.set_state(remote))
        remote.showstate();
    else
        std::cout << "can't change remote state\n";
    return 0;
}
