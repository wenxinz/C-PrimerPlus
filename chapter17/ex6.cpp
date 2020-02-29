#include <iostream>
#include <fstream>
#include <cctype>
#include "emp.h"

const int MAX = 5;

int main(){
    using namespace std;

    void showman();
    
    abstr_emp * pc[MAX];
    int classtype, i, index;
    ifstream fin;    
    ofstream fout;

    fin.open("ex6.txt");
    if(!fin.is_open()){
        //output file does not exit, first time through
        //program should solicit data from user, show all the entries
        //and save the information in the output file
        fout.open("ex6.txt");
        showman();
        for(i=0;i < MAX;i++){
            cout << "Enter the entry type(1-4, q to quit): ";
            if(!(cin >> classtype))
                break;
            else{
                cin.get();
                switch(classtype){
                    case 1: pc[i] = new employee; break;
                    case 2: pc[i] = new manager; break;
                    case 3: pc[i] = new fink; break;
                    case 4: pc[i] = new highfink; break;
                }
                pc[i]->setall();
                fout << classtype << endl;
                pc[i]->writeall(fout);
            }
        }
        if(i==MAX)    
            cout << "reach maximum entries\n";
        fout.close();
        index = i;
        cout << "Here're all the entries you entered: \n";
        for(i=0;i<index;i++){
            pc[i]->showall();
        }
    }
    else{
        //output file exist and open sucessfully, subsequent use
        //program should first read and display the file data
        //let user add data, and show all the data
        char ch;
        i=0;
        while((fin >> classtype).get(ch)){
            switch(classtype){
                case 1: pc[i] = new employee; break;
                case 2: pc[i] = new manager; break;
                case 3: pc[i] = new fink; break;
                case 4: pc[i] = new highfink; break;
            }
            pc[i++]->getall(fin);
        }
        index = i;
        cout << "Here're all the entries in the file: \n";
        for(i=0;i < index;i++){
            pc[i]->showall();
        }
        cout << "Do you want to add some data? (y/n)";
        cin >> ch;
        if(tolower(ch) == 'y'){
            fout.open("ex6.txt", ios_base::app);
            showman();
            for(i=index;i < MAX;i++){
                cout << "Enter the entry type(1-4, q to quit): ";
                if(!(cin >> classtype))
                    break;
                else{
                    cin.get();
                    switch(classtype){
                        case 1: pc[i] = new employee; break;
                        case 2: pc[i] = new manager; break;
                        case 3: pc[i] = new fink; break;
                        case 4: pc[i] = new highfink; break;
                    }
                    pc[i]->setall();
                    fout << classtype << endl;
                    pc[i]->writeall(fout);
                }
            }
            if(i==MAX)    
                cout << "reach maximum entries\n";
            fout.close();
            index = i;
        }
        cout << "Here're all the entries you entered: \n";
        for(i=0;i<index;i++){
            pc[i]->showall();
        }
    }
    fin.close();
    return 0;
}

void showman(){
    std::cout.width(20);
    std::cout << std::left << "1 employee" << "2 manager" << std::endl;
    std::cout.width(20);
    std::cout << "3 fink" << "4 highfink" << std::endl;
}
