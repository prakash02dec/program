#include <iostream>

struct Node {
    int data ;
    Node *next ; 
}*first=nullptr;

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

void insert_in_sorted_LL(Node *node , int x){

    Node *last {node} ;
    Node *temp {new Node}; 
    temp ->data = x ;
    temp ->next = nullptr ;
    if(first == nullptr){
        first = temp ;
        return ;
    }

    while(node != nullptr && node->data < x){
        last = node ;
        node = node->next ;
    }

    if(first == node){
        temp->next = first ;
        first = temp ;
    }else{
        temp->next = node ;
        last->next = temp ;
    }
}

int main(){
    int A[]  {3,5,7,10,15} ;
    create(A , 5) ;
    Display(first) ;
    insert_in_sorted_LL(first , 9) ;
    Display(first) ;

    return 0 ;
}