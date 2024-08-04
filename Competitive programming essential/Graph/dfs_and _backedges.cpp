#include<bits/stdc++.h>
using namespace std;

const int N= 1e5 +1 ;
int vis[N] {} ;
bool cycle = false ;

vector<int> g[N] ;

void dfs(int cur , int par){
    cout << cur << " " ;
    vis[cur] = 1 ;
    for(auto x : g[cur]){
        if(!vis[x]){
            dfs(x, cur) ;
        }
        else if(x != par){ 
            cout << "\nbackegde : " << cur << " " << x << endl ;
            cycle = true ;
        }
    }
}


int main(){
    int n , m ;
    cin >> n >> m ;

    for(int i {} ; i < m ; i++){
        int x , y ;
        cin >> x >> y ;
        g[x].push_back(y) ;
        g[y].push_back(x) ;
    }

    for(int i { 1 } ; i <= n ; i++){
        if(!vis[i]) 
            dfs(1 , -1) ;
    }

    if(cycle) cout << "\n cycle is present" ;


    return 0 ;
}			