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
     std::cout << std::endl ;
}

int Count(Node *node){
    int count {} ;
    while( node != nullptr){
        count++ ;
        node = node->next ; 
    }
    return count ;
}

int Delete(Node *node , int pos){
    int x ;
    if(pos >Count(node) && pos < 1)
        return -1 ;

    if(pos == 1){
        x = node->data ;
        first = node->next ;
        delete node ;
    }else{
        int i {1} ;
        Node* last {nullptr} ; 
        while(node != nullptr && i<pos ){
            last = node ;
            node = node->next ;
            i++;
        }
        if(i == pos && node != nullptr){
            last->next = node->next ;
            x = node->data ;
            delete node ;
        }

    }
    return x ;
}

int main(){
    int A[]  {3,5,7,10,15} ;
    create(A , 5) ;
    Delete(first ,3);
    Display(first) ;

    return 0 ;
}