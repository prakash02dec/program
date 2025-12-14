#include <iostream>

struct Node {
    int data ;
    Node *next ; 
}*first;

void create(int A[] , int n){
    Node *temp {} , *last {} ; 
    first = new Node ;
    first->data = A[0] ;
    first->next = nullptr ;
    last = first ; 
    for(int i{1} ; i < n  ; i++){
        temp = new Node ;
        temp->data = A[i] ;
        temp->next = nullptr ;
        last->next = temp ;
        last = temp ;
    }

}

void Display(Node *node){
    std::cout << "Linked List : " ; 
    while(node!=nullptr){
        std::cout << node->data << " " ; 
        node = node->next ;
    }
    
}

int Count(Node *node){
    int count {} ;
    while( node != nullptr){
        count++ ;
        node = node->next ; 
    }
    return count ;
}
// recursive count
int Rcount(Node *node){
    if( node == nullptr){
        return 0 ;
    }else{
        return Rcount(node->next) + 1 ;
    }
}

int main(){
    int A[]  {3,5,7,10,15} ;
    create(A , 5) ;
    Display(first) ;
    std::cout << Count(first) ;
    return 0 ; 
}