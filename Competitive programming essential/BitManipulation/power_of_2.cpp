#include <iostream>

int main() {
    int n {} ;
    std::cin >> n ; 
    // O(1) 
    if( (n & (n-1)) == 0 ){
        std::cout << "is Power of 2" << std::endl ;
    }else{
        std::cout << "Not a power of 2" << std::endl ;
    } 
    return 0 ;
}