#include <iostream>
#include <climits>

struct Node{
    int data ;
    Node *next ;
};

class Stack{
    
    private :
    Node *top ;
    
    public :
    
    Stack()
    :top{nullptr} {} ;
    ~Stack(){} ;

    bool Push(int x);
    int Pop();
    int Peek(int pos)const ;
    int StackTop()const ;

    bool isEmpty()const ;
    bool isFull()const ;

    friend std::ostream& operator<<(std::ostream &os , const Stack &st); 
};

std::ostream& operator<<(std::ostream &os , const Stack &st){
    Node *temp {st.top} ;
    while(temp != nullptr){
        std::cout << temp->data << " " ;
        temp= temp->next ;
    }
    std::cout << std::endl ;
    return os ;
}

bool Stack::Push(int x){
    Node *temp {new Node} ;
    if(temp == nullptr){
        std::cout << "Stack overflowed " << std::endl ;
        return false ;
    }
        
    temp->data = x ; 
    temp->next = top ;
    top = temp ;

    return true ;
}

int Stack::Pop(){
    int x {} ;
    if(isEmpty()){
        std::cout << "stack is underflow" << std::endl ;
        return -1 ; 
    }

    Node *temp {} ;
    temp = top ;
    top = top->next ;
    x = temp->data ;
    delete temp ;
    return x ;
}

bool Stack::isEmpty()const {
    if(top == nullptr)
        return true ;
    return false ;
}

bool Stack::isFull()const{
    Node *temp{new Node } ;
    if(temp == nullptr){
        return true ;
    }else{
        delete temp ;
        return false; 
    }
}

int Stack::Peek(int pos)const{
    Node *temp{top} ;
    

    while(temp != nullptr && pos-1 ){
        temp = temp->next ;
        pos--;
    }
    if(temp == nullptr)
        return -1 ;
    return temp->data ; 
}

int Stack::StackTop()const{
    if(top == nullptr){
        std::cout<< "stack underflow" << std::endl ;
        return INT_MIN ;
    }
    return top->data ;

}

int main(){
    
    Stack st{} ;
    st.Push(10) ;
    st.Push(20) ;
    st.Push(30) ;
    st.Push(40) ;
    std::cout << st.Pop() << std::endl ;
    std::cout << st.StackTop() << std::endl ;
    std::cout << st.Peek(2) << std::endl ;
    std::cout << st ;    
    return 0 ;
}