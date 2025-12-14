#include<iostream>
#include <vector>
const int N {11} ; 

void primeSieve(std::vector<int> &ans){
    std::vector<bool> isprime (N,true) ;
    isprime[0] = isprime[1] = false ;
    for(long long p {2} ; p<=N ; p++){
        if(isprime[p]){
            ans[p] = ans[p-1]+1 ;
            for(long long i {p*p} ; i <=N ; i += p){
                isprime[i] = false ; 
            }
        }else{
            ans[p] = ans[p-1] ;
        }
    }

}

int main() {
    std::vector<int> ans (N,0) ;
    primeSieve(ans) ;
        std::cout << "[ " ; 
    for(const auto prime : ans)
        std::cout << prime << " ";
    std::cout << "]" ; 
    return 0 ;
}