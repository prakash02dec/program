#include<bits/stdc++.h>
using namespace std ;

vector<vector<int>> calculate_cofficient(int n , int k){
    std::vector<vector<int>> table (n+1 , vector<int> (k+1 , 0)) ;
    for(int i {} ; i <= n ; i++){
        for(int j {} ; j <= min(i,k) ; j++){
            if(j==0 || j== n)
                table[i][j] = 1;
            else 
                table[i][j] = table[i-1][j-1] + table[i-1][j];
            
        }
    }
    return table ;
}

int main() {
    int n {1337} ;
    std::cin >> n ;
    vector <vector <int >> table = calculate_cofficient(n, n) ;

    int queries {1} ;
    while(queries--){
        int k {} ;
        std::cin>> k ;
        std::cout << table[n][k] << std::endl ;
    }


    return 0 ;
}