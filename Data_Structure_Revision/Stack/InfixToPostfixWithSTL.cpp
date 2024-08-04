#include <iostream>
#include <stack>
#include <cstring>

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
    std::stack<char> stk ;

    char* postfix = new char[std::strlen(infix)+1] ;
    int i{} , j{} ;

    while( infix[i] != '\0' ){
        if(isOperand(infix[i])){
            postfix[j++] =infix[i++] ;
            
        }else{
            if( stk.empty() ||  pre(infix[i]) > pre( stk.top() ) )
                stk.push(infix[i++]) ;
            else{
                postfix[j++] = stk.top() ;
                stk.pop();
            }

                
        }
    }

    while(!stk.empty()){
        postfix[j++] = stk.top() ;
        stk.pop() ;
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