#include <iostream> 
#include <unordered_map>
#include <string>
#include <numeric>

int main() {
    std::unordered_map<std::string , int > menu ;

    // Insert key value pairs inside the hashtable O(1) operation
    menu["maggi"] = 15 ;
    menu["colddrink"] = 20 ;
    menu["dosa" ] = 20 ;


    //search
    std::string item {} ;
    std::cin>> item ;

    if(menu.count(item)==0 ){
        std::cout << item << "is not available";
    }else{
        std::cout << item << " is avaible and its cost is " << menu[item] << std::endl  ;
    }
    // deletion
    menu.erase("dosa");
    
    // we can iterate over all the key - values pair that are present 
    for(std::pair<std::string , int > item : menu){
        std::cout<< item.first << " - " << item.second << std::endl ;
    }
    
    return 0 ;

}

// helps in optimizing bruteforce solution 
// to get in 