#include<iostream>
#include<climits> 
const int I {INT_MAX} ; // infinity

void prims(){ 
    // initialization
    int cost[][8] {
        {I,I,I,I,I,I,I,I},
        {I,I,25,I,I,I,5,I},
        {I,25,I,12,I,I,I,10},
        {I,I,12,I,8,I,I,I},
        {I,I,I,8,I,16,I,14},
        {I,I,I,I,16,I,20,18},
        {I,5,I,I,I,20,I,I},
        {I,I,10,I,14,18,I,I}
    };
    int near[8] {I,I,I,I,I,I,I,I};
    int t[2][6] {} ;
    int min {I} , u {} , v{} , n{7} ;

    // initial steps

    // upper triangular
    for(int i{1} ; i <=n ; i++ ){
        for(int j{i} ; j <= n ; j++){
            if(cost[i][j] < min){
                min = cost[i][j];
                u = i ;
                v = j ; 
            }
        }
    }
    // store minimum edge
    t[0][0] = u ; 
    t[1][0] = v ;
    // its included in the solution 
    near[u] = near[v] = 0 ;

    // initialize near array according minimum edge 
    for (int i{1} ; i <= n-1 ; i++ ){
        if(near[i]!=0 )
            near[i] = (cost[i][u]<cost[i][v]) ? u : v ;  
    }

    // repeatition steps 

    for (int i {1} ; i <n-1 ; i++){
        min = I ;
        int k {} ;
        // find out which one is minimum connected edge 
        for (int j {1} ; j <=n ; j++){
            if( near[j]!=0 && cost[j][near[j]]< min ){
                min = cost[j][near[j]];
                k = j ;
            }
        }
        // add the next minimum edge in the solution
        t[0][i] = k ; 
        t[1][i] = near[k] ;
        near[k] = 0 ;
        // now modify the near array to check whether other vertices near to newly added vertices 
        for(int j {} ; j<= n ; j++ ){
            if(near!=0 && cost[j][k] < cost[j][near[j]] )
                near[j] = k ;
        }
    }

    // print 
    for(int i {} ; i <n-1 ; i++){
        std::cout << t[0][i] << " - " << t[1][i] << std::endl ; 
    }
    
}

int main(){
    prims() ;
    return 0 ; 
}