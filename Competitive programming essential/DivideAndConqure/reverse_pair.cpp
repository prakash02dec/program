#include<bits/stdc++.h>
using namespace std;

int merge(int l  , int mid , int h , vector<int> &arr){
    int count {} ;
    int right {mid+1} ;
    for(int i{l} ; i<= mid ; i++){
        while(arr[i]>(long long)2*arr[right] && right <= h){
            right++ ;
        }
        count += right - (mid +1 );
    }
    
    vector<int> temp ;
    int i {l} , j {mid+1 } ;
    
    while(i<= mid && j <= h){
        if(arr[i]<arr[j]){
            temp.push_back(arr[i++]) ;
        }else{
            temp.push_back(arr[j++]) ;
            
        }
    }
    while(i<= mid){
       temp.push_back(arr[i++] ) ; 
    }
    while(j<= h){
        temp.push_back(arr[j++]) ;
    }
    int idx {} ;
    for(int k{l} ; k<= h ; k++ ){
        arr[k] = temp[idx++];
    }
    return count ;
}

int countPairs(int l , int h , vector<int> &arr){
    if(l>=h){
        return 0  ;
    }
    int mid {(l+h)/2} ;
    int v1 = countPairs( l ,  mid , arr) ;
    int v2 = countPairs( mid+1, h , arr ) ;
    int v3 = merge(l , mid , h , arr) ;
    return v1 + v2 + v3 ;
}

int reversePairs(vector<int> &nums) {
    return countPairs( 0 , nums.size()-1 , nums)   ; 
}

int main(){
    vector<int> nums {-704, -827, -785, -248, -187, -73, -254, -716} ;
    std::cout << reversePairs(nums) ;
    // std::cout << endl ;
    // for(auto ele : nums){
    //     std::cout << ele << " " ;
    // }
    // std::cout << endl ;
    return 0 ;
}

    // int count {} ;
    // int right {mid+1} ;
    // for(int i{l} ; i<= mid ; i++){
    //     if( right <= h && arr[i]>2*(long long)arr[right] ){
    //         right++ ;
    //     }
    //     count += (right - mid -1 );
    // }


    // int count {} ;
    // int j = mid+1;
    // for(int i=low; i<=mid; i++){
    //     while(j<=high && nums[i] > 2*(long long)nums[j]){
    //         j++;
    //     }
    //     count += j-(mid+1);
    // }