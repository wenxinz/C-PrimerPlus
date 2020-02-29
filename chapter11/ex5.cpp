#include "stonewt.h"
#include <iostream>

int main(){
    using std::cout;
    using std::endl;
    Stonewt jimmy = 150.0;
    Stonewt bobby(200,12.0);
    Stonewt danny(1205);
    jimmy.stone_form();
    bobby.intpounds_form();
    danny.pounds_form();
    cout << "Jimmy's weight(stone_form): " << jimmy << endl;
    cout << "Bobby's weight(intpounds_form): " << bobby << endl;
    cout << "Danny's weight(pounds_form): " << danny << endl;
    cout << "Jimmy + Bobby's weight: " << jimmy + bobby << endl;
    cout << "Bobby - Danny's weight: " << bobby - danny << endl;
    cout << "10*Danny's weight: " << 10 * danny << endl;
    cout << "Danny's weight * 10: " << danny * 10 << endl;
    return 0;
}
