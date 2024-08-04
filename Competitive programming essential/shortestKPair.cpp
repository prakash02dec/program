#include<bits/stdc++.h>
using namespace std;

// vector<vector<int>> kSmallestPairs(vector<int> nums1, vector<int> nums2, int k) {
//         set<pair<int , int>> visited ;
//         priority_queue< vector<int> , vector<vector<int>> , greater<vector<int>>  > min_heap ;
//         vector<vector<int>> ans ;

//         min_heap.emplace(vector<int>{nums1[0]+nums2[0] , 0 ,0}) ;
//         auto top = min_heap.top() ;
//         visited.insert({0 ,0}) ;
//         while(k>0 && !min_heap.empty()){

//             auto top = min_heap.top() ;
//             int i {top[1]} , j{top[2]} ;
//             min_heap.pop() ;


//             ans.emplace_back(vector<int> {i , j}) ;
//             if(i+1 < nums1.size() and !visited.count({i+1 , j})){
//                 min_heap.emplace( vector<int>{ nums1[i+1]+nums2[j] , i+1 ,j} ) ;
//             }
//             if(j+1 < nums2.size() and !visited.count({i , j+1})){
//                 min_heap.emplace(vector<int>{ nums1[i]+nums2[j+1] , i ,j+1} ) ;

// //             }

//             k-- ;
//         }

//         return ans ;
//     }


vector<vector<int>> kSmallestPairs(vector<int> nums1, vector<int> nums2, int k) {
        set<pair<int , int>> visited ;
        priority_queue< vector<int> , vector<vector<int>> , greater<vector<int>>  > min_heap ;
        vector<vector<int>> ans ;

        min_heap.emplace(vector<int>{nums1[0]+nums2[0] , 0 ,0}) ;
        auto top = min_heap.top() ;
        visited.insert({0 ,0}) ;
        while(k>0 && !min_heap.empty()){
            auto top = min_heap.top() ;
            int i {top[1]} , j{top[2]} ;
            min_heap.pop() ;

            ans.emplace_back(vector<int> {i , j}) ;
            if(i+1 < nums1.size() and !visited.count({i+1 , j})){
                min_heap.emplace( vector<int>{ nums1[i+1]+nums2[j] , i+1 ,j} ) ;
            }
            if(j+1 < nums2.size() and !visited.count({i , j+1})){
                min_heap.emplace(vector<int>{ nums1[i]+nums2[j+1] , i ,j+1} ) ;
            }

            k-- ;
        }
        for(auto &ele : ans){
            cout << ele[0] << " " << ele[1] << endl ;
        }
        return ans ;
    }

int main() {
    kSmallestPairs({1,7,11} , {2,4,6}, 3) ;
    return 0 ;
}



