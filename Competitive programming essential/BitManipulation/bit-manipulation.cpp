// write function to 
// get i th bit 
// set i th bit
// clear i th bit

#include <iostream>

int getIthBit(int n , int i ){
    int mask {1<<i} ;
    return (n & mask) > 0 ? 1 : 0 ;
}

void setIthBit(int &n , int i){
    int mask {1<<i} ;
    n = n | mask ;
}

void clearIthBit(int &n ,int i){
    int mask {~(1<<i)} ;
    n = n & mask ;
}

void updateIthBit(int &n , int i , int v){
    clearIthBit(n ,i) ;
    int mask = v << i ;
    n = n | mask ;
}

void clearLastIBits(int &n , int i ){
    int mask {-1<<i} ;
    n = n & mask ;
}

void clearBitsInRange(int &n , int i , int j){
    int a {-1<<(j+1)} ; 
    int b { (1<<i) -1} ;
    int mask {a|b} ;

    n = n & mask ;
}

int main() {
    int n {5} ;
    int i {} ;
    std::cin >> i ;
    std::cout << getIthBit(n , i) ;
    setIthBit(n,5) ;
    clearIthBit(n , 5 ) ;
    std::cout << std::endl << n ;
    return 0 ; 
}