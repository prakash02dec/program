
#include <iostream>
#include <vector>
#include "Account_Util.hpp"

using namespace std;

int main() {
    cout.precision(2);
    cout << fixed;




    Account *p1 = new Checking_Account {"thor", 5000, 5.0} ;
    Account *p2 = new Savings_Account {"captain America", 5000, 5.0} ;
    Account *p3 = new Trust_Account {"iron man", 5000, 5.0} ;

    std::vector <Account*> accounts {p1,p2,p3};
    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts, 2000);
    

    return 0;
}

