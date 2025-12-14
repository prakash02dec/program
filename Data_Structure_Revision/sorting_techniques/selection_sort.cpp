#include <iostream> 

void swap(int &a , int &b ){
    int temp{a} ; 
    a= b ;
    b = temp ;
}

void SelectionSort (int A[] , int n) {
    for(int i {} ; i < n-1 ; i++){
        int k {i} ;
        for(int j{i} ; j<n ; j++){
            if(A[j] < A[k])
                k = j ;
        }
        swap(A[k] , A[i]);
    }
}

int main() {

    int A[] = { 11, 13, 7 , 12 , 16 , 9 , 24 , 5 , 10 , 3 } , n = 10;
    
    for(int i {} ; i < n ; i++){
        std::cout << A[i] << " " ;
    }
    std::cout<< std::endl ;

    SelectionSort(A , n) ;

    for(int i {} ; i < n ; i++){
        std::cout << A[i] << " " ;
    }
    std::cout<< std::endl ;

    return 0 ;
}