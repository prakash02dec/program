#include <iostream> 
#include <climits>

int main() {
    int n{32} ;
    // 0101 0101 0101 0101 0101 0101 0101 0101 or 1431655765 
    if((n & (n-1))==0 &&  (1431655765&n)==n) std::cout << "Power of 4" << std::endl ;
    else std::cout << "Not power of 4" << std::endl ;

    return 0 ;
}