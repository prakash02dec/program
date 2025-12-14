#include <bits/stdc++.h>

void permutation(std::string input , int l ){
    if(l== input.length()-1){ 
        std::cout << input << std::endl ;
        return ; 
    }
    for(int i {l} ; i< input.length() ; i++){
        std::swap(input[l] , input[i]) ;
        permutation(input , l+1) ;
        std::swap(input[l] , input[i]); 
    }
}


int main() {
    std::string input {"abc"} ;
    permutation(input , 0  ) ;
    return 0 ;
}