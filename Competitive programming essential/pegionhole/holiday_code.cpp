#include <iostream >
#include <vector>
#include <numeric>
#include <algorithm>

typedef long long ll ;

// give us the size of the tree from node where it is called 
int dfs (int u , int parent , std::vector<std::pair<int, int >> adj[] , long long &ans , int N ){
    int currentTreeSize {1} ;
    for(auto p : adj[u]){
        int v {p.first} ;
        int wt {p.second } ;
        //  handle for cylic case or skip the parent node (which is acting as nbr)
        if(parent == v) {
            continue; 
        }
        int childTreeSize = dfs (v , u , adj , ans , N) ;
        int edgeContribution = 2* std::min(childTreeSize , N-childTreeSize)*wt ;
        ans += edgeContribution ;
        //update the ree size by adding childTree size 
        currentTreeSize += childTreeSize ;

    }
    return currentTreeSize ;
}

int main() {
    // your code goes here 
    int test {} ;
    std::cin >> test ;

    // graph
    int n , u , v , w ; 
    std::vector<std::pair<int , int>> adj[100005] ;
    int tc = 1 ;

    while(tc <= test){
        std::cin >> n ;
        // reset the adj list before every test case 
        for (int i=1  ; i<=n ; i++){
            adj[i].clear() ;
        }
        //scan the graph
        for(int i=1 ; i<=n-1 ; i++){
            std::cin >> u >> v >> w ; 
            adj[u].push_back({v,w}) ;
            adj[v].push_back({u,w}) ;
        }

        //dfs 
        long long ans {} ;
        dfs(1 , -1 , adj , ans , n ) ;
        std::cout << "case # " << tc << ": " << ans <<std::endl ;
        tc = tc + 1 ;
    }
    return 0 ;
}