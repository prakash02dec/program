#include <bits/stdc++.h>

bool divideAmongK(int arr[] , int n , int k , int min_coins){
     
    int partiton = 0 ;
    int current_friend = 0 ;

    for(int i = 0 ; i <= n ; i++){
        current_friend += arr[i] ;
        if(current_friend >= min_coins){
            current_friend = 0 ;
            partiton++ ;
        }
    }
    return partiton >= k ;
}


int k_partition(int *arr , int n , int k){
    int s = 0 ; 
    int e = 0 ;
    for( int i {} ; i < n ; i++){
        e += arr[i] ;
    }
    int ans {} ;
    while(s<=e){
        int mid = (s+e) /2 ;
        bool isPossible = divideAmongK(arr , n , k , mid) ;
        if(isPossible){
            s = mid+1 ;
            ans = mid ;
        }else {
            e = mid -1 ;
        }
        
    }
    return ans ;
}

int main() {
    int a[] = {1 ,2 ,3 ,4} ;
    int n = sizeof (a) / sizeof (int ) ;
    int k = 3 ;

    std::cout << k_partition(a ,  n , k);

    return 0 ;
}