#include<bits/stdc++.h>
using namespace std;

struct pQ{
    list<int> path;
    int cost;
    bool operator>(const pQ &rhs) const
    {
        return cost > rhs.cost;
    }
};

class mycomparison{
public:
    bool operator()(pQ p1, pQ p2) const{
        return (p1 > p2);
    }
};

class Graph{
    int V;
    vector<int> *adj;
    vector<int> *wgt;

public:
    Graph(int V);
    void addEdge(int v, int w, int wgt);
    void UCF(int s, int t);
    void displayPath(struct pQ f);
};

Graph::Graph(int V){
    this->V = V;
    adj = new vector<int>[V];
    wgt = new vector<int>[V];
}

void Graph::addEdge(int v, int w, int wt){
    adj[v].push_back(w);
    wgt[v].push_back(wt);
}

void Graph::UCF(int s, int t){
    int current = 0, pos = 0;
    typedef priority_queue<pQ, vector<pQ>, mycomparison> mypq_type;
    mypq_type pq;

    pQ vstart;

    vstart.path.push_back(s);
    vstart.cost = 0;

    vector<int>::iterator i;
    pq.push(vstart);

    while (!pq.empty())
    {
        pQ currentPQ, tempPQ;
        current = pq.top().path.back();
        currentPQ = pq.top();
        pq.pop();
        if (current == t){
            cout << "found" << endl;
            displayPath(currentPQ);
            exit(0);
        }
        else{
            for (i = adj[current].begin(); i != adj[current].end(); ++i){
                tempPQ = currentPQ;
                tempPQ.path.push_back(*i);
                pos = find(adj[current].begin(), adj[current].end(), *i) - adj[current].begin();
                tempPQ.cost += wgt[current].at(pos);
                pq.push(tempPQ);
            }
        }
    }
}

void Graph::displayPath(struct pQ p){
    list<int>::iterator i;
    cout << "Path: ";
    for (i = p.path.begin(); i != p.path.end(); ++i)
    {
        cout << "-->" << *i;
    }
    cout << endl;
    cout << "Pathlength: " << p.cost;
}

int main(){
    int n, e;
    Graph g(6);
    int vstart = 0, vend = 0;
    g.addEdge(0, 1, 10);
    g.addEdge(0, 5, 12);
    g.addEdge(1, 2, 45);
    g.addEdge(1, 3, 76);
    g.addEdge(2, 4, 32);
    g.addEdge(3, 4, 12);
    g.addEdge(3, 5, 23);
    g.addEdge(4, 5, 67);
    cout << "Enter the start vertex:";
    cin >> vstart;
    cout << "Enter the end vertex:";
    cin >> vend;

    g.UCF(vstart, vend);
    return 0;
}