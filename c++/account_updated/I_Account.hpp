#ifndef _I_ACCOUNT_H_
#define _I_ACCOUNT_H_

#include <iostream>

class I_Account {

    public:
    friend std::ostream &operator<<(std::ostream &os , const I_Account &account);
    

    virtual void print(std::ostream &os) const =0;

    virtual ~I_Account() = default;
};

#endif