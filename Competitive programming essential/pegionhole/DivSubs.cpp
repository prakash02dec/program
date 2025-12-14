#include <iostream>
#include <vector>
#include <unordered_map>
int solve(int n , std::vector<int > nums){
    std::vector<int> sums (5,0) ;
    sums.at(0) = nums.at(0)%n ;
    for(int i {1} ; i < n ; i++){
        sums.at(i) = (sums.at(i-1) + nums.at(i))%n ;    
    }
    std::unordered_map<int , int > hash_table {} ;
    for(const auto &sum : sums){
        hash_table[sum]++ ;
    }
    int ans {} ;
    for(auto it {hash_table.begin()} ; it != hash_table.end() ; it++) {
        if(it->second > 1){
            ans += (it->second * (it->second-1))/2 ;
        }
    }
    return ans ;
    
}


int main() {
    
    return 0 ; 
}