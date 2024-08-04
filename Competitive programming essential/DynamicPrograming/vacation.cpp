#include<bits/stdc++.h>
using namespace std ;

int main() {
    int n {} ;
    cin >> n ;
    vector<vector<int>> V(n ,vector<int> (3,0)) , dp(n ,  vector<int> (3, 0)) ;
    for(int i {} ; i< n ; i++){
        for(int j {} ; j < 3 ; j++){
            cin>> V[i][j] ;
        }
    }

    dp[0][0] = V[0][0] ;
    dp[0][1] = V[0][1] ;
    dp[0][2] = V[0][2] ;



    for(int i {1} ; i< n ; i++){
        for(int j {} ; j < 3 ; j++){
            for(int k{} ; k<3 ; k++ ){
                if(j != k){
                    dp[i][j] = max(dp[i][j] , dp[i-1][k] + V[i][j] ) ;
                }
            }
        }
    }

    cout << *max_element(dp[n-1].begin() , dp[n-1].end()) ;

    return 0 ;
}