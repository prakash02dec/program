#include<bits/stdc++.h>
using namespace std ;

class Graph{
    int V ;
    list<int> *l ;
    public : 

    Graph(int n ){
        V = n ;
        l = new list<int> [n] ;
    }

    void addEgde(int x , int y , bool undir = false){
        l[x].push_back(y) ;
        if(undir){
            l[y].push_back(x) ;
        }
    }

    int dp(int i , vector<int> &memo){
        int ans = 0;   
        if(memo[i] != -1 ) return memo[i] ;
        for(auto child : l[i]){
            ans = max(ans , dp(child , memo)+ 1) ;
        }
        return memo[i] = ans ;
    }

    int longestPath(){
        int ans {} ;
        vector<int>  memo(V , -1 ) ;
        for(int i {1} ; i < V; i++){
            ans = max(ans , dp(i , memo)) ;
             
        }
        return ans ;
    }
};

int main() {
    int n ,m ;
    cin>> n >> m;
    Graph g(n+1) ;
    for(int i {} ; i< m ; i++) {
        int x , y ;
        cin>> x >> y ;
        g.addEgde(x , y ) ;
    }
    
    cout << g.longestPath() ;
    
    return 0 ;
}