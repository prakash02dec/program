#include<iostream>

long long pow(long long a , long long b , long long c){
    long long result{0} ;
    while(b){
        if(b&1) result += a , result %=c;
        a = 2 * a ; 
        a %= c ;
        b = b>>1 ;
    }
    return result  ;
}
int main(){
    return 0 ; 
}