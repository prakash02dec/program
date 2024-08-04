#include <iostream>

void merge(int A[] , int low  , int mid , int high){
    int i {low } , j {mid+1} ,k{low} , B[high+1] ;
    while(i<=mid && j<= high){
        if(A[i]<A[j]){
            B[k++] = A[i++] ;
        }else
            B[k++] = A[j++] ;
    }

    while(i<= mid) B[k++] = A[i++] ;
    while(j<= high) B[k++] = A[j++] ;

    for(i = low ; i <= high ; i++) A[i] = B[i] ;

}

// 2-way merge sort
void IMergeSort(int A[] , int n){
    int p {} ; 
    for(p = 2 ; p <= n ; p = p*2){
        for(int i {} ; i+p-1 < n ; i = i+p){
            int low{i} , high {i+p-1} , mid {(low+high)/2} ;
            merge(A, low , mid , high) ;
        }
    }
    if(p/2 < n )
        merge(A , 0 , p/2-1 , n-1) ;
}

void mergesort(int A[] , int low , int high ){
    if(low< high){
        int mid  {low + (high-low)/2} ;

        mergesort(A, low , mid ) ;
        mergesort(A , mid+1 , high) ;
        merge(A , low , mid , high) ;
    }
}

int main(){
    int A[] = { 11, 13, 7 , 12 , 16 , 9 , 24 , 5 , 10 , 3 } , n = 10;
    
    for(int i {} ; i < n ; i++){
        std::cout << A[i] << " " ;
    }
    std::cout<< std::endl ;

    // IMergeSort(A , n) ;
    mergesort(A , 0 , n-1) ;

    for(int i {} ; i < n ; i++){
        std::cout << A[i] << " " ;
    }
    std::cout<< std::endl ;

    return 0 ;
}