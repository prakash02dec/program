#include <iostream>

void swap(int &a , int &b ){
    int temp {a} ; 
    a = b ;
    b = temp ;
}

void bubble_sort(int A[] , int n ){
    int flag{} ;
    for(int i {} ; i < n-1 ; i++){
        for(int j {} ; j < n-1-i ; j++){
            if(A[j]>A[j+1]){
                swap(A[j] , A[j+1] ) ; 
                flag = 1 ;
            }
        }
        if(flag == 0) break;
    }

}

int main (){
    int A[] = { 11, 13, 7 , 12 , 16 , 9 , 24 , 5 , 10 , 3 } , n = 10;
    
    for(int i {} ; i < n ; i++){
        std::cout << A[i] << " " ;
    }
    std::cout<< std::endl ;
    bubble_sort(A , n) ;
    for(int i {} ; i < n ; i++){
        std::cout << A[i] << " " ;
    }
    return 0 ;
}