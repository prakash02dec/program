#include<bits/stdc++.h>
using namespace std;

vector<int> findClosestElements(vector<int> arr, int k, int x) {
    std::vector<int> ans {} ;
    std::priority_queue< std::pair<int,int> , std::vector<std::pair<int,int>> , std::greater<std::pair<int,int>> > heap {} ;  //min heap
    for(int i {} ; i < arr.size() ; i++){
        int diff {abs(arr[i]-x)};
        heap.push({diff,arr[i]});
    }       
    while(k--){
        ans.push_back(heap.top().second);
        heap.pop();
    }
    sort(ans.begin() , ans.end());
    return ans ;
}

int main(){

    return 0 ;
}