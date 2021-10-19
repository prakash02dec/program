#include <iostream>
#include <memory>
#include "Account.hpp"
#include "Checking_Account.hpp"
#include "Savings_Account.hpp"
#include "Trust_Account.hpp"
#include "Account_Util.hpp"

using namespace std;

int main() {
    // test your code here
    try{
    std::unique_ptr<Account> ptr = std::make_unique<Checking_Account> ("prakash" , 1000);
    ptr->withdraw(2000);
    }
    catch (InsufficentFundsException &ex) {
        std::cerr<< ex.what() << std::endl;
    }
    catch (IllegalBalanceException &ex) {
        std::cerr << ex.what() << std::endl ;
    }
    std::cout << "Program completed successfully" << std::endl;
    return 0;
}

