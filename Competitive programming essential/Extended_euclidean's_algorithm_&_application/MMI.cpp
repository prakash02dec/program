#include <iostream>
#include <vector>
#include <cmath> 
#include <climits>


// bottom up approach 
// extended euclid algorithm
std::vector<int> extendedGCD(int a , int b ){
    if(b == 0){
        return std::vector<int> {1 ,0 , a} ;
    }
    std::vector<int> result {extendedGCD(b,a%b)} ;
    int x {result[0]} ;
    int y {result[1]} ;
    int gcd {result[2] } ;

    int X {y} ;
    int Y {x - (a/b)*y} ;

    return std::vector<int> {X,Y , gcd} ;
}   

// code for MMI
int modInverse (int a , int m){
    std::vector<int> result {extendedGCD(a,m)} ;
    if (result[2] != 1){
        std::cout << "Multiplicative modulo inverse doesn't exist" << std::endl ;
        return INT_MAX;
    }
    else {
        std::cout << "Multiplicative module inverse of " << "a" << " under mod " << "m"
        << result[0] ;
        return (result[0]%m + m)%m ;
    }
}

int main() {
    int a {} , b { } ; 
    std::cin>> a >> b ;
    // ax + by = gcd(a,b)
    std::vector<int> result {extendedGCD(a,b)} ;
    std::cout << "x : " << result[0] << " y : " << result[1] << " gcd : " << result[2] <<  std::endl ;

    return 0  ;   

}