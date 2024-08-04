/*
Given 2N + 2 Numbers, where every number is coming twice 
except two numbers find those two unique numbers.
*/

#include <bits/stdc++.h>

void uniqueNo2 (std::vector<int> arr){
    int n {static_cast<int>(arr.size())} ;
    // xor 
    int result {} ;
    for(auto no : arr){
        result = result ^no ;
    }
    int pos {} ;
    int temp {result} ;
    while ((temp&1) == 0){
        pos++ ;
        temp >>= 1 ;
    }
     
    int setA {} , setB {} , mask {1<<pos} ;

    for(auto no : arr){
        if(mask&no){
            setA = setA ^ no ;
        }else{
            setB = setB ^ no ;
        }
    }

    std::cout << setA << " " << setB ;
}

int main(){
    std::vector<int> arr {1,3,5,4,3,1,5,7} ;
    uniqueNo2(arr) ;
}