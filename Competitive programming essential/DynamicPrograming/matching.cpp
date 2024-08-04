#include<bits/stdc++.h>
using namespace std ;
const int mod {static_cast<int> (1e9+7)} ;
#define int long long

// bool canBePlace(const auto &a ,const auto &state ,  int i , int j){
//     while(i>= 0 ){
//         if(state[i][j] == 1) return false ;
//         i-- ;
//     }
//     return true ;
// }

// int no_of_ways(const auto &a ,  auto &state , int i= 0 ){
//     int count {} ;
//     if(i == a.size()){
//         return 1 ;
//     }

//     for(int k {} ; k < a.size() ; k++ ){
//         if(a[i][k] == 1 && canBePlace(a ,state ,  i , k)){
//             state[i][k] = 1 ;
//             count += no_of_ways(a ,state , i+1 ) ;
//             count %= mod ;
//             state[i][k] = 0 ;
//         }
//     }

//     return count ;
// }

vector<vector<int>> memo(21 , vector<int> (1<<21 , -1)) ;

int dp(const auto &a , int m ,int n ,  int set ){
    if(m == n) return 1 ;
    if(memo[m][set] != -1) return memo[m][set] ;

    int ans = 0 ;
    for(int x = 0 ; x< n ; x++){
        if( !(set>>x & 1)  and a[m][x] == 1){
            ans += dp(a , m+1 ,n , (set | 1 << x ) ) ;
            ans %= mod ;
        }
    }
    return memo[m][set] = ans ;
}


int32_t main() {
    int n {} ;
    cin>> n ;
    vector<vector<int>> a (n , vector<int> (n , 0 )) , state ;
    // state = a ;
    for(int i {} ; i < n ; i++){
        for( int j {} ; j < n ; j++){
            cin>> a[i][j] ;
        }
    }
    int set {} ;
    cout << dp(a ,0 ,n , set) ;

    // cout << no_of_ways(a , state) ;


    return 0 ;
}