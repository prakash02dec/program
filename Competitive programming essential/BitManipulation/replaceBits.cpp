/*
you are given two 32-bit numbers, N and M, and two bit position i and j.
Write a method to set all bits between i and j in N equal to M.
M (beomes a substring o N locationed at and starting a j)
Example ;
N =  100000000000
M =  10101
i = 2 , j = 6 
output : 1001010100
*/
#include <iostream>

void clearBitsInRange(int &n , int i , int j){
    int a {-1<<(j+1)} ; 
    int b { (1<<i) -1} ;
    int mask {a|b} ;

    n = n & mask ;
}

void replaceBits(int &n , int  i , int j , int m ){
    clearBitsInRange(n , i , j) ;
    int mask {m<<i} ;
    n = n | mask ; 

}


int main(){
    int n {15} , i {1} , j {3} , m {2} ; 
    replaceBits(n , i , j ,m) ;
    std::cout << n ;
    return 0 ;
}