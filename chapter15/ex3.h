//ex3.h
#include <stdexcept>
#include <iostream>

using std::endl;

class badmean: public std::logic_error{
private:
   double a;
   double b;
public:
   explicit badmean(double arg_a, double arg_b, const std::string& what_arg)
        :a(arg_a),b(arg_b),std::logic_error(what_arg){};
   virtual void report();
};

void badmean::report(){
   std::cout << "argument one: " << a << endl
             << "argument two: " << b << endl
             << what() << endl;
}

class bad_hmean: public badmean{
public:
   explicit bad_hmean(double arg_a, double arg_b, const std::string& what_arg)
        :badmean(arg_a,arg_b,what_arg){};
   virtual void report();
};

void bad_hmean::report(){
     std::cout << "function name: hmean\n";
     badmean::report();
}

class bad_gmean: public badmean{
public:
    explicit bad_gmean(double arg_a, double arg_b, const std::string& what_arg)
         :badmean(arg_a,arg_b,what_arg){};
    virtual void report();
};

void bad_gmean::report(){
     std::cout << "function name: gmean\n";
     badmean::report();
}  
