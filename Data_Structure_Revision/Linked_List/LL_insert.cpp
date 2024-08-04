#include <iostream>

struct Node {
    int data  ;
    Node *next {}; 
}*first = nullptr;

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
    std::cout << std::endl ;
    
}

// Insert before first node
// Inserting after given position 

// insert before first node
void push(Node *node , int x){
    Node *temp {new Node} ;
    temp->data = x ;
    temp->next = first ;
    first = temp ;
    
}

// insert node at last
void append(Node *node , int x){
    Node *last {node} ;
    while(last != nullptr && last->next != nullptr ){
        last = last->next ;
    }

    Node *temp {new Node} ;
    temp->data = x ;
    temp->next = nullptr ;    

    if(first == nullptr){
        first = last = temp ;
    }
    else{
    last->next = temp ;
    last = temp ;
    }
}

// func to insert a node at given position
void insert(Node *node , int x , int pos){
    Node *temp {new Node} ;
    temp->data = x ;
    temp->next = nullptr ;

    if(pos == 0 ){
        temp->next = first ;
        first = temp ;
        return  ;
    }
    int i {1} ;
    while(node != nullptr){
        if(i==pos){
            temp->next = node->next ;
            node->next = temp ;
            return ;
        }
        i++ ;
        node =node->next ;
    }
    std::cout << "invalid operation" ;
}

int main(){
    int A[]  {3,5,7,10,15} ;
    create(A , 5) ;
    Display(first) ;
    push(first , 2);
    Display(first);
    append(first , 9) ;
    Display(first) ;
    insert(first ,54 , 0);
    Display(first) ;
    insert(first , 33 , 3) ;
    Display(first) ;



    return 0 ;
}