#include<iostream>
#include<vector> 
#include<ctime>
#include<algorithm>

int main(){
    int n {} ;
    std::cin >> n ;
    std::vector<int> arr(n,0) ;

    // Init a Reverse Sorted Array
    for(int i{} ; i < n ; i++){
        arr[i] = n - i ;
    }

    auto start_time {std::clock()} ;
    sort(arr.begin() , arr.end()) ;
    auto end_time {std::clock()} ;

    std::cout << end_time - start_time << std::endl ;    
    return 0 ;

}