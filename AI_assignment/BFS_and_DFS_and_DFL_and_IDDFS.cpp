//  1. BFS
//  2. DFS
//  3. DLS
//  4. IDDFS

#include<bits/stdc++.h>
using namespace std;
   
class Graph
{
    int V;    
    list<int> *adj;
public:
    Graph(int V);  
    void addEdge(int v, int w);
    void BFS(int v); 
    void DFS(int v);
    void DLS1(int v , int limit) ;
    bool DLS(int v, int target, int limit);
    bool IDDFS(int v, int target, int max_depth);
};
   
Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}
   
void Graph::addEdge(int u, int v){
    adj[u].push_back(v); 
}

// it is like dfs with depth limitation
bool Graph::DLS(int src, int target, int limit){
    if (src == target)
        return true;
    if (limit <= 0)
        return false;
    for (auto i = adj[src].begin(); i != adj[src].end(); ++i)
       if (DLS(*i, target, limit-1) == true)
          return true;
   
     return false;
}
   
bool Graph::IDDFS(int src, int target, int max_depth){

    for (int i = 0; i <= max_depth; i++)
       if (DLS(src, target, i) == true)
          return true;
   
    return false;
}

void Graph::BFS(int v){
    vector<bool> visited;
    visited.resize(V,false);
    list<int> queue;

    visited[v] = true;
    queue.push_back(v);
 
    while(!queue.empty()){
        v = queue.front();
        cout << v << "-->";
        queue.pop_front();

        for (auto adjecent: adj[v]){
            if (!visited[adjecent]){
                visited[adjecent] = true;
                queue.push_back(adjecent);
            }
        }
    }
}


void Graph::DLS1(int v, int limit){
    if(limit>0){
    vector<bool> visited;
    visited.resize(V,false);
    visited[v] = true;
    cout << v << "-->";

    for (auto i {adj[v].begin()}; i != adj[v].end(); ++i)
        if (!visited[*i])
            DLS1(*i , limit-1);
    }
}


void Graph::DFS(int v){
    vector<bool> visited;
    visited.resize(V,false);
    visited[v] = true;
    cout << v << "-->";

    for (auto i {adj[v].begin()}; i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}

int main(){

    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 5);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    std::cout << std::endl << "BFS : " ;
    g.BFS(2) ;
    std::cout << std::endl << "DFS : " ;
    g.DFS(1) ;
    std::cout << std::endl << "DLS with max depth 2 : " ;
    g.DLS1(3,2) ;
    int target  {3}, maxDepth {1}, src  {0};
    std::cout << std::endl << "IDDFS with max depth " << maxDepth << " : " ;
    
    if (g.IDDFS(src, target, maxDepth) == true)
        std::cout << "Target is reachable from source "
                "within max depth";
    else
        std::cout << "Target is NOT reachable from source "
                "within max depth";
    return 0;
}