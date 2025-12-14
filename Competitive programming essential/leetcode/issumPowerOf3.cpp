#include<bits/stdc++.h>
using namespace std ;


bool checkPowersOfThree(int n) {
    int maxPower {static_cast<int> ( floor(log(n) / log(3)))} ;

    int sum {} ;
    for(int i {maxPower} ; i >= 0 ; i-- ){
        int power = (int)pow(3 , i) ;
        if(sum + power <= n ){
            sum += power ;
        }

        if(sum  == n)  return true ;
    
    }
    return false ;
}


int main() {
    cout << checkPowersOfThree(12) ;
    return 0 ;
}