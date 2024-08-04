#include<iostream>
#include <cmath >
#include <vector>

// O(n)
void factorise (int n){
    for(int i {2} ; i <= n ; i++) {
        if(n%i == 0){
            int count {} ;
            while(n%i == 0){
                n = n/i ;
                count++ ; 
            }
            std::cout << i << "^" << count <<std::endl ; 
        }
    }
}

// O(sqrt(N))
void factorise1 (int n){
    for(int i {2} ; i <= sqrt(n) ; i++) {
        if(n%i == 0){
            int count {} ;
            while(n%i == 0){
                n = n/i ;
                count++ ; 
            }
            std::cout << i << "^" << count <<std::endl ; 
        }
    }
    if(n != 1 ){
        std::cout << n << "^" << "1" << std::endl ;
    }

}

// O(log(N))
void factorise2 (int n){

    std::vector<int> sieve (n+1,0) ;
    // sieve[0] = sieve[1] = 0 ; 
    for(int p{2} ; p<=n; p++ ){
        if(!sieve[p]){
            sieve[p] = p ;
            for(int j {p*p} ; j<=n ; j += p){
                if(sieve[j] == 0 )
                    sieve[j] = p ;
            }
        }
    }
    // for(const auto prime : sieve)
    //     std::cout << prime << " ";
    // std::cout << "]" ; 

    while(n != 1 ){
        int count {} ;
        int divisor {sieve[n]} ;
        while(sieve[n] == divisor){
            n = n/sieve[n] ;
            count++ ;
        } 
        std::cout << divisor << "^" << count <<std::endl ; 
    }
    
}


int main(){
    factorise2(286);
    return 0 ;
}