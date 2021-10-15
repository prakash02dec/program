#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_
#include "Savings_Account.hpp"
#include <iostream>
#include <string>
class Trust_Account : public Savings_Account{
    
    private:
    
    static constexpr const char *def_name = "unnamed Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate =0.0;
    static constexpr int max_with= 3;
    static constexpr double max_withdrawl_percent=0.2;
    static constexpr double bonus = 50.00;

    protected:
    int no_of_with;

    public:
    
    Trust_Account(std::string name = def_name , double balance =def_balance , double int_rate = def_int_rate );
    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount) override;
    virtual void print (std::ostream &os ) const override;

    virtual ~Trust_Account() = default;
};

#endif