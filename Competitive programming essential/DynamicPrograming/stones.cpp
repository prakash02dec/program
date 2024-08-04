#include<bits/stdc++.h>
using namespace std ;

int main() {
    int n {} , k {} ;
    cin >> n >> k ;
    vector<int> a(n , 0) ;
    for(int i {} ; i< n ; i++){
        cin >> a[i] ; 
    }
    vector<int> dp(k+1 , 0) ;

    for(int i {1} ; i<=k ; i++ ){
        for(int j {} ; j < n ; j++){
            if(i-a[j] >=0 && dp[i-a[j]] == 0){
                dp[i] = 1 ; 
                break ; 
            }
        }
    }
    
    cout << (dp[k] ? "First" :  "Second")  ;

    return 0 ;
}