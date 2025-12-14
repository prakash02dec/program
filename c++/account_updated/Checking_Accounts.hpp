#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_   
#include "Account.hpp"
#include <iostream>
#include <string>

class Checking_Account : public Account{

    private :
    static constexpr const char *def_name = "unnamed account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_fee = 1.5;

    protected:
    double fee;

    public:
    Checking_Account(std::string name = def_name ,double balance = def_balance , double fee = def_fee);
    virtual bool withdraw(double amount)override;
    virtual bool deposit(double amount) override;
    virtual void print (std::ostream &os)const override;

    virtual ~Checking_Account() = default;

}; 

#endif