#include<bits/stdc++.h>
using namespace std ;

int ans(vector<int> &h , vector<int> &dp , int i , int k){
    if(i  == 0 ) return dp[i] = 0 ;
    if(i < 0 ) return INT_MAX ;


    if(dp[i] != -1) return dp[i] ;

    int temp {INT_MAX} ;
    for(int jump {1} ;  jump <= k ; jump++  ){
        if(i-jump>=0 )
        temp = min (temp ,ans(h , dp , i-jump , k) + abs(h[i] - h[i- jump ])) ;       
    }

    return dp[i] = temp ;
}


int main() {
    int n {}  , k {} ;
    cin >> n >> k ;
    vector<int > dp( n , -1 ) ,  h (n , 0 )  ;
    for(int i {} ; i< n ; i++ ){
        cin >> h[i] ;
    }
    cout << ans(h ,dp , n-1 , k) ;
    return 0 ;
}