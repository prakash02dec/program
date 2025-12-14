#include <iostream>

void Insert_sort(int A[] , int n){
    for( int i {1} ; i < n ; i++ ){
        int j {i-1} , temp {A[i]} ;
        while( j>-1 &&temp < A[j]){
            A[j+1] = A[j] ;
            j-- ;
        }
        A[j+1] = temp ;
    }
}


int main() {    
    int A[] = { 11, 13, 7 , 12 , 16 , 9 , 24 , 5 , 10 , 3 } , n = 10;
    
    for(int i {} ; i < n ; i++){
        std::cout << A[i] << " " ;
    }
    std::cout<< std::endl ;

    Insert_sort(A , n) ;

    for(int i {} ; i < n ; i++){
        std::cout << A[i] << " " ;
    }
    std::cout<< std::endl ;



    return 0 ; 
}