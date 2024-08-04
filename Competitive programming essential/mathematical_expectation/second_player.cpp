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
long long factorial (int n ){
    if (n <= 1) return 0 ;
    long long result {1} ; 
    while (n>1){
        result *= n ;
        result %= mod;
        n-- ; 
    }
    return result ;
}

int solve(int n, vector<int> a){
    long long numerator {1} , denomnator {n} ;
    

        for(int i {2} ; i< n ; i++){
            long long temp { (1 + (i-1) + factorial(i-1))%mod };
            numerator += temp*temp ;
            numerator %= mod ;
        }
    
    long long result { ((numerator)*(power((denomnator) , mod-2 , mod)))%mod} ;
    // int result = 1 ;
    return result ; 
}

int main () {
    std::cout <<  solve(34 , vector<int> {1,2 ,3}) << std::endl ;
    // std::cout << power(3, 9 , 11);
    return 0 ;
}