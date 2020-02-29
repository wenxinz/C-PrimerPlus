#include <iostream>
#include <cstring>
#include <new>

struct chaff{
    char dross[20];
    int slag;
};

const int BUF = 512;

int main(){
    using namespace std;
    int i;
    char * buffer;
    buffer = new char[BUF];
    chaff * p1;
    p1 = new (buffer) chaff[2];
    strcpy(p1[0].dross,"something");
    p1[0].slag = 0;
    strcpy(p1[1].dross,"somethine else");
    p1[1].slag = 1;
    for(i=0;i<2;i++){
        cout << i << " chaff.dross: " << p1[i].dross << endl;
        cout << "chaff.slag: " << p1[i].slag << endl;
        cout << &p1[i] << endl;
    }
    return 0;
}
