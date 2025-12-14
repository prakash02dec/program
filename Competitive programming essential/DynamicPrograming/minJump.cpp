#include<bits/stdc++.h>
using namespace std ;

int min_jumps(vector<int> arr , int n , vector<int> dp , int i = 0){
    // base case
    if(i == n-1) return 0 ;
    if(i >=n ) return INT_MAX ;
    // working of current call
    if(dp[i] != 0){
        return dp[i] ;
    }
    int ans {INT_MAX} ;
    for(int j {1} ; j <= arr[i] ; j++ ){
        int subproblem =  min_jumps(arr , n , dp , i+j) ;
        if(subproblem != INT_MAX)
        ans = min(ans , subproblem+ 1 ) ;
    }
    return dp[i] = ans ;
}


int main(){
    vector<int> arr {3 , 4 , 2 , 1 ,1 , 3 ,7 ,1 ,1 , 3} ;
    int n = arr.size() ;
    vector<int> dp(n , 0) ;
    cout << min_jumps(arr , n , dp , 0) ; 
    return 0 ;
}