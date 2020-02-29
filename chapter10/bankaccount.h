#ifndef BANKACCOUNT_H_
#define BANKACCOUNT_H_

#include <string>

class bankaccount{
private:
    std::string m_name;
    std::string m_number;
    double m_balance;
public:
    bankaccount();
    bankaccount(std::string name, std::string number, double balance=0.0);
    ~bankaccount(); 
    void open();
    void open(std:: string name, std::string number, double balance);
    void display() const;
    void deposit(double money);
    void withdraw(double money);
};

#endif
