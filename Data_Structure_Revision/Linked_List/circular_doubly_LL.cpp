#include <iostream>

struct Node{
    Node *prev ;
    Node data ;
    Node *next ;
}*head = nullptr ;

void Display(Node *node){
    do{
        std::cout << node->data << std::endl ;
        node = node->next ;
    }while(node != head);

}

int Length(Node *node){
    int len{} ;
    do{
        len++ ;
    }while(node != head);

    return len ;
}

void Insert(Node *node, int index , int x){
    Node *temp{} ;
    if( index < 0 && index > length(node)) return ; 
    temp = new Node ;
    temp->data = x ;
    temp->next = temp->prev = nullptr ;
    if(index == 0){
        temp ->prev = head->prev ;
        temp ->next = head->next ;
        head->pre->next = temp ;
        head->pre = temp ;

    }else{
        for(int i{1} ; i<pos ; i++ ){
            node= node->next ;
        }

        temp->next = node->next ;
        temp->prev = node ;
        node->next->prev = temp ;
        node->next = temp ;
    }
}

int Delete(Node *node, int pos ){
    Node *last{};
    int x {} ;
    if( pos < 1 && pos > length(node)) return -1; 

    if( pos == 1 ){
        last = head ;
        head = head->next ;
        head->prev = last->prev ;
        last->pre->next = head;
        x = last->data ;
        delete last ;
        return x ;

    }else{
        for(int i{1} ; i<pos ; i++ ){
            last = node ;
            node = node->next ;
        }

        last->next = node->next ;
        node->next->prev = last ;
        x = node->data; 
        delete node ;
        return x ;
    }
}


int main(){

    return 0 ;
}