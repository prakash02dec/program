#include<bits/stdc++.h>
using namespace std;

class Graph {
    int V ;
    list<int> *l ;
    public :
    Graph(int v){
        V= v ;
        l = new list<int> [v] ;
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
    int dfs(int source ,int parent ){
        int height {} ;
        for(auto nbr : l[source]){
            if( nbr != parent)
                height = max (height , dfs(nbr , source)) ;
        }
        return height + 1 ;
    }

    ~Graph(){
        delete [] l ;
    }

};
vector<int> treeDistances(int n, vector<vector<int>>edges){
    Graph g(n+1) ;
    for(auto edge : edges){
        g.addEdge(edge[0] , edge[1]) ;
    } 
    vector<int> ans ;
    for(int i {1} ; i<= n ; i++ ){
        ans.push_back(g.dfs( i  , -1) -1 ) ;
    }
    for(auto ele : ans ) cout << ele << " " ; 
    cout << endl ;
    
    return ans ; 
}


int main() {    
    treeDistances(5 , {{1, 2},{1, 3},{3, 4},{3, 5}} )  ;
    return 0 ; 
}