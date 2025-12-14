#include <bits/stdc++.h>
using namespace std;

/*
APPROCHES
1 - Recursive
2 - Top Down 
3 - Bottom Up
4 - Bottom Up Optimised Recurrence 
*/

// O(k^n)

// recursive approach
int countWays(int n , int k ){
    if(n == 0){
        return 1 ;
    }
    if(n<0) {
        return 0 ;
    }
    int ans {} ;
    for(int jump = 1 ; jump <= k ; jump++){
        ans += countWays(n-jump , k) ;
    }
    return ans ;
}

// top down approach
int countWaysTD(int n , int k , int *dp ){
    if(n == 0){
        return 1 ;
    }
    if(n<0) {
        return 0 ;
    }
    // check if state is already computed
    if(dp[n] != 0){
        return dp[n] ;
    }
    int ans {} ;
    for(int jump = 1 ; jump <= k ; jump++){
        ans += countWaysTD(n-jump , k , dp) ;
    }
    return dp[n] = ans ;
}

// bottom up Approach (O(n*k))
int countWaysBU(int n , int k ){
    // iterative approach
    vector<int> dp(n+1 , 0) ;
    dp[0] = 1 ;
    for(int i {1} ; i <= n ; i++){
        for(int jump{1} ; jump<= k ; jump++){
            if(i-jump>=0)
                dp[i] += dp[i-jump] ;
        }
    }
    return dp[n] ;
}

// optimise bottom up Approach (O(n*k))
int countWaysOptBU(int n , int k ){
    // iterative approach
    vector<int> dp(n+1 , 0) ;
    dp[0] = dp[1] = 1 ;
    for(int i {2} ; i <= k ; i++){
        dp[i] = 2*dp[i-1] ;
    }
    for(int i {k+1} ; i<=n ; i++){
        dp[i] = 2*dp[i-1] - dp[i-k-1] ;
    }
    return dp[n] ;
}

int main(){
    int n , k ;
    cin >> n >> k ;
    int dp[n+1] {} ;
    cout << countWays(n , k ) << endl ;
    cout << countWaysTD(n , k , dp) << endl ;
    cout << countWaysBU(n , k ) << endl ;
    cout << countWaysOptBU(n , k ) << endl ;
    return 0 ;
}