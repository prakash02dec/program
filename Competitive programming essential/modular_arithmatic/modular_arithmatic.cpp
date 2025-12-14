#include <bits/stdc++.h>

const int mod {1000'000'007} , N{2000001};

#define int   long long int

int  fac[N] {} ;

int addm(int x , int y) {
    return (x+y) % mod ;
}

int subm(int x , int y){
    return ((x - y ) + mod ) % mod ;
}

int mulm (int x , int y){
    return (x*y) %mod ;
}


int pow(int x , int m ){
    int result {1} ;
    while(m){
        if(m&1) result = mulm(x, result) ;
        x = mulm(x ,x) ;
        m /= 2 ;
    }
    return result ;
}


int inv(int y){
    return  pow(y , mod-2) ;
}

// using fermat theorum
int divm(int x , int y){
    return mulm (x , inv(y)) ;
}

void caculate_factorial() {
    fac[0] = 1 ;
    for(int i=1 ; i< N ; i++){
        fac[i] = mulm(fac[i-1] ,i) ;
    }

}

int nCr(int n , int r){
    return mulm (mulm(fac[n] , inv(fac[r])) , inv(fac[n-r])) ;
}


int32_t main(){
    caculate_factorial() ;
    // for(int i {} ; i < 100 ; i++) std::cout << fac[i] << " " ;
    std::cout << addm(addm(nCr(391 , 1) , mulm(4 , nCr(391 ,2)) ) , mulm(3 ,nCr(391 ,3))) <<std::endl ;

    // std::cout <<  nCr(1276 , 189);
    return 0 ;
}