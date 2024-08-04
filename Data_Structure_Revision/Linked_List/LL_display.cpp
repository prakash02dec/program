#include <iostream>

struct Node{
    int data ;
    Node *next ; 
}*first;

void create(int A[] , int n){
    // temp to help in creating the node
    // last to keep to track of the node
    Node *temp , *last ; 
    // create new node with data and next as nullptr first and then assign the next 
    first = new Node ;
    first->data = A[0] ;
    first->next = nullptr ;
    last = first ;

    for(int i {1} ; i < n ; i++){
        temp = new Node ;
        temp->data = A[i] ;
        temp->next = nullptr ;
        last->next = temp ;
        last = temp ;
    }

}



void Display(Node *p){
    std::cout << "Linked List : " ;
    while( p!=nullptr ){
        std::cout << p->data << " " ;
        p = p->next ;
    }
    std::cout << std::endl ; 
}

// in Recursive display method
// time complexity is O(n)
// space complexity is O(n+1) 

void Recusive_Reverse_Display(Node *p){
    if(p != nullptr){
        Recusive_Reverse_Display(p->next) ;
        std::cout << p->data <<" " ;   
    }
}

int main(){
    int A[]  {3,5,7,10,15} ;
    create(A , 5) ;
    Display(first) ;
    Recusive_Reverse_Display(first);
    return 0 ;
}