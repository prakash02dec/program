#include <bits/stdc++.h>
using namespace std ;

class Node {
    public:
    string name ;
    list<string> nbrs ;

    Node(string name){
        this->name = name ;
    }
};

class Graph{
    // All Node
    // hashmap (string , Node)

        unordered_map<string , Node* > m ;
    public :
        Graph(vector<string> cities){
            for(auto city : cities){
                m[city] = new Node (city) ;
            }
        }
        Graph(vector<vector<string>> edges){
            for(auto edge : edges ){
                // cout << edge[0] << " " << edge[1] << endl ;
                if(!m.count(edge[0]))
                    m[edge[0]] = new Node (edge[0]) ;
                if(!m.count(edge[1]))
                    m[edge[1]] = new Node (edge[1]) ;
                addEdge(edge[0] , edge[1]) ;
            }
                
        }


        void addEdge(string x , string y , bool undir= false){
            m[x]->nbrs.push_back(y) ;
            if(undir){
                m[y]->nbrs.push_back(x) ;
            }
        }
        
        void printAdjList(){
            for(auto cityPair : m){
                auto city = cityPair.first ;
                Node *node = cityPair.second ;

                cout << city << "--> " ;
                for(auto nbr : node->nbrs){
                    cout << nbr << ", " ;
                }
                cout << endl ;
            }
        }

            // helper function
        void dfs(string source , unordered_set<string> &visited ){   
            cout << source << " " ;
            visited.insert(source) ;
            auto nbrs {m[source]->nbrs} ;
            for(auto nbr : nbrs){
                if(!visited.count(nbr))
                    dfs(nbr , visited) ;
            }
            
            return ;
        }

        void dfs(string source){
            unordered_set<string> visited ;
            cout << "DFS : " ;
            dfs(source , visited) ;
            cout << endl ;

        }
    
    ~Graph(){
        for(auto citypair : m){
                delete citypair.second ;
        }
    }
        
};

int main() {
    vector<string> cities = {"Delhi" , "London" , "Paris" , "New York"} ;
    Graph g(cities)  ;
    g.addEdge("Delhi" ,"London" ) ;
    g.addEdge("Delhi" ,"Paris" ) ;
    g.addEdge("New York" ,"London" ) ;
    g.addEdge("Paris" ,"New York" ) ;

    // g.printAdjList() ;
    g.dfs("Delhi" ) ;

    return 0 ;
}