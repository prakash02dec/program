#include <iostream>
#include <vector>
#include <cmath> 


// bottom up approach 
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

int main() {
    int a {} , b { } ; 
    std::cin>> a >> b ;
    // ax + by = gcd(a,b)
    std::vector<int> result {extendedGCD(a,b)} ;
    std::cout << "x : " << result[0] << " y : " << result[1] << " gcd : " << result[2] <<  std::endl ;

    return 0  ;   

}