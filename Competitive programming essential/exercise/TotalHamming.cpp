#include<bits/stdc++.h>
using namespace std;

int totalHammingDistance(vector<int> nums) {
    int ans {} , length {nums.size()};
    for(int i {} ; i <= 31 ; i++){
        int count_ones {} ;
        for(auto x : nums ){
            if(x&(1<<i)) count_ones++ ;
        }
        ans += count_ones*(length-count_ones) ;
    }
    return ans ;
}