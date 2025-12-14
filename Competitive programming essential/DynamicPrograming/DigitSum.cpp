#include <bits/stdc++.h>
using namespace std ;

const int m {(int)1e9 + 7} ;

int d ;
string k ;

int memo[100000][2][101] ;

int dp(int i , bool last , int mod){

    if( i == k.size() ){
        return mod == 0  ;
    }

    int &ans = memo[i][last][mod] ;
    if(ans != -1) return ans ;

    ans = 0 ;

    int till = last ? (k[i] - '0') : 9 ;

    for(int digits {} ; digits <= till ; digits++ ){
       ans += dp(i + 1 , last && (digits == till) , (mod + digits)%d ) ;
        ans %= m ;
    }
    return ans ;
}

int32_t main(){
    cin >> k >> d ;
    memset(memo , -1 , sizeof(memo)) ;
    cout << (dp(0 , 1  , 0) - 1 + m)%m ;
    return 0 ;
}