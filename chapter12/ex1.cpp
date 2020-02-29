#include "cow.h"
#include <iostream>

int main(){
   using std::cout;
   Cow test1;
   Cow test2("test2","sleep",12.4);
   cout << "test1:\n";
   test1.ShowCow();
   cout << "test2:\n";
   test2.ShowCow();
   test1 = test2;
   cout << "test1 after test1 = test2:\n";
   test1.ShowCow();
   return 0;
}
