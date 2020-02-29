#include <iostream>
#include "golf.h"

int main(){
    golf ann;
    setgolf(ann, "Ann Birdfree", 24);
    showgolf(ann);
    handicap(ann, 15);
    showgolf(ann);
    while(setgolf(ann)){
       showgolf(ann);
    }
    return 0;
}

