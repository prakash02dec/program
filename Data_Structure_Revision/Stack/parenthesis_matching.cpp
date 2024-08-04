#include <iostream>
#include <climits>
#include <cstring>

const int MAX_SIZE {100} ;

template< typename T>
class Stack{
    private:

    T *A ;
    int size ;
    int top ;

    public:

    Stack(int size=MAX_SIZE)
    :size{size} , top{-1} , A{std::move(new T [size])}
    {};
    ~Stack(){
        delete [] A ;
    };

    bool Push(T x) ;
    T Pop() ;
    T StackTop()const ;
    bool isEmpty()const ;
    bool isFull()const ;
    
};

template<typename T>
bool Stack<T>::Push(T x){
    if( isFull() ){
        std::cout << "stack overflow " << std::endl ;
        return false;
    }       
    top++;
    A[top] = x ;
    return true ;
}

template<typename T>
T Stack<T>::Pop(){
    if(isEmpty()){
        std::cout << "stack underflow " << std::endl ;
        return -1 ;
    }
    T x {-1} ;
    x = A[top] ;
    top-- ;
    return x ;
}

template<typename T>
T Stack<T>::StackTop()const{
    return isEmpty()? -1 : A[top] ; 
}

template<typename T>
bool Stack<T>::isEmpty()const{
    return (top == -1) ;
}

template<typename T>
bool Stack<T>::isFull()const{
    return (top == size-1);
}


bool is_balance(char* exp ){
    Stack<char> st { static_cast<int> (std::strlen(exp)) } ;
    for(int i{} ; exp[i] != '\0' ; i++){
        if(exp[i] == '(') 
            st.Push(exp[i]) ;
        else if(exp[i] == ')'){
            if( st.isEmpty() ) return false ;
            st.Pop() ;
        }

    }
    
    return st.isEmpty() ;
}

int main(){
    char A[] = "((a+b)*(c-d))" ;
    if(is_balance(A))
        std::cout << "paranthesis is balance" << std::endl ;
    else 
        std::cout << "paranthesis is not balance " << std::endl ;
    return 0 ;
}