#include <bits/stdc++.h>

const int N {1e5} ;


void calculate_totient(){
    std::vector<bool > prime (N , true) ;
    std::vector<int > tot(N) ;

    prime[0] = prime[1] = false ;
    for(int i = 2 ; i<N ; i++){
        if(prime[i]){
            for(int j {i*i} ; j<N ; j+=i ){
                prime[i] =  false ;
            }
        }
    }



    std::iota(tot.begin() , tot.end() , 0) ;

    for(int i {1} ; i<N ; i++) {
        if(prime[i]){
            for(int j {i} ; j < N ; j += i  ){
                tot[j]/= i ;
                tot[j] *= (i-1) ;
            }
        }
        
    } 

}


int main(){


    return 0 ;
}