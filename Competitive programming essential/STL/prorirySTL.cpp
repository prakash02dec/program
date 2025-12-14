#include<iostream>
#include <vector>
#include <queue>

int main() {
    std::vector<int> v ;
    std::priority_queue<int , std::vector<int> , std::greater<int>> heap ; // min heap with greater
    // when the capacity increase , its cost also increase in terms of time 
    v.reserve(100) ;
 
    return 0 ;
}