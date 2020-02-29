#include <iostream>
#include <cstdlib>

using namespace std;
const int strsize = 20;

// Benevolent Order of Programmers name structure
struct bop{
    char fullname[strsize]; //real name
    char title[strsize]; //job title
    char bopname[strsize]; //secret BOP name
    int preference; // 0=fullname, 1=title, 2=bopname
};

void displaybyname(bop bopreport[], int num);
void displaybytitle(bop bopreport[], int num);
void displaybybopname(bop bopreport[], int num);
void displaybypreference(bop bopreport[], int num);
 
int main(){
    bop bopreport[]={{"Wimp Macho", "Senior Programmer", "Wimp", 0},
                     {"Raki Rhodes", "Junior Programmer", "Raki", 1},
                     {"Celia Laiter", "intern", "MIPS", 2},
                     {"Hoppy Hipman", "Analyst Trainee", "Hoppy", 1},
                     {"Pat Hand", "Data Scientist", "LOOPY", 2}};
    //show menu
    cout << "Benevolent Order of Programmers Report\n"
            "a. display by name 	b. display by title\n"
            "c. display by bopname      d. display by preference\n"
            "q. quit\n";
    //
    char ch;
    cout << "Enter your choice: ";
    int k = 1;
    while(k){
       (cin.get(ch)).get();
       switch(ch){
          case 'a' : displaybyname(bopreport,5); 
                    // cout << "Next choice: "; 
                     break;
          case 'b' : displaybytitle(bopreport,5); 
                    // cout << "Next choice: "; 
                     break;
          case 'c' : displaybybopname(bopreport,5); 
                    // cout << "Next choice: "; 
                     break;
          case 'd' : displaybypreference(bopreport,5); 
                    // cout << "Next choice: "; 
                     break;
          case 'q' : cout << "Bye!" << endl; exit(0);
       }
     cout << "Next choice: ";
     }
     return 0;
}

void displaybyname(bop bopreport[], int num){
      for(int i=0;i<num;++i){
          cout << bopreport[i].fullname << endl;
      }
}

void displaybytitle(bop bopreport[], int num){
      for(int i=0;i<num;++i){
          cout << bopreport[i].title << endl;
      }
}

void displaybybopname(bop bopreport[], int num){
      for(int i=0;i<num;++i){
          cout << bopreport[i].bopname << endl;
      }
}

void displaybypreference(bop bopreport[], int num){
      for(int i=0;i<num;++i){
           switch(bopreport[i].preference){
               case 0: cout << bopreport[i].fullname << endl; break;
               case 1: cout << bopreport[i].title << endl; break;
               case 2: cout << bopreport[i].bopname << endl; break;
           }
      }
} 
