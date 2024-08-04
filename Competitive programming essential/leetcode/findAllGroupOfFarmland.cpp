#include<bits/stdc++.h>
using namespace std; 

    pair<int , int> dfs(int row , int col ,  vector<vector<int>> &land , vector<vector<int>> &visited){
        visited[row][col] = 1 ;
        pair<int , int> res = make_pair(row , col) ;
        vector<vector<int>> dirs_nbrs {{1, 0} , {-1 , 0 } , {0 , 1 } , {0 , -1}} ;
        for(auto nbrs : dirs_nbrs ){
            int x = row + nbrs[0] ;
            int y = col + nbrs[1] ;

            if(x < 0 || x == (int)land.size() || y < 0 || y== (int)land[0].size() ||land[x][y] == 0 || visited[x][y] ) continue ;

            auto ans = dfs(x , y , land , visited ) ;
            res.first = max(res.first , ans.first) ;
            res.second = max(res.second , ans.second) ;

        }
        return res ;

    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n {static_cast<int>(land.size())} , m {static_cast<int>(land[0].size())} ;
        vector<vector<int>> visited ( n , vector<int> (m , 0) ) ;

        vector<vector<int>> ans {} ;
        for(int i{} ; i< n ; i++){
            for(int j {} ; j < m ; j++){
                if(visited[i][j] == 0 && land[i][j] == 1){
                    auto pr = dfs(i , j , land , visited) ;
                    ans.emplace_back(vector<int> {i , j , pr.first , pr.second}) ;
                }
            }
        }

        return ans ;

    }

int32_t main(){
    vector <vector<int>> land  {{1,1},{1,1}} ;
    auto temp = findFarmland(land) ;

    for( auto s : temp ){
        cout << "[ " ; 
        for(auto x : s ) cout << x << " " ;
        cout << "]" ;
    }

    return 0 ;
}			