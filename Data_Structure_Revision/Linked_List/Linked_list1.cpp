#include<iostream>


struct Node{
    public:
    int data; 
    Node *next ;
};

class LinkedList{
    private:
        Node *first ;
    public:
        LinkedList()
        :first{nullptr}{};
        LinkedList(int A[] , int n) ;
        ~LinkedList();
        void Display()const;
        void Insert(int index , int x) ;
        int Delete(int index) ;
        int Length()const;

};

LinkedList::LinkedList(int A[] , int n){
    Node *last {nullptr }, *temp{nullptr} ;
    first = new Node ;
    first->data = A[0] ;
    first->next = nullptr ;
    last = first ;
    
    for(int i {1} ; i < n ; i++){
        temp = new Node ;
        temp->data = A[i] ;
        temp->next = nullptr ;
        last ->next = temp ;
        last = temp ;
    } 

}

LinkedList::~LinkedList(){
    Node *last {first} ;
    while(first != nullptr){
       first = first->next ;
       delete last ;
       last = first ; 
    }
}

void LinkedList::Display()const{
    Node* temp {first} ;
    std::cout << "LinkedList : " ;
    while( temp != nullptr){
        std::cout << temp->data << " ";
        temp = temp->next ;
    }   
    std::cout << std::endl ;
}

int LinkedList::Length()const{
    int len {};
    Node *temp {first} ;
    while(temp != nullptr){
        len++;
        temp = temp->next ;
    }
}

void LinkedList::Insert(int index , int x){
    Node *temp , *node{first} ;
    temp->data = x ;
    temp ->next = nullptr ;
    if(index == 0){
        temp ->next = first ;
        first = temp ;
        return ;
    }
    
    for(int i {1} ; i < index ; i++ )
        node = node->next ;
    
    temp ->next = node->next ;
    node ->next = temp ;
    
}

int LinkedList::Delete(int index){

    Node *temp {first} ;
    Node *last {nullptr} ;
    int x {} ;
    if(index <1 || index > Length()){
        return -1;
    }
    if(index == 1 ){
        first = first->next ;
        x = temp ->data ;
        delete temp ;
        return x ;
    }
    int i {1} ;  
    while(temp != nullptr && i < index){
        last = temp ;
        temp = temp ->next ;
    }
    last ->next = temp ->next ;
    x = temp->data ;
    delete temp ;
    return x ;


}


int main(){
    int A[] ={1 , 2 ,3 ,4 ,5} ;
    LinkedList l(A , 5) ;
    l.Display();
    l.Length();

    return 0 ;
}