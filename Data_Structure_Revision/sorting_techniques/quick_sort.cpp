#include <iostream> 

void swap(int &a , int &b ){
    int temp{a} ;
    a = b ;
    b = temp ;
}

int partition(int A[] , int l , int h ){
    int pivot{A[l]} , i {l} , j { h } ;
    while(i < j ) {
        while(A[i] <= pivot) i++ ;
        while(A[j] > pivot) j-- ;

        if(i<j){
            swap(A[i] , A[j]) ;
        }
    }

    swap(A[j] , A[l]);
    return j ;
}

void quick_sort(int A[] , int l  , int h ){
    int split {} ;
    if(l< h){
    split = partition(A, l , h ) ;
    quick_sort(A , l , split-1) ;
    quick_sort(A , split+1 , h) ;

    }
    
}



int main() {
    int A[] = { 11, 13, 7 , 12 , 16 , 9 , 24 , 5 , 10 , 3 } , n = 10;
    
    for(int i {} ; i < n ; i++){
        std::cout << A[i] << " " ;
    }
    std::cout<< std::endl ;

    quick_sort(A ,0, n-1) ;

    for(int i {} ; i < n ; i++){
        std::cout << A[i] << " " ;
    }
    std::cout<< std::endl ;


    return 0 ; 

}