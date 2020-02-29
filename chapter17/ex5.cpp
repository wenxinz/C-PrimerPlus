#include <iostream>
#include <fstream>
#include <set>

int main(){
    using namespace std;
    
    ostream_iterator<string,char> out_iter(cout, "\n");
    set<string> mat, pat;
    string temp;
    ifstream fin;
    fin.open("mat.dat");
    if(!fin.is_open()){
        cout << "Can't open mat.dat\n";
        exit(EXIT_FAILURE);
    }
    while(getline(fin,temp)){
        mat.insert(temp);
    }
    fin.clear();
    fin.close();
    cout << "list of mat's friend:\n";
    copy(mat.begin(), mat.end(), out_iter);
    cout << endl;   
 
    fin.open("pat.dat");
    if(!fin.is_open()){
        cout << "Can't open pat.dat\n";
        exit(EXIT_FAILURE);
    }
    while(getline(fin,temp)){
        pat.insert(temp);
    }
    fin.close();
    cout << "list of pat's friend:\n";
    copy(pat.begin(), pat.end(), out_iter); 
    
    ofstream fout;
    fout.open("matnpat.dat");
    ostream_iterator<string, char> fout_iter(fout, "\n");
    set_union(mat.begin(), mat.end(), pat.begin(), pat.end(), fout_iter);
    fout.close();
    
    return 0; 
} 
