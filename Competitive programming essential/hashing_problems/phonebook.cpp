#include <iostream>
#include <map>
#include <list>
#include <string>

int main(){
    std::map<std::string , std::list<std::string>> phonebook {} ;
    phonebook["Prateek"].push_back("3243452343") ;
    phonebook["Prateek"].push_back("32434534343") ;
    phonebook["Prateek"].push_back("3234534343") ;

    phonebook["Prakash"].push_back("323453443") ;
    phonebook["Prakash"].push_back("3243534543") ;
    phonebook["Prakash"].push_back("3234543433") ;
    
    return 0 ;
}