#include <iostream>

struct Node{
    int data ;
    Node *next ; 
};


int Max(int A[] , int n ){
    int max {A[0]};
    for (int i {1} ; i < n ; i++){
        if(max < A[i]) max = A[i] ;
    }
    return max ;
}

void Insert(Node **node , int ele){
    Node *temp{new Node} ;

    temp->data = ele ;
    temp->next = nullptr ;

    if( *node == nullptr){
        *node = temp ;
    }else{
        Node* last{*node} ;
        while(last->next != nullptr)
            last = last->next ;
        last->next = temp ;
    }
}

int Delete(Node **node ){
    int x {} ;
    if(*node != nullptr){
        Node *temp {} ;
        temp = *node ;
        
        x = temp->data ;
        
        *node = temp->next ;
        delete temp ;

        return x ;

    }
    return x ;
}

void bucket_sort(int A[] ,int n ){
    int max{Max(A, n)} ;
    Node **bins {} ;
    bins = new Node*[max+1] ;
    for(int i {} ;  i < max+1 ; i++) 
        bins[i] = nullptr ;
    for(int i {} ; i < n ; i++)
        Insert(&bins[A[i]], A[i]);
    int i{} , j{} ;
    while(i < max+1){
        while(bins[i] != nullptr){
            A[j++] = Delete(&bins[i]);
        }
        i++ ;
    }
    
}

int main() {
    int A[] = { 11, 13, 7 , 12 , 16 , 9 , 24 , 5 , 10 , 3 } , n = 10;
    
    for(int i {} ; i < n ; i++){
        std::cout << A[i] << " " ;
    }
    std::cout<< std::endl ;

    bucket_sort(A ,n) ;

    for(int i {} ; i < n ; i++){
        std::cout << A[i] << " " ;
    }
    std::cout<< std::endl ;
    return 0 ; 
}