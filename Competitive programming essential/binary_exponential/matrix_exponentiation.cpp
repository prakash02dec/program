#include<bits/stdc++.h>
const int mod {1000'000'007};
const int sz {3};

struct Mat {
    long long m[sz][sz] ; 
    Mat() {
        memset(m, 0 , sizeof(m)) ;
    }
    void identity(){
        for(int i {0} ; i < sz ; i++){
            m[i][i] = 1 ;
        }
    }
    Mat operator*(Mat a){
        Mat res {}; 
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

int fib (int n){
    Mat res {} ; 
    res.identity() ; 
    Mat T {} ;
    // std::cout << res.m[0][0] << std::endl ;
    T.m[0][0] = T.m[0][1] = T.m[1][0] = 1 ;

    if( n <= 2) return 1 ;
    n -= 2 ; 
    while(n) {
        if(n&1) res = res*T  ;
        T=T*T ; 
        n = n>>1 ;
    }

    return (res.m[0][0] + res.m[0][1])% mod ; 
     
}
// O( size^3 *log(n) ) 

long long  fibosum(int n){
    Mat res {} ;
    res.identity() ;
    Mat T {} ;
    T.m[0][0] = T.m[0][1] = T.m[0][2] = T.m[1][1] = T.m[1][2] = T.m[2][1] = 1 ; 
    if(n<2) return n  ;
    // n>= 2
    n -= 1 ;

    while(n) {
        if(n&1) res = res*T  ;
        T=T*T ; 
        n = n>>1 ;
    }

    return (res.m[0][0] + res.m[0][1])% mod ; 


}

int fibSum(int n,int m){
    return (fibosum(m) - fibosum(n-1)+ mod)%mod ;
}
int main() {
    std::cout << fib(154) << std::endl  ;
    // std::cout << fibosum(3) << std::endl ; 
    // int m { } , n {} ; 
    // std::cin >> n >> m ;
    // std::cout << fibSum(154, 1390)  << std::endl ; 
    return 0 ; 
}