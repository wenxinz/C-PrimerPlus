#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>

class Store{
private:
    std::ofstream * foutp;
public:
    Store(std::ofstream & out){foutp = &out;}
    void operator()(const std::string & str);
};

void Store::operator()(const std::string & str){
    std::size_t len = str.length();
    foutp->write((char *)&len, sizeof(std::size_t));
    foutp->write(str.data(),len);
}

int main(){
    void ShowStr(const std::string & str);
    void GetStrs(std::ifstream & fin, std::vector<std::string> & vstr);

    using namespace std;
    vector<string> vostr;
    string temp;

//acquire strings
    cout << "Enter strings (empty line to quit):\n";
    while(getline(cin,temp) && temp[0] != '\0')
        vostr.push_back(temp);
    cout << "Here is your input.\n";
    for_each(vostr.begin(), vostr.end(), ShowStr);

//store in a file
    ofstream fout("strings.dat", ios_base::out | ios_base::binary);
    for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();

//recover file contents
    vector<string> vistr;
    ifstream fin("strings.dat", ios_base::in | ios_base::binary);
    if(!(fin.is_open())){
        cerr << "Could not open file for input.\n";
        exit(EXIT_FAILURE);
    }
    GetStrs(fin, vistr);
    cout << "\nHere are the strings read from the file: \n";
    for_each(vistr.begin(), vistr.end(), ShowStr);
    
     return 0;
}

void ShowStr(const std::string & str){
    std::cout << str << std::endl;
}

void GetStrs(std::ifstream & fin, std::vector<std::string> & vstr){
    std::size_t len;
    std::string temp;
    while(fin.read((char *)&len,sizeof(std::size_t))){
        temp = "";
        for(int i=0;i<len;i++){
            temp += fin.get();
        }
        vstr.push_back(temp); 
    }
}
