#include <bits/stdc++.h>
using namespace std ;


int matrixScore(vector<vector<int>>& grid) {
        auto  cols{grid[0].size()} , rows {grid.size()} ;
        for(auto &binary : grid){
            if(!binary[0])
                for_each(binary.begin() ,binary.end() , [](int &x){x = (x == 1) ? 0 : 1 ;}) ;
        }
        for(auto binary : grid){
            for(auto x : binary){
                std::cout << x << " " ;
            }
            std::cout << std::endl ;
        }
        for(int i {1} ; i < cols ; i++ ){
            int count {} ;
            for(int j {} ; j < rows ; j++){
                if(grid[j][i]) count++ ;
            }
            if(count < ceil(rows/float(2))){
                for(int j {} ; j < rows ; j++)
                    grid[j][i] = grid[j][i] == 0 ? 1 : 0 ;
            }
        }
        std::cout<< std::endl << std::endl ;
        for(auto binary : grid){
            for(auto x : binary){
                std::cout << x << " " ;
            }
            std::cout << std::endl ;
        }
        int ans {} ;
    
        for(auto binary : grid){
            int pow {} ;
            for(auto no : binary){
                ans += no*(1<<(cols - pow-1)) ;
                pow++ ;
            }
        }
        return ans ;
}

int main() {
    // vector<vector<int>> grid {{0,0,1,1},{1,0,1,0},{1,1,0,0}} ;
        vector<vector<int>> grid {{0,1},{1,1}} ;
    std::cout << matrixScore(grid) ;
    return 0 ;
}