#include <iostream>
#include <unordered_set>

int main(){
    // set is just a collection of keys 
    std::unordered_set<int> s{1,2,3,8,11,15,0} ;
    s.insert(111) ;
    s.erase(11) ;
    
    int key {} ;
    std::cin >> key ;
    if(s.find(key) != s.end() ){ // search in O(1)
        std::cout << key << "is present" ;
    }else{
        std::cout << "not found" ;
    }

    // let us print all the element of unordered set 
    for (auto x : s){
        std::cout << x << std::endl ;
    }
    return 0 ;  
}
