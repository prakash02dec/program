#include <bits/stdc++.h>
using namespace std ;

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
    void dfs(int source , vector<bool> &visited ){
        
        cout << source << " " ;
        visited[source] = true ;
        for(auto nbr : l[source]){
            if(!visited[nbr])
                dfs(nbr , visited) ;
        }
        
        return ;
    }

    void dfs(int source){
        vector<bool> visited (V ,false) ;
        cout << "DFS : " ;
        dfs(source , visited) ;
        cout << endl ;
    }

    ~Graph(){
        delete [] l ;
    }

};

int main() {
    Graph g(7) ;
    g.addEdge(0,1) ;
    g.addEdge(1,2) ;   
    g.addEdge(2,3) ;
    g.addEdge(3,5) ;
    g.addEdge(5,6) ;
    g.addEdge(4,5) ;
    g.addEdge(0,4) ;
    g.addEdge(3,4) ;


    g.printAdjList() ;
    g.bfs(1) ;
    g.dfs(1) ;
    
    return 0 ;
}