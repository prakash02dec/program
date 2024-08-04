#include<iostream>

struct Node{
    Node *pre ;
    int data ; 
    Node *next ;
}*first = nullptr ;

void create(int A[] , int n){
    Node *temp {nullptr} , *last {nullptr} ;
    int i {} ;

    first = new Node ;
    first->pre = first->next = nullptr ;
    first->data = A[0] ;
    last = first ;

    for(int i{1} ; i<n ; i++){
        temp = new Node ;
        temp -> pre  = last ;
        temp->data = A[i] ;
        temp ->next = last->next ;
        last->next = temp ;
        last = temp ;
    }
}

void Display(Node *node){
    std::cout << "Circular Linked List : " ;
    while(node != nullptr){
        std::cout << node->data << " " ;
        node = node->next ;
    }
    std::cout << std::endl ;
}

int Length(Node *node){
    int len {} ;
    while(node != nullptr){
        len++ ;
        node = node->next ;
    }
    return len ;
}

void Insert(Node *node ,int index , int x){
    if(index < 0 || index >Length(node)) return ;
    Node *temp{}  ;
    temp = new Node ;
    temp->data = x ;
    if(index == 0){
        temp->pre = nullptr ;
        temp->next = first ;
        first->pre = temp ;
        first = temp ;
    }else{
        for(int i {1} ; i < index ; i++ ){
            node = node->next ;
        }
        temp ->next = node->next ;
        temp->pre = node ;
        if(node->next != nullptr)
            node->next->pre = temp ;
        node->next = temp ;
    }
}

int Delete(Node *node , int pos){
    int x {} ;
    Node *last{} ;
    if(pos == 1){
        
        last = first ;
        first = first->next ;
        
        x = last->data ;
        delete last ;

        if(first != nullptr)
            first->pre = nullptr ;
        
        return x ;  
    }else{
        
        for(int i{1} ; i< pos ; i++ ){
            last = node ;
            node = node->next ;
        }
        
        last->next = node->next ;

        if(node->next != nullptr)
            node->next->pre = last ;
        
        x = node->data ;
        delete node ;

        return x ;
            
    }
}

void Reverse(Node *node){
    Node *temp ;
    while( node != null ){
        temp = node->next ;
        node->next = node->pre ;
        node->pre = node->next ;

        node = node->pre

        if(node!= nullptr &&  node->next == nullptr)
            first = p ;

        
    }
}

int main(){
    int A[] = {10 ,20 ,30 ,40 ,50} ;
    create(A, 5) ;
    Display(first) ;
    Delete(first , 1) ;
    Display(first) ;
    return 0 ;

}