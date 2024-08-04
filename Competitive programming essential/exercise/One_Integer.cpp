#include<bits/stdc++.h>

int solve(std::vector<int> nums) {
    std::priority_queue<int , std::vector<int> , std::greater<int>> heap {nums.begin() , nums.end()};
    int sum {} , x {} ,y {};
    while(heap.size() != 1){
        x = heap.top() ; heap.pop() ;
        y = heap.top() ; heap.pop() ;
        heap.push(x + y) ;
        sum += x + y ;
    }
    return sum ;
}

int main() {
    std::vector<int> nums {1, 2, 3, 4, 5};
    std::cout << solve(nums) ;
    return 0 ;
}