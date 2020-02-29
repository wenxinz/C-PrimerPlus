// stock.h ---dynamically allocated memory

#include <cstring>
#include "stock.h"

//constructors
Stock::Stock(){  // default constructor
    company = new char[1];
    company[0] = '0';
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const char * co, int n, double pr){
    int len = std::strlen(co); 
    company = new char[len+1];
    std::strcpy(company,co);
    if(n < 0){
        std::cerr << "Number of shares can't be negative;"
                  << company << " shares set to 0.\n";
        shares = 0;
     }
     else
        shares = n;
     share_val = pr;
     set_tot();
}

Stock::Stock(const Stock & s){  //copy constructor
     int len = std::strlen(s.company);
     company = new char[len+1];
     std::strcpy(company, s.company);
     shares = s.shares;
     share_val = s.share_val;
     total_val = s.total_val;
}

// class destructor
Stock::~Stock(){
     delete [] company;
}

// other methods
void Stock::buy(int num, double price){
     if(num < 0){
         std::cerr << "Number of shares purchased can't be negative;"
                   << "Transaction is aborted.\n";
     }
     else{
         shares += num;
         share_val = price;
         set_tot();
     }
}

void Stock::sell(int num, double price){
     using std::cerr;
     if(num < 0){
         cerr << "Number of shares sold can't be negative. "
              << "Transaction is aborted.\n";
     }
     else if(num > shares){
         cerr << "You can't sell more than you have! "
              << "Transaction is aborted.\n";
     }
     else{
         shares -= num;
         share_val = price;
         set_tot();
     }
}

void Stock::update(double price){
     share_val = price;
     set_tot();
}

const Stock & Stock::topval(const Stock & s) const{
     if(s.total_val > total_val)
           return s;
     else
           return *this;
}

Stock & Stock::operator=(const Stock & s){
      if(this == &s)
           return *this;
      delete [] company;
      company = new char[std::strlen(s.company)+1];
      std::strcpy(company, s.company);
      shares = s.shares;
      share_val = s.share_val;
      total_val = s.total_val;
      return *this;
}

ostream & operator<<(ostream & os, const Stock & s){
      os << "Company: " << s.company
         << " Shares: " << s.shares << std::endl
         << " Share Price: $" << s.share_val
         << " Total Worth: $" << s.total_val << std::endl;
      return os;
}
 
