#include <iostream>
#include <cstring>   //strlen(), strcpy()
using namespace std;
struct stringy{
     char * str;    //point to a string
     int ct;     //length of string (not counting '\0'
};

//prototype for set(), show()
void set(stringy & beany, char test[]);
void show(const stringy & beany, int times=1);
void show(const char test[], int times=1);

int main(){
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";
    set(beany,testing);
    show(beany);
    show(beany,2);
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing,3);
    show("Done!");
    return 0;
}

void set(stringy & beany, char test[]){
    //allocates space to hold copy of test, sets str member of beany
    //to point to the new block, copies test to new block, and sets ct
    //member of beany
    char * newblock = new char[strlen(test)];
    beany.str = newblock;
    strcpy(newblock, test);
    beany.ct = strlen(beany.str);
    delete [] newblock;
}
void show(const stringy & beany, int times){
     cout << "member string " << times << " times\n";
     for(int i=0;i<times;i++)
        cout << beany.str << endl;
}
void show(const char test[], int times){
     cout << "char array " << times << " times\n";
     for(int i=0;i<times;i++)
         cout << test << endl;
}

