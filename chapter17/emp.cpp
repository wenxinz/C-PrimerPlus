#include "emp.h"

abstr_emp::abstr_emp(){
	fname = "na";
	lname = "na";
	job = "na";
}

abstr_emp::abstr_emp(const std::string & fn, const std::string & ln, const std::string & j){
	fname = fn;
	lname = ln;
	job = j;
}

void abstr_emp::showall() const{
	std::cout << "first name: " << fname << std::endl
	          << "last name: " << lname << std::endl
	          << "job: " << job << std::endl;
}

void abstr_emp::setall(){
	std::cout << "enter first name: ";
	getline(std::cin, fname);
	std::cout << "enter last name: ";
	getline(std::cin, lname);
	std::cout << "enter job: ";
	getline(std::cin, job);
}

void abstr_emp::getall(std::ifstream & in){
	getline(in, fname);
	getline(in, lname);
	getline(in, job);
}

void abstr_emp::writeall(std::ofstream & out) const{
	out << fname << std::endl << lname << std::endl << job << std::endl;
}

std::ostream & operator<<(std::ostream & os, const abstr_emp & e){
	os << "first name: " << e.fname << '\t' << "last name: " << e.lname;
	return os;
}

abstr_emp::~abstr_emp(){}

void employee::showall() const{
    std::cout << "here's the information of the employee:\n";
	abstr_emp::showall();
}

void employee::setall(){
	std::cout << "enter information of the employee:\n";
	abstr_emp::setall();
}

void employee::getall(std::ifstream & in){
	abstr_emp::getall(in);
}

void employee::writeall(std::ofstream & out) const{
	abstr_emp::writeall(out);
}

manager::manager(const manager & m): abstr_emp(m){
	inchargeof = m.inchargeof;
}

void manager::showall() const{
	std::cout << "here's the information of the manager:\n";
	abstr_emp::showall();
	std::cout << "number of abstr_emps managed: " << inchargeof << std::endl;
}

void manager::setall(){
	std::cout << "enter information of the manager:\n";
	abstr_emp::setall();
	std::cout << "enter number of abstr_emps managed: ";
	std::cin >> inchargeof;
}

void manager::getall(std::ifstream & in){
	abstr_emp::getall(in);
	in >> inchargeof;
}

void manager::writeall(std::ofstream & out) const{
	abstr_emp::writeall(out);
	out << inchargeof << std::endl;
}

fink::fink(const fink & e): abstr_emp(e){
	reportsto = e.reportsto;
}

void fink::showall() const{
	std::cout << "here's the information of the fink:\n";
	abstr_emp::showall();
	std::cout << "to whom fink reports: " << reportsto << std::endl;
}

void fink::setall(){
	std::cout << "enter information of the fink:\n";
	abstr_emp::setall();
	std::cout << "enter to whom fink reports: ";
	getline(std::cin, reportsto);
}

void fink::getall(std::ifstream & in){
	abstr_emp::getall(in);
	getline(in,reportsto);
}

void fink::writeall(std::ofstream & out) const{
	abstr_emp::writeall(out);
	out << reportsto << std::endl;
}

void highfink::showall() const{
	std::cout << "here's the information of the highfink:\n";
	abstr_emp::showall();
	std::cout << "number of abstr_emps managed: " << InChargeOf() << std::endl;
	std::cout << "to whom highfink reports: " << ReportsTo() << std::endl;
}

void highfink::setall(){
	std::cout << "enter the information of the highfink:\n";
	abstr_emp::setall();
	std::cout << "enter number of abstr_emps managed: " ;
	(std::cin >> InChargeOf()).get();
	std::cout << "enter to whom highfink reports: ";
	getline(std::cin, ReportsTo());
}

void highfink::getall(std::ifstream & in){
	abstr_emp::getall(in);
	(in >> InChargeOf()).get();
	getline(in, ReportsTo());
}

void highfink::writeall(std::ofstream & out) const{
	abstr_emp::writeall(out);
	out << InChargeOf() << std::endl;
	out << ReportsTo() << std::endl;
}