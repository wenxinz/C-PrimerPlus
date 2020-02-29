//worker.h

#include <string>
#include <iostream>

class Worker{
private:
    std::string fullname;
    long id;
public:
    Worker() :fullname("no one"), id(0L) {}
    Worker(const std::string & s, long n)
         : fullname(s), id(n) {}
    ~Worker() {};
    void Set();
    void Show() const;
};

void Worker::Show() const{
    std::cout << "Name: " << fullname << std::endl;
    std::cout << "Employee ID: " << id << std::endl;
}

void Worker::Set(){
    std::cout << "Enter worker's name: ";
    getline(std::cin,fullname);
    std::cout << "Enter worker's ID: ";
    std::cin >> id;
    while(std::cin.get() != '\n')
         continue;
}


