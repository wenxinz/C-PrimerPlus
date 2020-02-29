#include <iostream>
using namespace std;

const int SLEN = 30;
struct student{
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};

int getinfo(student pa[], int n);
void display1(student st);
void display2(const student * ps);
void display3(const student pa[], int n);

int main(){
    cout << "Enter class size: ";
    int class_size;
    cin >> class_size;
    while(cin.get() != '\n')
        continue;
    student * ptr_stu = new student[class_size];
    int entered = getinfo(ptr_stu, class_size);
    for(int i=0; i<entered; i++){
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
    }
    display3(ptr_stu, entered);
    delete [] ptr_stu;
    cout << "Done\n";
    return 0;
}

int getinfo(student pa[], int n){
     int i;
     for(i=0;i<n;i++){
         cout << "Enter info of student " << i << " : \n";
         cout << "full name: ";
         cin.get(pa[i].fullname,SLEN);
         if(cin.fail() == true) {cin.clear();break;}
         cin.get();
         cout << "hobby: ";
         cin.getline(pa[i].hobby,SLEN);
         cout << "ooplevel: ";
         (cin >> pa[i].ooplevel).get();
     }
     return i;
}

void display1(student st){
      cout << "display1: \n";
      cout << "full name: " << st.fullname << endl;
      cout << "hobby: " << st.hobby << endl;
      cout << "ooplevel: " << st.ooplevel << endl;
      cout << endl;
}

void display2(const student * ps){
      cout << "display2: \n";
      cout << "full name: " << ps->fullname << endl;
      cout << "hobby: " << ps->hobby << endl;
      cout << "ooplevel: " << ps->ooplevel << endl;
      cout << endl;
}

void display3(const student pa[], int n){
      for(int i=0;i<n;i++){
          cout << "student #" << i+1 << " : \n";
          cout << "full name: " << pa[i].fullname << endl;
          cout << "hobby: " << pa[i].hobby << endl;
          cout << "ooplevel: " << pa[i].ooplevel << endl;
      }
}        
