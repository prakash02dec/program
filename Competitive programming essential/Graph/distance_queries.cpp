#include <bits/stdc++.h>
using namespace std ;

class Graph {
    int V ;
    list<int> *l ;
    vector<vector<int>> parent ;
    int m ;
    vector<int> depth ;
    public :
    Graph(int v){
        V= v ;
        l = new list<int> [v] ;
        m = (int)log(V) +1 ;
        depth.resize(V , 0) ;
        parent.resize(V , vector<int> ( m , 0)) ;
    }

    void addEdge(int i , int j , bool undir = true){
        l[i].push_back(j) ;
        if(undir){
            l[j].push_back(i) ;
        }
    }

    void printAdjList(){
        for(int i {} ; i<V ;i++){
            cout << i << "--> " ;
            for(const auto node : l[i]) {
                cout << node << ", " ;
            }
            cout << endl ;
        }
    }

    // helper function
    void dfs(int source , int parents ){
        depth[source] = depth[parents] + 1 ;
        parent[source][0] = parents ;
        for(int i {1} ; i <m ; i++){
            parent[source][i] = parent[parent[source][i-1]][i-1] ;
        }
        
        for(auto nbr : l[source]){
            if(nbr != parents )
                dfs(nbr , source) ;
        }
        
        return ;
    }
    
    int LCA(int u , int v){
        if(u == v) return u ;
        if(depth[u]<depth[v]) swap(u , v) ;
        
        int diff = depth[u] - depth[v] ;
        
        for(int i {m-1} ; i >= 0 ; i--){
            if( (diff>>i)&1) u = parent[u][i];
        }
        
        for(int i {m-1} ; i >= 0 ; i--){
            if( parent[u][i] != parent[v][i] ){
                u = parent[u][i] ;
                v = parent[v][i] ;
             }
        }
        if(u == v) return u ;
        return parent[u][0] ;
        
    }
    
    int distance(int u , int v){
        int lca {LCA(u , v)} ;
        return depth[u] + depth[v]- 2*depth[lca] ;
    }
    
    
    ~Graph(){
        delete [] l ;
    }

};


vector<int> distanceQuery(int n, vector<vector<int>>edges, vector<vector<int>>queries){
    Graph g(n+1) ;
    for(const auto edge : edges){
        g.addEdge(edge[0] , edge[1]) ; 
    }
    g.dfs(1 , 0) ;
    vector<int> ans ;
    for(auto query : queries){
        ans.push_back(g.distance(query[0] , query[1])) ;   
    }
    
    
    return ans ;
}