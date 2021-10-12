#include "account.h"

bool account::deposit(double bal){
    
        balance += bal;
        
        return true;
    }
bool account::withdraw(double bal){
        if(balance>0){
        balance -=bal;
        return true;
        }
        return false;

}

void account::set_balance(double bal){
        balance = bal;
}
double account::get_balance(){
        return balance;
}
void account::set_name( std::string nam ){
        name = nam;
}
std::string account::get_name(){
        return name;
}