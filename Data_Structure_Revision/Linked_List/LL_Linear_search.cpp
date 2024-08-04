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

Node* Linear_search(Node *node , int key){
    while(node != nullptr){
        if( node->data == key ){
            return node ;
        }
        node = node->next ;
    }
    return nullptr ;
}

// Recursive 
Node* RLinear_search(Node *node , int key){
    if(node == nullptr)
        return nullptr ;
    if(node->data == key)
        return node ;
    else
        return RLinear_search(node->next , key) ;
}

Node* Linear_searchI(Node *node , int key){
    Node *last {nullptr} ;
    while(node != nullptr){
        if(node->data == key){
            last->next = node->next ;
            node->next = first ;
            first = node ;
        }
        last = node ; 
        node = node->next ;
    }
}


int main(){
    int A[]  {3,5,7,10,15} ;
    create(A , 5) ;
    Display(first) ;

    return 0 ;
}