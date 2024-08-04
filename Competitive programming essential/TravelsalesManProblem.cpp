#include <iostream> 
#include <climits>
#include <vector>
using namespace std ;

int tsp(std::vector<std::vector<int>> dist , int setOfCities , int city , int n , std::vector<std::vector<int>> &dp){
    // base case
    if( setOfCities == (1<<n)-1 ){
        // return the cost from the current city to the orginal 
        return dist[city][0] ;
    }
    if(dp[setOfCities][city] != -1){
        return dp[setOfCities][city] ;
    }
    int ans {INT_MAX} ;
    // otherwise try all possible options 
    for(int choice {} ; choice < n ; choice++){
        if((setOfCities&(1<<choice)) == 0 ){  // visited or not
            int subProb {dist[city][choice] + tsp(dist , (setOfCities | (1<<choice)) , choice , n , dp ) } ; // (setOfCities | (1<<choice)) => adding a city
            ans = min(ans ,subProb) ;
        }
    }
    dp[setOfCities][city] = ans ;
    return ans ; 
}

int main() {
    std::vector<std::vector<int>> dist {
        {0,20,42,25},
        {20,0,30,34},
        {42,30,0,10},
        {25,34,10,0},
    } ;
    int n {4};
    std::vector< std::vector<int> > dp ( 1<<n ,std::vector<int> (n,-1) ) ;
    std::cout << tsp(dist , 1, 0 , n , dp ) << std::endl ;
    return 0 ;
}