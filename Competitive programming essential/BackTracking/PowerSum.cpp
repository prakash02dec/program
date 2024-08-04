#include<bits/stdc++.h>
using namespace std;

int no_of_ways(int x , int n , int sum , int num ){
    if(x == sum ){
        return 1 ;
    }
    int total {} ;
    for(int i {num} ; i<= static_cast<int>(sqrt(x)) ; i++ ){
        total += no_of_ways(x , n , sum+ pow(i , n) , i+1) ;
    }
    
    return total ;
}

int solve(int x,int n){
    return no_of_ways(x , n , 0 , 1 ) ;
}

int main() {

    std::cout << solve (100 ,3) ;
    return 0 ;
}