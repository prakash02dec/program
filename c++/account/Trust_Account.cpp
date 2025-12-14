#include "Trust_Account.hpp"

Trust_Account::Trust_Account(std::string name , double balance , double int_rate)
: Savings_Account{name ,balance, int_rate} , no_of_with{0} {}

bool Trust_Account::deposit(double amount){
    if(amount >= 5000)
    amount += bonus;

    return Savings_Account::deposit(amount);
}
bool Trust_Account::withdraw(double amount){
    if(no_of_with < max_with && amount <= max_withdrawl_percent*balance && Savings_Account::withdraw(amount)) {no_of_with++ ; return true;}
    std::cout << "you reach max limit of withdrawl this year";
    return false;
}
std::ostream &operator<<(std::ostream &os , const Trust_Account &account){
     os << "[Trust_Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "% withdrawls : "<< account.no_of_with << " ]";
    return os;
}