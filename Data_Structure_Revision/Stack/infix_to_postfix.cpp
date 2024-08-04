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


// helping function 
// function to know operand or not 
bool isOperand(char x){
    if( x=='+' || x=='-' || x=='*' || x=='/' )
        return false ;
    else 
        return true ;
}

// function to know precedence 
int pre(char x){
    if( x=='+' || x=='-' )
        return 1 ;
    else if( x=='*' || x=='/' )
        return 2 ;
    return 0 ; // for any other thing is 0. mean if the stack is empty then its precendence is 0.
}

char* infix_to_post(char* infix){
    // stack intilize
    Stack<char> st{static_cast<int> (std::strlen(infix))} ;

    char* postfix = new char[std::strlen(infix)+1] ;
    int i{} , j{} ;

    while( infix[i] != '\0' ){
        if(isOperand(infix[i])){
            postfix[j++] =infix[i++] ;
            
        }else{
            if( pre(infix[i]) > pre( st.StackTop() ) )
                st.Push(infix[i++]) ;
            else
                postfix[j++] = st.Pop();
        }
    }

    while(!st.isEmpty()){
        postfix[j++] = st.Pop() ;
    }
    postfix[j] = '\0' ;

    return postfix ;

}

int main(){
    char infix[] = "a+b*c-d/e" ;
    char *postfix = infix_to_post(infix) ;
    std::cout << postfix ;
    return 0 ;
}