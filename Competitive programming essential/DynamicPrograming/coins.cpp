#include<bits/stdc++.h>
using namespace std ;

#define int long long int
#define double long double

const int N {3000} ;
vector<vector<double >> memo(N ,vector<double > (N , -1)) ;
 

double dp(int i , int h , int t , const auto &p){
    if(i == p.size()) return 1.00  ;

    double &ans = memo[i][h] ;
    if(ans != -1 ) return ans ;

    ans = 0 ;
    if(h){
        ans += dp(i+1 , h-1 , t , p)*p[i] ;
    }
    if(t){
        ans += dp(i+1 , h , t-1 , p)*(1.00-p[i]); 
    }
    return ans ;
}

int32_t main(){
    int n ;
    cin >> n ;
    vector<double> p(n , 0)  ;
    for(int  i = 0 ; i< n ; i++) {
        cin>> p[i] ;
    }
    double ans {0.0} ;
    for(int i = (n/2 + 1) ; i<= n ; i++ ){
        ans += dp(0 , i , n-i , p) ;
    }
    cout << setprecision(10) ;
    cout << ans ;
    return 0 ;
}			