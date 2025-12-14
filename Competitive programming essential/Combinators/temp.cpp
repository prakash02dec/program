#include<bits/stdc++.h>
using namespace std;

const int mod {998244353} ;

std::vector<vector<unsigned >> C_table(2000,vector<unsigned> (2000 , 0));

long long nCr(int n , int r){
    if(r == 0 || r == n)  return 1; 
    
    if(C_table[n][r] == 0){
        long long x {nCr(n-1 , r-1)} ; 
        long long y {nCr(n-1 , r)} ;
        C_table[n][r] = (x + y)%mod;
    }
    
    return C_table[n][r]  ;
}

int countBST_bottomup(int N ){
    std::vector<long long> dp(N+1 , 0) ;
    dp[0] = dp[1] = 1 ;

    for(int n = 2 ; n<=N ; n++){
        for(int i = 1  ; i<=n ; i++){
            dp[n] += (dp[i-1]*dp[n-i]) ;
            dp[n] %= 1000000 ;
            
        }
    }
    return dp[N] ;

}

int solve(int n,int m){
    return nCr(m , n-1);
}

int main ( ){
    std::cout << solve (42,1337) ;
    return 0 ;
}