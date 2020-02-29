#include <iostream>
#include <fstream>

int main(int argc, char * argv[]){
    using namespace std;
    
    if(argc != 3){
        cout << "Usage: " << argv[0] << " input_filename output_filename\n";
        exit(EXIT_FAILURE);
    }
    ifstream fin;
    ofstream fout;
    fin.open(argv[1]);
    if(!fin.is_open()){
        cout << "Can't open the input file\n";
        exit(EXIT_FAILURE);
    }
    fout.open(argv[2]);
    char ch;
    while(fin.get(ch)){
        fout << ch;
    }
    fin.close();
    fout.close();
    return 0;
}
