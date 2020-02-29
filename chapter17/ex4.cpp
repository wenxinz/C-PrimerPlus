#include <iostream>
#include <fstream>

int main(int argc, char * argv[]){
    using namespace std;
    if(argc != 4){
        cout << "Usage: " << argv[0]
             << " input_filename1 input_filename2 output_filename\n";
        exit(EXIT_FAILURE);
    }
    ifstream fin1, fin2;
    ofstream fout;
    fin1.open(argv[1]);
    if(!fin1.is_open()){
        cout << "Can't open input file " << argv[1] << endl;
        exit(EXIT_FAILURE);
    }
    fin2.open(argv[2]);
    if(!fin2.is_open()){
        cout << "Can't open input file " << argv[2] << endl;
        exit(EXIT_FAILURE);
    }
    fout.open(argv[3]);
    string temp1, temp2;
    getline(fin1, temp1);
    getline(fin2, temp2);
    while(!fin1.eof()|| !fin2.eof()){
        fout << temp1 + " " + temp2 << endl;
        getline(fin1,temp1);
        getline(fin2,temp2);
    }
    return 0;
}
