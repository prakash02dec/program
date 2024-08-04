#include<bits/stdc++.h>
using namespace std ;

int boxStacking(vector<vector<int>> boxes ){
    vector<int> dp(boxes.size() , 0) ;
    sort(boxes.begin() , boxes.end() , [](auto v1 , auto v2){
        return v1[2] < v2[2] ;
    });
    dp[0] = boxes[0][2] ;
    int max_height = dp[0] ;
    for(int i{1} ; i<boxes.size() ; i++ ){
        dp[i] = boxes[i][2] ;
        for(int j {} ; j < i ; j++){
            if(boxes[i][0]> boxes[j][0] and boxes[i][1] > boxes[j ][1] and boxes[i][2] > boxes[j ][2]){
                dp[i] = max(dp[i] ,boxes[i][2] + dp[j] ) ;
                
            }
        }
        max_height = max(max_height , dp[i]);
    }
    for(auto ele : dp) cout << ele << " " ;
    return max_height ;
}

int main() {
    vector<vector<int>> boxes {
        {2 ,1 ,2} , 
        {3 ,2 ,3},
        {2, 2, 8},
        {2, 3, 4},
        {2 ,2, 1},
        {4 ,4 ,5}
    };
    cout << boxStacking(boxes) ;
    return 0 ;
}