#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    string name ;
    multiset<string> nbrs ;

    Node(string name){
        this->name = name ;
    }
};

class Graph{
    // All Node
    // hashmap (string , Node)

        unordered_map<string , Node* > m ;
        int edges ;
    public :
        Graph(vector<vector<string>> edges){
            this->edges = 0 ;
            for(auto edge : edges ){
                if(!m.count(edge[0]))
                    m[edge[0]] = new Node (edge[0]) ;
                if(!m.count(edge[1]))
                    m[edge[1]] = new Node (edge[1]) ;
                addEdge(edge[0] , edge[1]) ;
                this->edges++ ;
            }
                
        }
        Graph(vector<string> cities){
            edges = 0 ;
            for(auto city : cities){
                m[city] = new Node (city) ;
            }
        }

        void addEdge(string x , string y , bool undir= false){
            m[x]->nbrs.insert(y) ;
            if(undir){
                m[y]->nbrs.insert(x) ;
            }
        }
        
        void printAdjList(){
            for(auto cityPair : m){
                auto city = cityPair.first ;
                Node *node = cityPair.second ;

                cout << city << "--> " ;
                for(auto nbr{node->nbrs.begin()} ; nbr != node->nbrs.end() ; nbr++){
                    cout << *nbr << ", " ;
                }
                cout << endl ;
            }
        }
// ["JFK","ANU","EZE","AXA","TIA","ANU","JFK","TIA","ANU","TIA","JFK"]
            // helper function
        void dfs(string source , vector<string> &soln){   
           
            auto &nbrs {m[source]->nbrs} ;
            for(auto nbr{nbrs.begin()} ; nbr != nbrs.end() ; nbr++){
                    cout << *nbr << ", " ;
                }
            cout << endl;
            while(!nbrs.empty()){
                // if(!visited.count(pair<string , string> {source , nbr})){
                    // visited.insert(pair<string , string> {source , nbr}) ;
                    // cout << source<< " " << nbr << endl
                    cout << source << " " << *nbrs.begin() << " begin () \n" ;
                    auto temp = *nbrs.begin() ;
                    // cout << "delete : " << temp ;
                    nbrs.erase(nbrs.begin()) ;
                    dfs(temp , soln) ;
                    
                
                // }
            }
            //  cout << source << " " ;
            soln.push_back(source) ;
            return ;
        }
    
    ~Graph(){
        for(auto citypair : m){
                delete citypair.second ;
        }
    }
        
};

vector<string> findItinerary(vector<vector<string>> tickets) {
    Graph g(tickets) ;
    vector<string> soln ; 
    g.printAdjList() ;
    g.dfs("JFK" , soln) ;
    
    reverse(soln.begin() , soln.end()) ;
    for(auto ele : soln){
        cout << ele << " " ;
    }
    return soln ;
}

int main() {
    findItinerary({{"EZE","AXA"},{"TIA","ANU"},{"ANU","JFK"},{"JFK","ANU"},{"ANU","EZE"},{"TIA","ANU"},{"AXA","TIA"},{"TIA","JFK"},{"ANU","TIA"},{"JFK","TIA"}});
    // findItinerary({{"AAA","NNN"},{"NNN","AAA"},{"AAA","BBB"}}) ;
    // findItinerary({{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}}) ;
    // findItinerary({{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}}) ;
    return 0 ;
}
// ["JFK","ANU","EZE","AXA","TIA","ANU","JFK","TIA","ANU","TIA","JFK"]