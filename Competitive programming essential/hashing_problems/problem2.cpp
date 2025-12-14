// pair sum problem 
// possible approaches
// 1. 2 Nested loops O(N2)
// 2. sorting + 2 pointeres O(NlogN)
// 3. sorting + binary search O(NlogN)
// 4. hashing O(N)
#include<iostream>
#include <unordered_set>
#include <vector>

void pairsum(std::vector<int> arr , int sum ){
    std::unordered_set<int> s {};

    for(int i {0} ; i <arr.size() ; i++){
        int x {sum - arr[i]} ;
        if(s.find(x) != s.end()){
            std::cout << x << " - " << arr[i] << std::endl ;

        }
        s.insert(arr[i]);
    }
}

int main() {
    std::vector<int> arr{10,5,2,3,-6,9,11,2};
    pairsum(arr , 4) ;
    return 0 ;
}

