#include<bits/stdc++.h>
using namespace std;



vector<int> solve(int n){
    
    std::vector<int> sieve(n+1 , 0);
    for(long long p {2} ; p<=n ; p++ ){
        if(!sieve[p]){
            sieve[p] =  p ;
            for(long long i{p*p} ; i<=n ; i+=p ){
                if(sieve[i] == 0)
                    sieve[i] = p ;
            }
        }
    }
    
    std::unordered_map<int, int> factors;
    // std::vector<int> ans {1 ,0} ;
    int ans {1} ;
    while(n != 1 ){
        int divisor {sieve[n]} ;
        while(n%divisor == 0){
            factors[divisor]++ ;
            n /= divisor ;
        }
        ans *= divisor ;
    }
    
    int max {std::max_element(factors.begin() , factors.end() , [](auto a , auto b){return a.second < b.second ; })->second };
    int ans1 {0} ;
    while(max != 1){
        if(max%2 == 0) {
            ans1++ ;
            max >>= 1 ;  
        }
        else {
            max++ ; 
            ans1++ ;
        } 
    }
    
    // return ans ;
    std::cout << ans << " "  << ans1 << std::endl ;
    return std::vector<int> {ans ,ans1} ;
    
    
}

int main(){
    solve(102) ;
    return 0 ;
}


