#include<bits/stdc++.h>
using namespace std ;

int ans (const vector<int> &h , vector<int> &dp , int i  ){
    if(i == 0 ) return dp[i] = 0 ;

    if(dp[i] != -1 ) return dp[i] ;

    if(i-2 < 0 ) return dp[i] = ans(h , dp , i-1) + abs(h[i-1]  - h[i]) ;

    return dp[i] = min(ans(h , dp , i-1) + abs(h[i-1] -h[i] ) , ans(h , dp , i-2) + abs(h[i-2] - h[i])) ;

}

int main() {
    int n ;
    cin>> n ;
    vector<int>  h(n , 0) , dp(n , -1) ;
    for(int i {} ; i< n ; i++){
        cin>> h[i] ;
    }


    cout << ans(h , dp , n-1) ;
    

    return 0 ;
}