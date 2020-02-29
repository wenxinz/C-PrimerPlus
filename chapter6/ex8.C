#include <iostream>
#include <fstream>
#include <cstdlib>

int main(){
    using namespace std;
    char ch;
    int i=0;
    ifstream infile;
    infile.open("testfile.txt");
    if(!infile.is_open()){
       cout << "Could not open the file! \n";
       exit(EXIT_FAILURE);
    }
    infile.get(ch);
    while(infile.good()){
         i++;
         infile.get(ch);
    }
    cout << i << " characters in the file" << endl;
    return 0;
}

