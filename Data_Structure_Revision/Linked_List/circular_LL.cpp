#include <iostream>

struct Node{
    int data ;
    Node *next ;
}*head = nullptr ;

void Create(int A[] , int n ){
    Node *temp  ;

    head = new Node ;
    head->data = A[0] ;
    head->next = head ;

    Node *last {head} ;

    for(int i{1} ; i < n ; i++){
        temp = new Node ;
        temp->data = A[i] ;
        temp->next = last->next ;
        last->next = temp ;
        last = temp ;
    }

}

void Display(Node *node){

    std::cout << "Circular Linked List : " ;
    do{
        std::cout << node->data << " " ;
        node = node->next ;
    }while(node != head);

    std::cout << std::endl ;

}

void R_Display(Node *node){
    static int flag {};
    if(node != head || flag == 0){
        flag =1 ;
        std::cout << node ->data << " " ;
        R_Display(node->next) ;
    }
    flag = 0 ;
}

int Length(Node *node){
    int len {} ;
    do{
        len++ ;
        node = node->next ;
    }while(node != head);
    return len ;
}

void Insert(Node *node ,int pos , int x){
    Node *temp {nullptr} ;
    if(pos < 0 || pos > Length(node))
        return  ;

    temp = new Node ;
    temp->data = x ;
    temp->next = nullptr ;   
    if(pos == 0){

        if(head == nullptr ){
            head = temp ;
            head->next = head ;
            return ;
        }

        Node *last{head} ; 
        while(last->next != head){
            last = last->next ;
        }
        last->next = temp ;
        temp->next = head->next ;
        return ;
    }
    
    for(int i {1} ; i < pos ; i++){
        node = node->next ;
    }
    temp->next = node->next ;
    node->next = temp ;

}

int Delete(Node *node , int pos){
    int x {} ;
    if(pos < 0 || pos > Length(node)) return -1 ;
    if(pos == 1){
        Node *last{head} ;
        while(last->next != head)
            last = last->next ;
        
        x = head->data ;
        if(last==head){
            delete head ;
            head = nullptr ;
            return x ;
        }
        
        last->next = head->next ;
        
        delete head ;
        head = last->next ;

    }else{
        Node *last{node} ;
        for(int i{1} ; i < pos ; i++){
            last = node ;
            node = node->next ;
        }
        last->next = node->next ;
        x = node->data;
        delete node ;       

    }
    return x ;
}




int main(){
    int A[] = {1,2,3,4,5} ;
    Create(A , 5) ;
    // std::cout << "Circular Linked List : " ;
    Insert(head , 2,4) ;
    Delete(head , 1) ;
    Display(head) ;
    return 0 ;
}