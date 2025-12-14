#include <bits/stdc++.h>
using namespace std ;
#define int long long 

int prefix[401] ;


int sum (int l , int r){
    return prefix[r] - (l == 0 ? 0 : prefix[l-1] );
}

int dp( const vector<int> &a ,auto &memo , int l , int r){
    if(l == r) return 0 ;
    int &ans {memo[l][r]} ;
    if(ans != -1 ) return ans ;
    ans = (int) 1e15 ;
    for(int i {l} ; i < r ; i++ ) {
        ans = min(ans , dp(a ,memo , l , i) + dp(a ,memo , i+1 , r)) ;
    }
    ans += sum (l , r) ;
    return ans ;
}

int32_t main() {
    int n {} ;
    cin >> n ;
    vector<int> a (n , 0) ;

    for(int i {} ; i < n ;  i++){
        cin >> a[i] ;
        prefix[i] = a[i] ;
        if(i) prefix[i] += prefix[i-1] ;
    }
    vector<vector<int>> memo(n , vector <int> (n , -1)) ;
    cout << dp (a ,memo , 0 , n-1) ;
    return 0 ;
}