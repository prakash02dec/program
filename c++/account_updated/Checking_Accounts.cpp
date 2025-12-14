#include "Checking_Accounts.hpp"

Checking_Account::Checking_Account(std::string name , double balance , double fee)
    : Account{name , balance} , fee {fee} { }

bool Checking_Account::withdraw(double amount ){
    amount += fee;
    return Account::withdraw(amount);
}

bool Checking_Account::deposit(double amount ){
    return Account::deposit(amount);
}

void Checking_Account::print(std::ostream &os ) const{
    os << "[Checking_Account: " << name << ": " << balance << ", " << fee << "]";
}