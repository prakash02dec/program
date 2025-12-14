#include<bits/stdc++.h>
using namespace std ;

#define int long long


int knapsack(int i ,int currWt , int W , const vector<int> &wt , const vector<int> &v, auto &dp){
    if(i == wt.size() ){
        return 0 ;
    }
    if(dp[i][currWt] != -1) return dp[i][currWt] ;

    int ans {INT_MIN} ; 
    
    // included 
    if(currWt+ wt[i] <= W )
    ans = v[i] + knapsack(i+1 , currWt+ wt[i] , W ,  wt , v , dp) ;
    // not include 
    ans = max(ans ,  knapsack(i+1 ,currWt , W ,  wt , v , dp) ) ;
    // return answer 
    return dp[i][currWt] = ans ;
}

int32_t main(){
    int n {} , w {} ;
    cin >> n >> w ;
    vector<int> wt(n , 0) , v(n , 0) ;
    vector<vector<int>> dp(n , vector<int> (static_cast<int>(1e5+1) , -1)) ;
    
    for(int i {} ; i< n ; i++){
        cin >> wt[i] >> v[i] ;
    }

    cout << knapsack(0 , 0 , w,  wt , v , dp) ;
    return 0 ;
}