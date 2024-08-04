#include <iostream>

void swap(int &a , int &b ){
    int temp {a};
    a = b ;
    b = temp ;
}

void Insert( int H[] , int n){
    int i{n} , temp {} ;
    temp = H[i] ;

    while( i > 0 && temp > H[i/2] ){
        H[i] = H[i/2] ;
        i = i/2 ;
    }
    H[i] = temp ;

}

void create_heap(int H[] , int n ){
    for(int i {1} ; i < n ; i++){
        Insert(H , i ) ;
    }
}

void heapify(int H[] , int n ){
    for(int i {n-1} ; i >=0 ; i-- ){
        int j {2*i + 1} ;
        while(j<n ){
            if(H[j] < H[j+1]) j++ ;

            if( H[i] < H[j] )
                swap( H[i] , H[j] ) ;
            else 
                break;
            
            i = j ;
            j = 2*i +1 ;

        }
    }
        
}

int Delete(int H[] , int n){
    int i {} , j {} , x{} ;
    x = H[i] ;
    H[i] = H[n-1] ;
    j = 2*i + 1 ;
    while( j<n-1 ){
        if(H[j] < H[j+1])
            j++ ;
        if(H[i] < H[j] ){
            swap(H[i] , H[j] ) ;
        } else 
            break ;
        
        i = j ;
        j = 2*i +1 ;
    }
    H[n-1] = x ; 
    return x ; 
}

void heap_sort(int H[] , int n) {
    // create_heap(H , n ) ;
    heapify(H , n) ;
    for(int i {n} ; i > 0  ; i--){
        Delete( H , i ) ;
    }
}

void Heapify(int A[], int n){
    // # of leaf elements: (n+1)/2, index of last leaf element's parent = (n/2)-1
    for (int i=(n/2)-1; i>=0; i--){
 
        int j = 2 * i + 1;  // Left child for current i
 
        while(j < n-1){
            // Compare left and right children of current i
            if (A[j] < A[j+1]){
                j = j+1;
            }
 
            // Compare parent and largest child
            if (A[i] < A[j]){
                swap(A, i, j);
                i = j;
                j = 2 * i + 1;
            } else {
                break;
            }
        }
    }
}



int main(){
    int H[] = { 10, 20, 30 , 25 , 45, 40 , 35 };
    heap_sort(H , 7) ;
    // create_heap(H , 7) ;
    // heapify(H , 7) ;
    for (int i {} ; i < 7 ; i++ ){
        std::cout << H[i] << " " ; 
    }

    return 0 ;
}