#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include<string>

class account{
    private:
    std::string name {"account"};
    double balance {0.0};
    
    
    public:
    bool deposit(double bal);
    bool withdraw(double bal);
    void set_balance(double bal);
    double get_balance();
    void set_name( std::string nam );
    std::string get_name();

};


#endif