#include <iostream> 

int count_bits(int n ){
    int count {} ;
    while(n){
        count += n&1 ;
        n = n>>1 ;
    }
    return count  ;
}

int count_bits_hack(int n){
    int count {} ;
    while(n>0){
        // remove the last set bit from the current number 
        n = n & (n-1) ;
        count++ ;
    }
    return count ;
}


int main(){
    int n {55} ;
    std::cout << count_bits(n) << std::endl ;
    std::cout << count_bits_hack(n) << std::endl ;
    return 0 ;
}