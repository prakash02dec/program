#include<bits/stdc++.h>
using namespace std;


class Graph {
    int V  ;
    list <int > *l ;
    public :
    Graph(int v){
        V = v ;
        l = new list<int> [v] ;
    }

    void addEdge(int u , int v , bool undir = true){
        l[u].push_back(v) ;
        if(undir)
            l[v].push_back(u) ;
    }

    void printAdjList(){
        for(int i {} ; i<V ; i++ ){
            cout << i << "--> " ;
            for(auto ele : l[i]) cout << ele << " " ;
            cout << endl ; 
        }
    }

    int bfs(int source , int destination){
        bool visited[V] {false } ;
        queue<int> q ;
        int dist[V] ;
        for(int i {} ; i < V ; i++){
            dist[i] = -1 ;
        } 
        dist[source] = 1 ;
        q.push(source) ;
        visited[source] = true ;
        // cout << "BFS : " ;
        while(!q.empty()){
            int top = q.front() ;
            q.pop() ;
            // cout << top << " " ;
            for(auto nbr : l[top]){
                if(!visited[nbr]) {
                    q.push(nbr) ;
                    visited[nbr] = true ;
                    dist[nbr] = dist[top] + 1; 
                }
            }
        }
        return dist[destination] ;
    }

} ; 

int messageRoute(int n, vector<vector<int>>edges){
    Graph g(n+1) ;
    for(auto edge : edges){
        g.addEdge(edge[0] , edge[1]) ;
    }
    return g.bfs(1, n) ;

}


int main() {
    cout << messageRoute(5 , {{1,2},{1,3},{1,4},{2,3},{5,4}} ) ;
    return 0 ;
}