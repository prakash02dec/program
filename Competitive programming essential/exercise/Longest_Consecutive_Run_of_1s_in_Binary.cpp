#include<bits/stdc++.h>

int solve(int n) {
    int max_count {INT32_MIN} , count {} ;
    while(n>0){
        if(n&1){
            count++ ;
        }else {
            max_count = std::max(max_count , count) ; 
            count = 0 ;
        }
        n = n>>1 ;
    }
    max_count = std::max(max_count , count) ; 
    return max_count;
}

int main() {
    std::cout << solve(424) ;
    return 0 ;
}