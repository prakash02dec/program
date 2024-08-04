/*
Given 3N + 1 Numbers , where every number is coming thrice
except one numbers find that unique number.
*/

#include <bits/stdc++.h> 

void updateSum(std::vector<int> &sumArr , int x){
    for(int i {} ; i <32 ; i++){
        if(x&1) sumArr[i]++ ;
        x >>= 1 ; 
    }
}

int numfromBits(std::vector<int> sumArr){
    int num {} ;
    for(int i {} ; i<32 ; i++){
        num += (sumArr[i])*(1<<i) ; // 101 = 1*2^0 + 0*2^1 + 1*2^2 
    }
    return num ;
}

int uniqueNo3(std::vector<int> arr){
    std::vector<int> sumArr(32,0) ;
    for(auto x : arr){
        updateSum(sumArr ,x) ;
    }

    for(int i {} ; i<32 ; i++){
        sumArr[i] = sumArr[i] %3 ;
    }
    return numfromBits(sumArr) ;
}

int main(){
    std::vector<int> arr {1,3,5,4,3,1,5,5,3,1} ;
    std::cout << uniqueNo3(arr) << " " ;
    return 0 ;
}
