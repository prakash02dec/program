#include <iostream>

struct Node {
    int col ;
    int value ;
    Node *next ;
};

// create sparsh matrix
Node** create_sparsh(){
    int m{} , n {} ;
    std::cout << "Enter the dimension of the matrix " << std::endl ;
    std::cin >> m >> n  ;
    Node** A {} ;
    A = new Node* [m] ;
    int no_of_non_zero {};
    std::cout << "Enter the no of non zero " << std::endl ;
    std::cin >> no_of_non_zero ;
    std::cout << "Enter the coordinates with the respective elements" << std::endl ;
    std:: cout << "i  j  x" << std::endl ; 
    for (int i {} ; i < no_of_non_zero ; i++){
        int x{} , y {} , ele{};
        std::cin >> x >> y >> ele ;
        if(x > m) return nullptr ;
        Node *temp ;
        temp->value = ele ;
        temp->col = y ;
        if(A[x] == nullptr ){
            A[x] = temp ; 
        }else{
            Node *last{A[x]} ;
            while(last->next != nullptr){
                last = last->next ;
            }
            last->next = temp ;
        }

    }

    return A;

}

void Display(Node **A , int m , int n){
    Node* temp {} ;
    for(int i {} ; i<m ; i++){
        temp = A[i] ;
        for(int j {} ; j < n ; j++){
            if( j == temp->col ){
                std::cout << temp->value ;
                temp = temp->next ;
            }else{
                std::cout << "0 "  ;
            }
        }
        std::cout << std::endl ; 
    }
}

int main(){
    Node **A;
    A =create_sparsh();
}