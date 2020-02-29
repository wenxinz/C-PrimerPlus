#include <iostream>
#include "bankaccount.h"

bankaccount::bankaccount(){
    m_name = "\0";
    m_number = "\0";
    m_balance = 0.0;
}

bankaccount::bankaccount(std::string name, std::string number, double balance){
    m_name = name;
    m_number = number;
    m_balance = balance;
}

bankaccount::~bankaccount(){}

void bankaccount::open(){
    using std::cout;
    using std::cin;
    cout << "enter depositor's name: ";
    std::getline(cin,m_name);
    cout << "enter account number: ";
    std::getline(cin,m_number);
    cout << "enter balance: ";
    cin >> m_balance;
}

void bankaccount::open(std::string name, std::string number, double balance){
    m_name = name;
    m_number = number;
    m_balance = balance;
}

void bankaccount::display() const{
    using std::cout;
    using std::endl;
    cout << "depositor's name: " << m_name << endl;
    cout << "account number: " << m_number << endl;
    cout << "balance: " << m_balance << endl;
}

void bankaccount::deposit(double money){
     using std::cout;
     using std::endl;
     cout << "deposit " << money << endl;
     m_balance += money;
     cout << "the balance now is: " << m_balance << endl;
}

void bankaccount::withdraw(double money){
     using std::cout;
     using std::endl;
     if(money > m_balance)
         std::cerr << "not enough money in the account" << endl;
     else{
         cout << "withdraw " << money << endl;
         m_balance -= money;
         cout << "the balance now is: " << m_balance << endl;
     }
}

