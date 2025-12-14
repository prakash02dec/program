#include <iostream>
#include <stack>
#include <cstring>

// helping function 
// function to know operand or not 
bool isOperand(char x){
    if( x=='+' || x=='-' || x=='*' || x=='/' || 
        x=='^' || x=='(' || x==')' )
        return false ;
    else 
        return true ;
}

// function to know precedence 
int inprecedence(char x){
    if( x=='+' || x=='-' )
        return 2 ;
    else if( x=='*' || x=='/' )
        return 4 ;
    else if( x== '^')
        return 5 ;
    else if( x== '(')
        return 0 ;
    
    return -1 ; // for any other thing is 0. mean if the stack is empty then its precendence is 0.
}

int outprecedence(char x){
    if( x=='+' || x=='-' )
        return 1 ;
    else if( x=='*' || x=='/' )
        return 3 ;
    else if( x=='^')
        return 6 ;
    else if( x=='(')
        return 7 ;
    else if( x==')')
        return 0 ;
    return -1; // for any other thing is 0. mean if the stack is empty then its precendence is 0.
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
            if( stk.empty() ||  outprecedence(infix[i]) > inprecedence( stk.top() ) )
                stk.push(infix[i++]) ;
            else if(outprecedence(infix[i]) == inprecedence( stk.top() )){
                // this only happen in care of '(' in stack top and  ')' is the current one
                // we simply pop out
                stk.pop();
            }
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