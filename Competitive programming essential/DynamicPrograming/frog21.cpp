#include<bits/stdc++.h>
using namespace std ;

int main() {
    int n {} , k {} ;
    cin>> n >> k;
    int h[n] ;
    for(int i {} ; i< n ; i++){
        cin>> h[i] ;
    }
    int dp[n] ;
    dp[0] = 0 ;
    dp[1] = dp[0] +abs(h[1] - h[0]) ;

    for(int i {2} ; i< n ; i++){
        dp[i] = INT_MAX ;
        for(int jump  = 1 ; jump <= k && i-jump >= 0 ; jump++){
            dp[i] = min(dp[i] , dp[i - jump ] + abs(h[i] - h[i - jump])) ; 
        }
    }
    
    cout << dp [n-1] ;

    return 0 ;
}