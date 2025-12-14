// Given an integer array nums and an integer k, return the kth largest element in the array.
// Note that it is the kth largest element in the sorted order, not the kth distinct element.

#include<bits/stdc++.h>

// my approach
// int findKthLargest(std::vector<int> nums, int k) {
//     std::multiset<int> set{nums.begin() , nums.end()};
    
//     for(auto it{set.rbegin()}; it!=set.rend() ; it++ ){
//         if(k == 1 )
//             return *it ; 
//         k-- ;
//     }
// }

// solution approach
int findKthLargest(std::vector<int> nums, int k) {
   std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for (int num : nums) {
        pq.push(num);
        if (pq.size() > k) {
            pq.pop();
        }
    }
    return pq.top();
}

int main() {
    std::vector<int> vec{13,-98,99 ,1,-66,-48,-43} ;
    findKthLargest(vec , 2) ;
    return 0 ;
}