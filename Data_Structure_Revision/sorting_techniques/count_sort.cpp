#include<iostream>

int Max(int A[] , int n ){
    int max {A[0]};
    for (int i {1} ; i < n ; i++){
        if(max < A[i]) max = A[i] ;
    }
    return max ;
}

void count_sort(int A[] , int n){
    int max {Max(A , n )} ;
    int *temp {new int [ max + 1 ] } ;
    
    for(int i {} ; i < max+1 ; i++ ) temp[i] = 0 ;
    
    for(int i {} ; i < n ; i++ ) temp[A[i]]++ ;

    int i { } , j {} ; 
    while(i <max+1){
        while(temp[i] >0 ){
            A[j++] = i ;
            temp[i]-- ; 
        }
        i++;
    }
    delete [] temp ;
}

int main() {
    int A[] = { 11, 13, 7 , 12 , 16 , 9 , 24 , 5 , 10 , 3 } , n = 10;
    
    for(int i {} ; i < n ; i++){
        std::cout << A[i] << " " ;
    }
    std::cout<< std::endl ;

    count_sort(A ,n) ;

    for(int i {} ; i < n ; i++){
        std::cout << A[i] << " " ;
    }
    std::cout<< std::endl ;
    return 0 ;
}