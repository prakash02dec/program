#include<iostream>
#include<climits>

int I {INT_MAX} ;

void Union(int set [] , int u , int v){
    if(set[u] < set[v]){
        set[u] = set[u] + set[v] ;
        set[v] = u ; 
    }else{
        set[v] = set[v] + set[u] ;
        set[u] = v ; 
    }
}

int find (int set[] , int u ){
    int x {u}, v {};
    while(set[x]>0){
        x = set[x] ;
    }
    // collapsing finding addition code
    while(u!=x){
        v = set[u] ;
        set[u] = x ;
        u = v ;
    }
    return x ;
}

void kruskal (){
    int edges[3][9] {
        {1,1,2,2,3,4,4,5,5},
        {2,6,3,7,4,5,7,6,7},
        {25,5,12,10,8,16,14,20,18},
    } ;
    int set[8] {-1,-1,-1,-1,-1,-1,-1,-1} ; // disjoint subset
    int included[9] {0} ;
    int t[2][6] {};
    int i {} , n {7} , e {9} ;
    while(i < n-1){
        int min {I} , k {};
        // finding minimum edges
        for(int j {} ; j < e ; j++){
            if(included[j] == 0 && edges[2][j] < min){
                min = edges[2][j] ;
                k = j ;
            }
        }
        if(find(set, edges[0][k]) != find(set , edges[1][k])){
            t[0][i] = edges[0][k] ;
            t[1][i] = edges[1][k] ;
            Union(set , find(set , edges[0][k] ) , find(set , edges[1][k])) ;
            i++ ;
        }
        included[k] = 1 ; 
    }

    for(int i {} ; i < n-1 ; i++ ){
        std::cout << t[0][i] << " - " << t[1][i] << std::endl ;
    }
}

int main() {
    kruskal() ;
    return 0 ; 
}