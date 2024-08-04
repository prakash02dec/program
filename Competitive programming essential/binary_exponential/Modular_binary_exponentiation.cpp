#include<iostream>

const int mod { static_cast<int>(1e9 + 7)} ;

long long pow(long long a , int m){
    long long result{1} ;
    while(m){
        if(m&1) result *= a , result %= mod ;
        a *= a ; 
        a %= mod ;
        m = m>>1 ;
    }
    return result  ;
}

int main() {
    std::cout << pow(2, 200);
    return 0 ; 
}