#include <bits/stdc++.h>

int fast_power(int a , int n){
    if(n==0) return 1 ;
    int subproblem {fast_power(a , n/2)} ;
    int ans {subproblem*subproblem} ;
    if(n&1) ans *=  a;
    return ans ;    
    
}   

int main() {
    std::cout << fast_power(2,5) ;
    return 0 ;

}