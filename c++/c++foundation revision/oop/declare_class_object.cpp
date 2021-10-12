
#include<iostream>
#include<string>
#include<vector>
#include "account.h"

class player{
    public:
    //attributes
    std::string name {"player"};
    int health {100};
    int xp {3};

    //method

    void set_name (std::string n){
        name = n;
    }
    bool is_dead();

    // player(){
    //     name="none";
    //     health=100;
    //     xp= 3;
    // }
    // player(std::string name){
    //     std::cout<< "string arg constructor"<<std::endl;
    // } 
    // player(std::string name_val, int health_val , int xp_val){
    //     name =name_val;
    //     health= health_val;
    //     xp= xp_val;
    // } 
    
    // player();
    // player(std::string name);
    // player(std::string name_val, int health_val , int xp_val);


    // player(std::string name_val= "none", int health_val=0 , int xp_val = 0)
    // : name{name_val} , health{health_val}, xp{xp_val}{

    // }

    // player::player(const player &source)
    // :name {source.name} , health {source.health} , xp {source.xp} {

    // }

    // ~player(){
    //     std::cout<<" distructer called for"<< name <<std::endl;
    // }
};

// player::player()
// : name {"none"} , health {0} , xp {0}{

// }
// player::player(std::string name_val)
// : name {name_val}, health {0} , xp{0}{
// }

// player::player(std::string name_val , int health_val , int xp_val)
//  : name {name_val} , health{ health_val} ,  xp {xp_val} {
// }



// player::player()
// : player{"none" , 0 , 0}{

// }
// player::player(std::string name_val)
// : player{name_val, 0 , 0}{
// }

// player::player(std::string name_val , int health_val , int xp_val)
//  : name {name_val} , health{ health_val} ,  xp {xp_val} {
// }






// class account{
//     private:
//     std::string name ;
//     double balance ;
    
    
//     public:
//     account(){
//         name="none";
//         balance=1000;
//     }
//     account(std::string n){
//         name=n;
//     }

//     bool deposit(double bal);
//     bool withdraw(double bal);
//     void set_balance(double bal);
//     double get_balance();
//     void set_name( std::string nam );
//     std::string get_name();

// };

// bool account::deposit(double bal){
    
//         balance += bal;
        
//         return true;
//     }
// bool account::withdraw(double bal){
//         if(balance>0){
//         balance -=bal;
//         return true;
//         }
//         return false;

// }

// void account::set_balance(double bal){
//         balance = bal;
// }
// double account::get_balance(){
//         return balance;
// }
// void account::set_name( std::string nam ){
//         name = nam;
// }
// std::string account::get_name(){
//         return name;
// }

int main(){
    account frank_account;
    frank_account.set_name("frank's account");
    frank_account.set_balance ( 5000);
    frank_account.deposit(1000);
    frank_account.withdraw(500);
    std::cout<<frank_account.get_name()<<" have balance in acount"<< frank_account.get_balance();
    account hero_account;
    
    // player empty;

    // player frank ("frank");
    // // frank.talk("hi there");

    // player hero {"hero" , 100};


    // player *enemy {nullptr};
    // enemy = new player("new boss", 10000, 3000);
    // enemy->set_name("booss");

    // player players[] {frank, hero};

    // std::vector<player> player_vec {frank};
    // player_vec.push_back(hero);


    // delete enemy;
    std::cout<<std::endl;
    return 0;
}