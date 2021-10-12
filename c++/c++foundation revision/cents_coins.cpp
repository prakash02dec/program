#include<iostream>

int main(){
    const int dollar_value {100};
    const int quarter_value {25};
    const int dime_value {10};
    const int nickel_value {5};

    int amount_in_cents {};

    std::cout<<"Enter the value in cents : ";                                                                                           
    std::cin>>amount_in_cents;

    int balance {}, dollar {}, quarter {} , dime {} , nickel {} , pennies;
    dollar = amount_in_cents / dollar_value;
    balance = amount_in_cents % dollar_value;
    quarter = balance / quarter_value;
    balance %= quarter_value;
    dime = balance/dime_value;
    balance %= dime_value;
    nickel = balance / nickel_value;
    balance %= nickel_value;
    pennies = balance;

    std::cout<<"\n==========================================================";
    std::cout<<"\n you can provide this change as follows :"<<std::endl;
    std::cout<<"dollars : "<<dollar<<std::endl;
    std::cout<<"quarter : "<<quarter<<std::endl;
    std::cout<<"dimes : "<<dime<<std::endl;
    std::cout<<"nickles : "<<nickel<<std::endl;
    std::cout<<"pennies : "<<pennies<<std::endl;

    std::cout<<std::endl;
    return 0;

}