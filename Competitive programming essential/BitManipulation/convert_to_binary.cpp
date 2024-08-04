#include <iostream>

int convertToBinary(int n ){
    int binary {} ;
    int pow {1} ;
    while(n){
        binary +=  pow * (n&1) ;
        pow *= 10 ;
        n= n>>1 ;
    } 
    return binary ; 
}


int main() {
    int n {15} ;
    std::cout << convertToBinary(n) ; 
    return 0 ;
}