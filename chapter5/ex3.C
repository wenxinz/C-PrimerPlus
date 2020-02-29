#include <iostream>

int main(){
    using namespace std;
    double cleo, daphne;
    int i;
    for(i=1,cleo=100,daphne=100; cleo <= daphne; i++){
        daphne = daphne + 100.0 * 0.1;
        cleo = cleo * (1+0.05);
    }
    cout << "It takes " << i << " years " << "for the value of Cleo's \
investment (" << cleo << ") to exceed the value of Daphne's (" <<\
daphne << ")" << endl;
    return 0;
}
