#include<bits/stdc++.h>
using namespace std;

vector<int> closestRoom(vector<vector<int>> rooms, vector<vector<int>> queries) {
    std::sort(rooms.begin() , rooms.end() , [](auto v1 , auto v2){return v1[1]>v2[1] ;}) ;
    
    for(int i {} ; i < queries.size()  ; i++ ) queries[i].push_back(i) ;
    
    std::sort(queries.begin() , queries.end() , [](auto v1 , auto v2){return v1[1]> v2[1] ;});
    
    std::set<int> temp ;
    std::vector<int> ans (queries.size()) ;
    
    int ptr {} ;
    for(int i {} ; i <  queries.size() ; i++){
        
        while( ( ptr < rooms.size() )and (queries[i][1] <=rooms[ptr][1] )){
            temp.insert(rooms[ptr][0]);
            ptr++ ;
        }
       
        if(temp.empty()){
            ans[queries[i][2]] = -1 ;
            continue ;
        }
        
        auto it  {temp.lower_bound(queries[i][0])} ;
        int min {static_cast<int>(1e7)} ;
        
        if(it != temp.end()){
            if(abs(queries[i][0] - *it)< min)
            ans[queries[i][2]] = *it ;
            min = abs(queries[i][0] - *it) ;
        }
        
        if(it != temp.begin()){
            --it ;
            if(min>= abs(queries[i][0]-(*it))){
                ans[queries[i][2]] = *it ;
                min = abs(queries[i][0] - *it) ;
            }
        }
    }   
    
    return ans ;
}   