#include<bits/stdc++.h>
using namespace std;

vector<int> smallestRange(vector<vector<int>> nums) {
    std::vector<int> result { -100'000 , 100'000 } ;
    std::priority_queue<std::vector<int>, std::vector<std::vector<int>> , std::greater<std::vector<int>> > minHeap {} ;
    int maxVal {INT_MIN} ;
    for(int i {} ; i < nums.size() ; i++ ){
        std::sort(nums[i].begin() , nums[i].end()) ;
        maxVal = max(nums[i][0], maxVal) ;
        // 1st -- element of the list
        // 2nd -- index of the element of the list 
        // 3rd -- index of the current list in the k list 
        minHeap.emplace(std::vector<int> {nums[i][0] , 0 , i}) ;
    }
    while(true){
        std::vector<int> minVal {minHeap.top()} ;
        minHeap.pop() ;
        if(result[1]-result[0] > maxVal-minVal[0]){
            result[1] = maxVal ;
            result[0] = minVal[0] ;
        }
        minVal[1]++ ;
        if(minVal[1] == nums[minVal[2]].size()) break;  // 
        else {
            minVal[0] = nums[minVal[2]][minVal[1]];
            maxVal = max(maxVal , minVal[0]) ;
            minHeap.push(minVal) ;
        }

    }

    return result ;
    
}