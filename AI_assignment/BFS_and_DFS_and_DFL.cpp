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
#include <numeric>

void BFS(int G[][7],int start ,int n ){
    int i {start} ;
    std::queue<int> q {} ;
    bool visited[n] {} ;
    std::cout << i << "-->";
    visited[i] = true ;
    q.push(i);
    while(!q.empty()){
        i = q.front() ;
        q.pop() ;
        for(int j{1} ; j<n ; j++ ){
            if(G[i][j] == 1 && visited[j] == 0){
                std::cout << j << "-->";
                visited[j] = true ;
                q.push(j) ;
            }
        }
    }
}

void USC(int G[][7],int start ,int n ){
    int i {start} ;
    std::priority_queue<int , std::vector<int>, std::greater<int>> q {} ;
    bool visited[n] {} ;
    std::cout << i << "-->";
    visited[i] = true ;
    q.push(i);
    while(!q.empty()){
        i = q.top() ;
        q.pop() ;
        for(int j{1} ; j<n ; j++ ){
            if(G[i][j] == 1 && visited[j] == 0){
                std::cout << j << "-->";
                visited[j] = true ;
                q.push(j) ;
            }
        }
    }

}

void DFS(int G[][7] , int start ,int n ){
    static bool visited[7] {false} ;
    if(!visited[start]){
        std::cout << start << "-->" ;
        visited[start] = true ;
        for(int j{1} ; j<n ; j++){
            if( G[start][j] == 1 && !visited[j] ){
                DFS(G , j , n);
            }
        }
    }
}

void DFL(int G[][7] , int start ,int n , int limit ){
    static bool visited[7] {false} ;
    if(!visited[start] && limit > 0){
        std::cout << start << "-->" ;
        visited[start] = true ;
        for(int j{1} ; j<n ; j++){
            if( G[start][j] == 1 && !visited[j] ){
                DFL(G , j , n , limit-1);
            }
        }
    }
}

int main() { 
    int graph[7][7]{
        {0,0,0,0,0,0,0},
        {0,0,12,32,0,0,0},
        {0,10,0,0,41,0,0},
        {0,12,0,0,43,0,0},
        {0,0,13,18,0,12,11},
        {0,0,0,0,19,0,0},
        {0,0,0,0,15,0,0},
    };
    std::cout << std::endl << "BFS : " ;
    BFS(graph , 4 , 7) ;
    std::cout << std::endl << "USC : " ;
    USC(graph , 4 , 7) ;
    std::cout << std::endl << "DFS : " ;
    DFS(graph , 1 , 7) ;
    std::cout << std::endl << "DFL : " ;
    DFL(graph,1 ,7 , 2 ) ;
    return 0 ;
}