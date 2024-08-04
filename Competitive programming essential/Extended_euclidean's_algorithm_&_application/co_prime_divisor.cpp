#include<bits/stdc++.h>
using namespace std;

int gcd (int a , int b ){
    if(b == 0 )
    return a ;
    return gcd(b , a%b) ;
}

int solve(int a,int b){
    if(gcd(b , a) == 1) return a; 
    
    for( int i { 2 } ; i<=sqrt(a) ; i++ ){
        if(a%i == 0){
            if(gcd(b , a/i) == 1) return a/i ;
        }
    }
    
}