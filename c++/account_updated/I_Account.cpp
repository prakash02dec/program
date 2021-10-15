#include "I_Account.hpp"
#include <iostream>

std::ostream &operator<<(std::ostream &os , const I_Account &account){
    account.print(os);
    return os;
}

