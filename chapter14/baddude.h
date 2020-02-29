//baddude.h
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::string;

class Person{
private:
	string fname;
    string lname;
public:
	Person(string fn="null", string ln="null"){fname = fn; lname = ln;}
	virtual ~Person(){}
	virtual void Show();
	virtual void Set();
};

void Person::Show(){
	std::cout << "firstname: " << fname << '\t'
	          << "lastname: " << lname << std::endl;
}

void Person::Set(){
    std::cout << "Enter firstname: ";
    std::getline(std::cin,fname);
    std::cout << "Enter lastname: ";
    std::getline(std::cin,lname);
}

class Gunslinger: virtual public Person{
private:
	double dtime;
	int notch;
public:
	Gunslinger(string fn="null", string ln="null", double dt=0.0, double n=0)
	         : Person(fn,ln){dtime = dt; notch = n;}
	virtual ~Gunslinger(){}
	virtual double Draw(){return dtime;}
	virtual void Show();
	virtual void Data();
	virtual void SetData();
	virtual void Set();
};

void Gunslinger::Data(){
	std::cout << "draw time: " << dtime << std::endl
	          << "number of notches: " << notch << std::endl;
}

void Gunslinger::Show(){
    Person::Show();
    Data();
}

void Gunslinger::SetData(){
    std::cout << "Enter draw time: ";
    std::cin >> dtime;
    std::cout << "Enter number of notches: ";
    std::cin >> notch;
}

void Gunslinger::Set(){
	Person::Set();
	SetData();
}

class Pokerplayer: virtual public Person{
public:
	Pokerplayer(string fn="null", string ln="null"): Person(fn,ln){}
	virtual ~Pokerplayer(){}
	virtual int Draw();
	virtual void Show();
	virtual void Set(){Person::Set();}
};

int Pokerplayer::Draw(){
	std::srand(std::time(0));
    return std::rand()%52+1;
}

void Pokerplayer::Show(){
	Person::Show();
	std::cout << "card value: " << Draw() << std::endl;
}

class BadDude: public Gunslinger, public Pokerplayer{
public:
	BadDude(string fn="null", string ln="null", double dt=0.0, double n=0)
	        :Gunslinger(fn,ln,dt,n), Person(fn,ln){}
	~BadDude(){}
	virtual double Gdraw();
	virtual int Cdraw();
	virtual void Show();
	virtual void Set();
};

double BadDude::Gdraw(){
	return Gunslinger::Draw();
}

int BadDude::Cdraw(){
	return Pokerplayer::Draw();
}

void BadDude::Show(){
	Person::Show();
	Gunslinger::Data();
	std::cout << "next card drawn: " << Cdraw() << std::endl;
}

void BadDude::Set(){
	Person::Set();
	Gunslinger::SetData();
}