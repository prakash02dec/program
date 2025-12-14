#include <bits/stdc++.h>

void printSoln(auto soln , int n){
    for(int i{} ; i < n ; i++){
        for( int  j {} ; j<n ; j++) {
            std::cout << soln[i][j] << " ";
        }
        std::cout << std::endl ;
    }
    std::cout << std::endl ;
}

bool is_safe(auto soln , int sz , int i , int j){
    for(int k {} ; k < i ; k++){
        if(soln[k][j]){
            return false ;
        }
    }
    int n{i} , m{j} ;
    while(n>=0 && m>=0){
        if(soln[n][m]) return false ;
        n-- , m-- ;
    }
    n = i , m = j ;
    while(m<sz and n>=0){
        if(soln[n][m]) return false ;
        n-- , m++ ;
    }
    return true ;
}


// bool solveNQueensProblem(std::vector<std::vector<int>> &soln , int n , int i){
//     if(i== n){
//         printSoln(soln , n) ;
//         return true ;
//     }

//     for(int j {} ; j < n ; j ++){
//         if(is_safe(soln , n , i , j)){
//             soln[i][j] = 1 ;
//             bool subproblem {solveNQueensProblem(soln , n , i+1 )} ;
//             if(subproblem){
//                 return true ;
//             }
//             soln[i][j] = 0 ;
//         }
//     }
//     return false ;
// }

int solveNQueensProblem(std::vector<std::vector<int>> &soln , int n , int i){
    if(i== n){
        printSoln(soln , n) ;
        return 1 ;
    }
    int total {} ;
    for(int j {} ; j < n ; j ++){
        if(is_safe(soln , n , i , j)){
            soln[i][j] = 1 ;
            total += solveNQueensProblem(soln , n , i+1 );
            soln[i][j] = 0 ;
        }
    }
    return total ;
}

int main() {
    int n {} ;
    std::cout << "Enter n" << std::endl ;
    std::cin >> n ;
    std::vector<std::vector<int>> soln (n , std::vector<int> (n , 0)) ;
    std::cout << "Total : " << solveNQueensProblem(soln  , n, 0) ;
    return 0 ;
}