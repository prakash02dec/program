#ifndef _ACCOUNT_UTIL_H_
#define _ACCOUNT_UTIL_H_
#include <vector>
#include "Account.hpp"
#include "Savings_Account.hpp"
#include "Checking_Accounts.hpp"
#include "Trust_Account.hpp"

// Utility helper functions for Account class

void display(const std::vector<Account *> &accounts);
void deposit(std::vector<Account *> &accounts, double amount);
void withdraw(std::vector<Account *> &accounts, double amount);


#endif