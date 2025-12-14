#include <bits/stdc++.h>
using namespace std ;

class Graph {
    int V ;
    list<int> *l ;
    public :
    int ans ;
    Graph(int v){
        V= v ;
        l = new list<int> [v] ;
        ans = 0 ;
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
    void bfs(int source){
        cout << "BFS : " ;
        queue<int> q ;
        bool Visited [V] {false} ;

        q.push(source) ;
        Visited[source] = true ;

        while(!q.empty()){
            // work for every node 
            int f = q.front() ;
            cout << f << " " ;
            q.pop () ;
            // push the nbrs of current node which not visited 
            for(auto nbr : l[f]){
                if(!Visited[nbr])
                    q.push(nbr) ;
                    Visited[nbr] = true ;
            }   

        }
        cout << endl ;

    }

    // helper function
    int dfs(int source  , int parent ){
        int total {} ;
        for(auto nbr : l[source]){
            if(nbr != parent)
                total += dfs(nbr , source) ;
        }
        ++total ;

        if((total&1) == 0 && parent != -1) ans++ ; 
        return total  ;
    }

    ~Graph(){
        delete [] l ;
    }

};
int solve(int n, vector<vector<int>> edges){
    Graph g(n+1) ;
    for(auto edge : edges){
        g.addEdge(edge[0] , edge[1]) ;
    }
    g.dfs(1 , -1) ;
    if(g.ans == 0) return -1 ;
    return g.ans ;
}


int main() {
    cout << solve(4 , {{2,4} , {4,1} ,{3,1}}) ;
    return 0 ;
}