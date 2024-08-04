#include <iostream>

struct Node {
    int data ;
    Node *next ; 
};

Node* Linear_search(Node *node , int key){
    while(node != nullptr){
        if( node->data == key ){
            return node ;
        }
        node = node->next ;
    }
    return nullptr ;
}

void insert_in_sorted_LL(Node **node , int x){

    Node *last {*node} ;
    Node *iterator{*node} ;
    Node *temp {new Node}; 
    temp ->data = x ;
    temp ->next = nullptr ;
    if(*node == nullptr){
        *node = temp ;
        return ;
    }

    while(iterator != nullptr && iterator->data < x){
        last = iterator ;
        iterator = iterator->next ;
    }

    if(iterator == *node){
        temp->next = iterator ;
        iterator = temp ;
    }else{
        temp->next = iterator ;
        last->next = temp ;
    }
}

int hash(int key){
    return key%10 ;
}

void Insert(Node *H[] , int key){
    int index {hash(key)} ;
    insert_in_sorted_LL(&H[index] , key);

}

int main(){
    Node *HT[10] {};
    Insert(HT,12) ;
    Insert(HT , 22) ;
    Insert(HT , 42) ;
    Node *temp{Linear_search(HT[hash(22)] , 22)} ;    
    if(temp){
        std::cout << "Data found :" << temp->data ;
    }
    return 0 ;
}