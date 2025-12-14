#include <iostream>
#include <climits>
#include <cstring>

template <typename T>
struct Node{
    T data ;
    Node<T> *next ;
};

template <typename T>
class Stack{
    
    private :
    Node<T> *top ;
    
    public :
    
    Stack()
    :top{nullptr} {} ;
    ~Stack(){} ;

    bool Push(T x);
    T Pop();
    T Peek(T pos)const ;
    T StackTop()const ;

    bool isEmpty()const ;
    bool isFull()const ;

    template< typename U>
    friend std::ostream& operator<<(std::ostream &os , const Stack<U> &st); 
};

template <typename U>
std::ostream& operator<<(std::ostream &os , const Stack<U> &st){
    Node<U> *temp {st.top} ;
    while(temp != nullptr){
        std::cout << temp->data << " " ;
        temp= temp->next ;
    }
    std::cout << std::endl ;
    return os ;
}

template <typename T>
bool Stack<T>::Push(T x){
    Node<T> *temp {new Node<T>} ;
    if(temp == nullptr){
        std::cout << "Stack overflowed " << std::endl ;
        return false ;
    }
        
    temp->data = x ; 
    temp->next = top ;
    top = temp ;

    return true ;
}

template <typename T>
T Stack<T>::Pop(){
    T x {} ;
    if(isEmpty()){
        std::cout << "stack is underflow" << std::endl ;
        return -1 ; 
    }

    Node<T> *temp {} ;
    temp = top ;
    top = top->next ;
    x = temp->data ;
    delete temp ;
    return x ;
}

template <typename T>
bool Stack<T>::isEmpty()const {
    if(top == nullptr)
        return true ;
    return false ;
}

template <typename T>
bool Stack<T>::isFull()const{
    Node<T> *temp{new Node<T> } ;
    if(temp == nullptr){
        return true ;
    }else{
        delete temp ;
        return false; 
    }
}

template <typename T>
T Stack<T>::Peek(T pos)const{
    Node<T> *temp{top} ;
    

    while(temp != nullptr && pos-1 ){
        temp = temp->next ;
        pos--;
    }
    if(temp == nullptr)
        return -1 ;
    return temp->data ; 
}

template <typename T>
T Stack<T>::StackTop()const{
    if(top == nullptr){
        std::cout<< "stack underflow" << std::endl ;
        return -1 ;
    }
    return top->data ;

}


bool is_balance(char* exp ){
    Stack<char> st {} ;
    for(int i{} ; exp[i] != '\0' ; i++){
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[') 
            st.Push(exp[i]) ;
        else{ 
            if(st.StackTop() == '(' && exp[i] == ')'){
                if( st.isEmpty() ) return false ; 
                st.Pop() ;
            }else if(st.StackTop() == '{' && exp[i] == '}'){
                if( st.isEmpty() ) return false ; 
                st.Pop() ;
            }else if(st.StackTop() == '[' && exp[i] == ']'){
                if( st.isEmpty() ) return false ; 
                st.Pop() ;
            }

        }

    }
    
    return st.isEmpty() ;
}

int main(){
    char A[] = "{((a+b)*[(c-d)])}" ;
    if(is_balance(A))
        std::cout << "paranthesis is balance" << std::endl ;
    else 
        std::cout << "paranthesis is not balance " << std::endl ;
    return 0 ;
}