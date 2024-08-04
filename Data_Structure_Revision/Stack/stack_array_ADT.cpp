/*
STACK displine is LIFO
Data:
1. space for the storing element
2. Top pointer

Operation :
1. Push(x) 
2. Pop()
2. Peek(pos) [ looking at the value from the top position ]
3. StackTop()
4. isEmpty()
5. isFull()
*/

#include <iostream>
#include <climits>
const int MAX_SIZE {100} ;

class Stack{
    private:

    int *A ;
    int size ;
    int top ;

    public:

    Stack(int size=MAX_SIZE)
    :size{size} , top{-1} , A{std::move(new int [size])}
    {};
    ~Stack(){
        delete [] A ;
    };

    bool Push(int x) ;
    int Pop() ;
    int Peek(int pos)const ;
    int StackTop()const ;
    bool isEmpty()const ;
    bool isFull()const ;
    
};

bool Stack::Push(int x){
    if( isFull() ){
        std::cout << "stack overflow " << std::endl ;
        return false;
    }       
    top++;
    A[top] = x ;
    return true ;
}

int Stack::Pop(){
    if(isEmpty()){
        std::cout << "stack underflow " << std::endl ;
        return INT_MIN ;
    }
    int x {} ;
    x = A[top] ;
    top-- ;
    return x ;
}

int Stack::Peek(int pos)const{
    int x{-1} ;
    if((top-pos+1)<0)
        std::cout << "invalid Position " << std::endl ;
    else
        x = A[top-pos+1];
    
    return x ;
}

int Stack::StackTop()const{
    return isEmpty()? -1 : A[top] ; 
}

bool Stack::isEmpty()const{
    return (top == -1) ;
}

bool Stack::isFull()const{
    return (top == size-1);
}


int main(){
    
    Stack st{50} ;
    st.Push(10) ;
    st.Push(20) ;
    st.Push(30) ;
    st.Push(40) ;
    std::cout << st.Pop() << std::endl ;
    std::cout << st.StackTop() << std::endl ;
    std::cout << st.Peek(2) << std::endl ;
    
    return 0 ;
}