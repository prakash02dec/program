#include <bits/stdc++.h>
using namespace std ;

int32_t main() {
    int n {} , k {} ; 
    cin >> n >> k ;

    vector<int> a(n + 1, 0 ) ;

    for(int i {1} ; i<= n ; i++){
        cin>> a[i]  ;
    }

    vector<vector<int>> dp(n+1 , vector<int> (k+1 , 0) ) ;

    dp[0][0] = 1 ;

    for(int i {1} ; i<= n ; i++){
        for(int j {} ; j <= k ; j++){
            for(int kk{} ; kk <= min(j , a[i]) ; kk++){
                dp[i][j] += dp[i-1][j-kk] ;
            }
            
        }
    }

    for(int i {} ; i <= n ; i++){
        for(int j {}; j <= k ; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl ;
    } 


    return 0 ;
}