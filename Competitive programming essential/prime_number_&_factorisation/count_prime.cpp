#include<bits/stdc++.h>
using namespace std;

void primeSieve(std::vector<int> &ans ,int n ){
    std::vector<bool> isprime (n,true) ;
    isprime[0] = isprime[1] = false ;
    for(long long p {2} ; p<n ; p++){
        if(isprime[p]){
            ans[p] = ans[p-1]+1 ;
            for(long long i {p*p} ; i <n ; i += p){
                isprime[i] = false ; 
            }
        }else{
            ans[p] = ans[p-1] ;
        }
    }

}


int countPrimes(int n){
    std::vector<int> ans (n,0) ;
    primeSieve(ans ,n) ;
    return ans[n-1] ;
}