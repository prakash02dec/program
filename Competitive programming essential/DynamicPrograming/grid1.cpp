#include<bits/stdc++.h>
using namespace std ;

const int mod {static_cast<int> (1e9+7)} ;

int main() {
    int n , m ;
    cin >> n >> m ; 
    string s[n] ;
    for(int i = 0 ; i < n ; i++){
        cin>> s[i] ;
    }
    int dp[n][m] ;
    
    for(int i {} ; i < n ; i++ ){
        for( int j {} ; j < m ; j++){
            if( i == 0 && j ==0 ) dp[i][j] = 1 ;
            else if ( i== 0 ) dp[i][j] = dp[i][j-1] ;
            else if ( j== 0 ) dp[i][j] = dp[i-1][j] ;
            else {
                dp[i][j] = dp[i][j-1] + dp[i-1][j] ;
                dp[i][j] %= mod ;
            }
            if(s[i][j] == '#') dp[i][j]  = 0 ;
        }
    }

    cout << dp[n-1][m-1] ;

    return 0 ;
}