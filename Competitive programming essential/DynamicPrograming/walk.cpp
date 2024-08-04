#include <bits/stdc++.h>

const int mod {1000'000'007};
// const int sz {51};

#define int long long 
using namespace std; 

struct Mat {
    int sz ; 
    vector<vector<int>> m ; 
    Mat(int n) {
        sz = n ;
        m.resize(n , vector<int> (n , 0) ) ;
        // memset(m, 0 , sizeof(m)) ;
    }
    void identity(){
        for(int i {0} ; i < sz ; i++){
            m[i][i] = 1 ;
        }
    }
    Mat operator*(Mat a){
        Mat res (sz); 
        for(int i {} ; i < sz ; i++){
            for(int j {} ; j < sz ; j++){
                for(int k {} ; k < sz ; k++ ){
                    res.m[i][j] += m[i][k]*a.m[k][j] ; 
                    res.m[i][j] %= mod ; 
                }
            }
        }
        return res ;
    }
};


int32_t main() {
    
    int n {} , k {  };
    cin >> n >> k ;
    
    Mat a(n) , res(n) ;
    
    for(int i {} ; i < n ; i++){
        for (int j { } ; j < n ; j++){
            cin >> a.m[i][j] ;
        }
    } 

    res.identity() ;

    while(k){
        if(k & 1ll)
            res = res * a;

        a = a* a ;
        k /= 2 ; 
    }

    int ans = 0 ;

    for(int i {} ; i < n ; i++){
        for (int j { } ; j < n ; j++){
            ans += res.m[i][j] ;
            ans %= mod ;
        }
    } 
    cout << ans ;
    return 0 ;
}