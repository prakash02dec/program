#include <iostream> 
#include <vector >

const int N {1'00} ;

void primeSieve(std::vector<int> &sieve){
    std::vector<bool> isprime (N,true) ;
    isprime[0] = isprime[1] = false ; 
    for(long long p{2} ; p<=N ; p++ ){
        if(isprime[p]){
            sieve.push_back(p) ;
            for(long long j {p*p} ; j<=N ; j += p){
                isprime[j] = false ;
            }
        }
    }
    // for(int i {2} ; i<=N ; i++ ){
    //     if(isprime[i]){
    //         sieve.push_back(i) ;
    //     }
    // }

}

int main() {
    std::vector<int> sieve {} ;
    primeSieve(sieve) ;
    std::cout << "[ " ; 
    for(const auto prime : sieve)
        std::cout << prime << " ";
    std::cout << "]" ; 
    return 0 ; 
}