#include<bits/stdc++.h>
using namespace std;

const int mod {1'000'000'007} ;

long long power (long long a , long long n , int m){
    long long result{1} ;
    while(n){
        if(n&1) result *= a , result %= m ; 
        a *= a ;
        a %= m ;
        n >>= 1 ; 
    }
    return result ; 
}

int solve(int n){
    long long numerator {0} , denomnator {0} ;
    long long temp {power(26,n/2 , mod)} ;
    numerator = ((temp*25)%mod + (2*(temp-1))%mod) ;
    if(!(n&1)) numerator -= 25 ;
    // numerator /= 25 ;
    numerator %= mod ;
    
    denomnator = (temp*25)%mod ;
    // denomnator /= 25 ;
    // std::cout << "numerator : "  << numerator << " denomnator : " << denomnator  ;
    long long result { ((numerator)*(power((denomnator) , mod-2 , mod)))%mod} ;
    // int result = 1 ;
    return result ; 
}

int main () {
    std::cout <<  solve(2) << std::endl ;
    // std::cout << power(3, 9 , 11);
    return 0 ;
}