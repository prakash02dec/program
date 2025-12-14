#include<bits/stdc++.h>
using namespace std ;
#define int long long 

const int N = 3001 ;
int memo[N][N][2] ;

int dp(const vector<int> &a , int i , int j , int turn = 0 ){
    // taro turn == 0
    if(i > j ){
        return 0 ;
    }

    int &ans = memo[i][j][turn]  ;
    if(ans != (int) 1e18 ) return ans ;
    if(!turn) {
       
        return ans =  max(a[i] + dp(a  , i+1 , j  , 1) , a[j] + dp(a , i , j-1  , 1 ) ) ;
    }
    // jiro turn == 1
    else{
        return ans = min( dp(a , i+1 , j  , 0 ) ,  dp(a , i , j-1  , 0)  ) ;
    }
}


int32_t main() {
    int n ;
    cin >> n ;
    vector<int> a(n , 0) ;
    int sum {} ;
    for(int i {} ; i < n ; i++) {
        cin >> a[i] ;
        sum += a[i] ;
    } 
    
    for(int i {} ; i < N ; i++){
        for(int j {} ; j < N ; j++){
            memo[i][j][0] = memo[i][j][1] = (int) 1e18 ;
        }
    }
    int X = dp(a , 0 , n-1  , 0) ;
    int Y = sum - X ;
    cout << X - Y ;
    return 0 ;
}




















