#include <iostream>
#include<cmath>
struct Term {
    int coeff {} ;
    int exp {};
    Term* next ;
}*head= nullptr ;

void Insert(Term *term){
    std::cout << "Enter the no of terms" << std::endl ;
    int n {} ;
    std::cin >> n ;

    std::cout << "Enter the coeff and exp of x respectively : " << std::endl ;  
    for(int i {} ; i < n ; i++ ){
        Term *temp{new Term } ;
        std::cin >> temp->coeff >> temp->exp ;
        temp->next = nullptr ;
        if(head != nullptr){
            head = temp ;
        }else{
            Term *last{head} ;
            while(last->next != nullptr)
                last = last->next ;
            last->next = temp;
        }
    }
}

void Display(Term *term){
    Term *temp {head} ;
    while(temp != nullptr){
        sum += temp->coeff*pow(x , temp->exp) ;
        temp= temp->next ;
    }
    return sum ;

}

void Evaluate(Term *term , int x){
    double sum {} ;
    Term *temp {head} ;
    while(temp != nullptr){
        sum += temp->coeff*pow(x , temp->exp) ;
        temp= temp->next ;
    }
    return sum ;
}

int main () {
    

    return 0 ;
}