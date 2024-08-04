#include <bits/stdc++.h>

int countBST(int n  ){
    if(n==0 || n==1){
        return 1 ;
    }
    int ans {} ;
       
        for(int i=1 ; i<= n ; i++){
            int x {} , y{} ;
            x =  countBST(i-1 ) ;
            y = countBST(n-i ) ;
            ans += x*y ;
        }
    
    return ans ;
}

// top down
int dp_countBST(int n , int dp[] ){
    if(n==0 || n==1){
        return 1 ;
    }
    int ans {} ;
    if(dp[n] == 0){
       
        for(int i=1 ; i<= n ; i++){
            int x {} , y{} ;
            x =  dp_countBST(i-1 , dp) ;
            y = dp_countBST(n-i , dp) ;
            ans += x*y ;
        }
        dp[n] = ans ;
    }
    
    return dp[n] ;
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

std::vector<long long> dp(500+1 , 0) ;
int solve(int n){

    dp[0] = dp[1] = 1 ;

    for(int i {2} ; i <= n ; i++){
        for(int j{1} ; j<=i ; j++){
            dp[i] += dp[j-1]*dp[i-j] ;
            dp[i] %= 1000000 ;

        }
    }
    // std::cerr<< " " << dp[5] ;
    return dp[n] ;
}


int main(){
    int n {5} ;
    int dp[100] {} ;
    std::cout << solve(3) << std::endl ;

    return 0;
    
}