#include <iostream>
#include <climits>
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

int max(Node *node){
    int max {INT_MIN} ;
    while(node != nullptr){
        if(node->data > max)
            max = node->data ;
            node = node->next ;
    }
    return max ;
}

// recusive version
// int R_max(Node *node){
//     int x {} ;
//     if(node == nullptr)
//         return INT_MIN ;
//     else{
//         x= max(node->next) ;
//         if(x> node->data)
//             return x ;
//         else
//             return node->data ;
//     }
// }

// refactored one 
int R_max(Node *node){
    int x {} ;
    if(node == nullptr)
        return INT_MIN ;

    x= max(node->next) ;
    return x>node->data ? x : node->data ; 
}

int main(){
    int A[]  {3,5,74,10,15} ;
    create(A , 5) ;
    Display(first) ;
    std::cout << max(first) ;

    return 0 ;
}