#include<bits/stdc++.h>
using namespace std;

long long power(long long a , long long m){
    long long result {1} ;
    while(m){
        if(m&1) result *= a ;
        a *= a ; 
        m >>= 1 ; 
    }
    return result ;
}

int sum_of_digit(long long N){
    int sum {0}; 
    while(N){
       sum += N%10 ;
       N /= 10 ;
    }
    return sum ;
}

int solve(long long A, long long N){
    int ans{0} ;
    if(N>1){
        if(N % 2 == 0 ) ans = solve(sum_of_digit(A*A),N/2) ;
        else {
            ans = solve(sum_of_digit(A*A),N/2)*sum_of_digit(A) ;
            ans = sum_of_digit(ans) ;
        }
    }else {
        ans = sum_of_digit(A) ;
    }
    return sum_of_digit(ans) ; 
    
}

int main(){
    std::cout<< solve(941,1931) ;
    return 0 ;
}