#include <bits/stdc++.h>

bool isSorted(int arr[] , int n){
    if(n==1 or n==0){
        return true ;
    }
    if(arr[0] <= arr[1] and isSorted(arr +1 , n-1) ) return true ;

    return false ;

}


int main() {
    return 0 ;
}