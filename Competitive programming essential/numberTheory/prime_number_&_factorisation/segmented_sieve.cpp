#include <iostream>
#include <vector>

const int N {1'00'000} ;
std::vector<int> primes ;

void primeSieve(){
    std::vector<bool> sieve (N+1,true) ;
    sieve[0] = sieve[1] = false ;
    for(long long p{2} ; p<=N ; p++){
        if(sieve[p]){
            primes.push_back(p) ;
            for(long long i {p*p} ; i<=N ; i+=p ){
                sieve[i] = false ;
            }
        }

    }
}


int main() {
    // precompute
    primeSieve() ;
    int t {} ;
    std::cin >> t ;

    while(t--){
        int n {} , m  {};
        std::cin>>m >> n ;
        std::vector<int> segment (n-m+1 , 0) ;
        for(auto p : primes){
            // stop when p^2 > n
            if(p*p > n){
                break ;
            }
            // other wise we need to find the nearest starting point
            int start = (m/p)*p ;

            //special case 
            if(p>= m and p<= n){
                start = 2*p ;
            }

            // start marking the number as not prime from start 
            for(int j {start} ; j<= n ; j += p){
                if(j<m){
                    continue ;
                }
                segment[j - m] = 1 ;
            }
            

        }
        // primes stores as 0 in the segment
        for(int i {m} ; i<=n ; i++){
            if(segment[i-m] == 0 && i > 1){
                std::cout << i << std::endl ;
            }
        }
        std::cout << std::endl ; 

    }

    return 0 ;
}