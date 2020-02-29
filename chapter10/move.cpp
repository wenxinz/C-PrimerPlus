#include "move.h"
#include <iostream>

Move::Move(double a, double b){
     x = a;
     y = b;
}

void Move::showmove() const{
     using std::cout;
     using std::endl;
     cout << "x= " << x << "\t" << "y= " << y << endl;
}

Move Move::add(const Move & m) const{
     double newx, newy;
     newx = x + m.x;
     newy = y + m.y;
     return Move(newx,newy);
}

void Move::reset(double a, double b){
      x = a;
      y = b;
}

