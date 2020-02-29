//person.h

#include <string>
#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

class Person{
private:
   string firstname;
   string lastname;
Public:
   Person(const string fn = NULL, const string ln = NULL)
         {firstname = fn; lastname = ln;}
   Person(const char * fn, const char * ln)
         {firstname = fn; lastname = ln;}
   virtual ~Person() {}
   virtual void Set(const string fn, const string ln)
         {firstname = fn; lastname = ln;}
   virtual void Set(const char * fn, const char * ln)
         {firstname = fn; lastname = ln;}
   virtual void Show();
};

void Person::Show(){
   cout << "first name: " << firstname << endl;
   cout << "last name: " << lastname << endl;
}

//************************************************
class Gunslinger: virtual public Person{
private:
   double drawtime;
   int numnotch;
public:
   Gunslinger(const string fn = NULL, const string ln = NULL, 
double dval = 0.0,int num = 0) :Person(fn,ln), drawtime(dval), numnotch(num){}
   Gunslinger(const char * fn, const char * ln, double dval = 0.0, 
int num) :Person(fn,ln), drawtime(dval), numnotch(num){}
   virtual ~Gunslinger(){};
   void setdata(double dval, int num);
   virtual void Set(const string fn, const string ln, double dval, int num);
   virtual void Set(const char * fn, const char * ln, double dval, int num);
   virtual void Show();
   double Draw(){return drawtime};
   int Notch(){return numnotch};
};

void Gunslinger::Show(){
   cout << "gunslinger's name: \n";
   Person::Show();
   cout << "drawtime: " << drawtime << endl;
   cout << "num of notches on his gun: " << numnotch << endl;
}

void setdata(double dval, int num){
   drawtime = dval;
   numnotch = num;
}

void Set(const string fn, const string ln, double dval, int num){
    Person::Set(fn,ln);
    setdata(dval,num);
}

void Set(const char * fn, const char * ln, double dval, int num){
    Person::Set(fn,ln);
    setdata(dval,num);
}
//***************************************************
class Pokerplayer: virtual public Person{
public:
    Pokerplayer(const string fn = NULL, const string ln = NULL) :Person(fn,ln){}
    Pokerplayer(const char * fn, const char * ln) :Person(fn,ln){}
    virtual ~Pokerplayer(){}
    int Draw(){return int(52*rand()/RAND_MAX) + 1;}
};

//************************************************************
class BadDue :public Gunslinger, public Pokerplayer{
public:
    BadDue(const string fn = NULL, const string ln = NULL, double dval = 0.0, int num = 0) 
          :Person(fn,ln), 
    


