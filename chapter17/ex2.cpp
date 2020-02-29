//end-of-file: ctrl + d
#include <iostream>
#include <fstream>

int main(int argc, char * argv[]){
    if(argc == 1){
        std::cerr << "Usage: " << argv[0] << " filename\n";
        exit(EXIT_FAILURE);
    }
    std::ofstream fout;
    fout.open(argv[1]);
    char ch;
    while(std::cin.get(ch)){
        fout << ch;
    }
    return 0;
}
