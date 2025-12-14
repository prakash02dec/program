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


bool is_valid(auto sudoku , int i , int j , int n ,int num){
    for(int k{} ; k<n ; k++){
        if(sudoku[i][k] == num || sudoku[k][j] == num ) return false ;
    }
    int gridx {(i/3)*3} , gridy{(j/3)*3} ;

    for(int x {gridx} ; x< gridx +3 ; x++){
        for(int y {gridy} ; y < gridy+3 ; y++){
            if(sudoku[x][y] == num ) return false ;
        }
    } 

    return true ;
}




bool sudokuSolver(auto &sudoku , int i , int j ,const int n ){
    // base case 
    if(i == n){
        printSoln(sudoku , n) ;
        return true ;
    }
    
    // skip already filled number 
    if(sudoku[i][j])
        return sudokuSolver(sudoku , i+(j+1)/n, (j+1)%n , n) ;
    
    // start filling
    for(int num {1} ; num <= 9 ; num++){
        if(is_valid(sudoku , i , j , n , num)){
            sudoku[i][j] = num ;
            bool success {sudokuSolver(sudoku , i+(j+1)/n, (j+1)%n , n)} ;
            
            if(success) return true ;

        }
    }
    // no option work back tracking

    sudoku[i][j] = 0 ;
    return false ;
}

int main() {
    int n = 9;
	std::vector <std::vector<int >> sudoku {{5,3,0,0,7,0,0,0,0},
                                            {6,0,0,1,9,5,0,0,0},
                                            {0,9,8,0,0,0,0,6,0},
                                            {8,0,0,0,6,0,0,0,3},
                                            {4,0,0,8,0,3,0,0,1},
                                            {7,0,0,0,2,0,0,0,6},
                                            {0,6,0,0,0,0,2,8,0},
                                            {0,0,0,4,1,9,0,0,5},
                                            {0,0,0,0,8,0,0,7,9}};


        if(sudokuSolver(sudoku,0,0,n)){
        	std::cout<<"solution exists!";
        }
    return 0 ;
}