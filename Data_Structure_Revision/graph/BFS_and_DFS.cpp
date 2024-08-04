/*
            1       
           / \
          2   3
           \ /
            4
           / \
          5   6
*/
#include <iostream>
#include <queue>

void BFS(int G[][7],int start ,int n ){
    int i {start} ;
    std::queue<int> q {} ;
    bool visited[n] {} ;
    std::cout << "BFS : "; 
    std::cout << i << " ";
    visited[i] = true ;
    q.push(i);
    while(!q.empty()){
        i = q.front() ;
        q.pop() ;
        for(int j{1} ; j<n ; j++ ){
            if(G[i][j] == 1 && visited[j] == 0){
                std::cout << j << " ";
                visited[j] = true ;
                q.push(j) ;
            }
        }
    }

}

void DFS(int G[][7] , int start ,int n ){
    static bool visited[7] {false} ;
    if(!visited[start]){
        std::cout << start << " " ;
        visited[start] = true ;
        for(int j{1} ; j<n ; j++){
            if( G[start][j] == 1 && !visited[j] ){
                DFS(G , j , n);
            }
        }
    }
}

int main() { 
    int graph[7][7]{
        {0,0,0,0,0,0,0},
        {0,0,1,1,0,0,0},
        {0,1,0,0,1,0,0},
        {0,1,0,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0},
    };
    BFS(graph , 4 , 7) ;
    std::cout << std::endl << "DFS : " ;
    DFS(graph , 1 , 7) ;
    return 0 ;
}