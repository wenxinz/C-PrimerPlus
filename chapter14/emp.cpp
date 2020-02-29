//emp.cpp

#include "emp.h"

abstr_emp::abstr_emp(){
	fname = "NULL";
	lname = "NULL";
	job = "NULL";
}

abstr_emp::abstr_emp(const std::string &fn, const std::string & ln,
	                 const std::string &j){
	fname = fn;
	lname = ln;
	job = j;
}

abstr_emp::~abstr_emp(){}

void abstr_emp::ShowAll() const{
	std::cout << "fistname: " << fname << '\t' 
	          << "lastname: " << lname << std::endl
	          << "job: " << job << std::endl;	       
}

void abstr_emp::SetAll(){
	std::cout << "Enter firstname: ";
	std::getline(std::cin, fname);
	std::cout << "Enter lastname: ";
	std::getline(std::cin, lname);
	std::cout << "Enter job: ";
	std::getline(std::cin, job);
}

std::ostream & operator<<(std::ostream & os, const abstr_emp & e){
	os << "firstname: " << e.fname << '\t'
	          << "lastname: " << e.lname;
	return os;
}

//-------------------------------------------------------------------------

employee::employee(): abstr_emp(){}

employee::employee(const std::string & fn, const std::string & ln, 
	               const std::string & j): abstr_emp(fn,ln,j){}

void employee::ShowAll() const{
	std::cout << "employee:\n";
	abstr_emp::ShowAll();
}

void employee::SetAll(){
	abstr_emp::SetAll();
}

//--------------------------------------------------------------------------

manager::manager(): abstr_emp(){
	inchargeof = 0;
}

manager::manager(const std::string & fn, const std::string & ln,
	             const std::string & j, int ico): abstr_emp(fn,ln,j){
	inchargeof = ico;
}

manager::manager(const abstr_emp & e, int ico): abstr_emp(e){
	inchargeof = ico;
}

manager::manager(const manager & m): abstr_emp(m){
	inchargeof = m.inchargeof;
}

void manager::ShowAll() const{
	std::cout << "manager:\n";
	abstr_emp::ShowAll();
	std::cout << "Number of abstr_emp managed: " << inchargeof << std::endl;
}

void manager::SetAll(){
	abstr_emp::SetAll();
	std::cout << "Enter number of abstr_emp managed: ";
	std::cin >> inchargeof;
}

//------------------------------------------------------------------------------

fink::fink(): abstr_emp(){
	reportsto = "NULL";
}

fink::fink(const std::string & fn, const std::string & ln, 
	       const std::string & j, const std::string & rpo): abstr_emp(fn,ln,j){
	reportsto = rpo;
}

fink::fink(const abstr_emp & e, const std::string & rpo): abstr_emp(e){
	reportsto = rpo;
}

fink::fink(const fink & e): abstr_emp(e){
	reportsto = e.reportsto;
}

void fink::ShowAll() const{
	std::cout << "fink:\n";
	abstr_emp::ShowAll();
	std::cout << "To whom fink reports: " << reportsto << std::endl;
}

void fink::SetAll(){
	abstr_emp::SetAll();
	std::cout << "Enter to whom fink reports: ";
	std::getline(std::cin, reportsto);
}

//--------------------------------------------------------------------------------

highfink::highfink(): manager(), fink(), abstr_emp(){}

highfink::highfink(const std::string & fn, const std::string & ln, 
	               const std::string & j, const std::string & rpo, int ico)
	               : manager(fn,ln,j,ico), fink(fn,ln,j,rpo), abstr_emp(fn,ln,j){}

highfink::highfink(const abstr_emp & e, const std::string & rpo, int ico)
                   : manager(e,ico), fink(e,rpo), abstr_emp(e){}

highfink::highfink(const fink & f, int ico)
                   : manager(f,ico), fink(f), abstr_emp(f){}

highfink::highfink(const manager & m, const std::string & rpo)
                   : manager(m), fink(m,rpo), abstr_emp(m){}

highfink::highfink(const highfink & h)
                   : manager(h), fink(h), abstr_emp(h){}

void highfink::ShowAll() const{
	std::cout << "highfink:\n";
	abstr_emp::ShowAll();
	std::cout << "Number of abstr_emp managed: " << manager::InChargeOf() << std::endl
	          << "To whom fink reports: " << fink::ReportsTo() << std::endl;
}                  

void highfink::SetAll(){
	abstr_emp::SetAll();
	std::cout << "Enter number of abstr_emp managed: ";
	(std::cin >> manager::InChargeOf()).get();
    std::cout << "Enter to whom fink reports: ";
	std::getline(std::cin, fink::ReportsTo());
}
















