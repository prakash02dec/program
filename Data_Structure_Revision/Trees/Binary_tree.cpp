#include <iostream>
#include "Queue.hpp"
#include <stack>



Node* root {} ;

void create_tree( ){
    Node *temp {} , *parent ;
    int x ;
    Queue q{100} ;

    std::cout << "Enter the root node value" << std::endl ;
    std::cin >> x ;
    root = new Node ;
    root->data = x ;
    root->lchild = root->rchild = nullptr ;
    q.enqueue(root) ;
    // -1 value means no child;
    while(!q.isEmpty()){
        parent = q.dequeue() ;
        std::cout << "Enter the value of the left child of " << parent->data << std::endl ;
        std::cin >> x ;
        if(x != -1){
            temp = new Node ;
            temp->data = x ;
            temp->lchild = temp->rchild = nullptr ;
            parent->lchild = temp ;
            q.enqueue(temp) ;
        }
        std::cout << "Enter the value of the right child of " << parent->data << std::endl ;
        std::cin >> x ;
        if(x != -1){
            temp = new Node ;
            temp->data = x ;
            temp->lchild = temp->rchild = nullptr ;
            parent->rchild = temp ;
            q.enqueue(temp) ;
        }
    }
}

void preorder(Node* parent){
    if(parent){
        std::cout << parent->data << " " ;
        preorder(parent->lchild) ;
        preorder(parent->rchild) ;
    }

}

void inorder(Node* parent){
    if(parent){
        inorder(parent->lchild) ;
        std::cout << parent->data << " " ;
        inorder(parent->rchild) ;
    }

}

void postorder(Node* parent){
    if(parent){
        postorder(parent->lchild) ;
        postorder(parent->rchild) ;
        std::cout << parent->data << " " ;
    }

}

void Ipreorder(struct Node *parent){
    std::stack<Node*> stk{} ;
    while( parent || !stk.empty()){
        if(parent){
            std::cout << parent->data << " " ;
            stk.push(parent) ;
            parent= parent->lchild ;
        }else{
            parent = stk.top() ; 
            stk.pop() ;
            parent = parent->rchild ;
        }
    }
}

void I_inorder(struct Node *parent){
    std::stack<Node*> stk{} ;
    while( parent || !stk.empty()){
        if(parent){
            stk.push(parent) ;
            parent= parent->lchild ;
        }else{
            parent = stk.top() ; 
            stk.pop() ;
            std::cout << parent->data << " " ;
            parent = parent->rchild ;
        }
    }
}

void levelorder(Node* root){
    Queue q {100} ;
    Node *temp{root} ;
    // visit root node and push the addr
    std::cout << temp->data << " " ;
    q.enqueue(root) ;
    while(!q.isEmpty()){
        temp = q.dequeue() ;
        // visit left child  and push the addr
        if(temp->lchild){
            std::cout << temp->lchild->data << " " ;
            q.enqueue(temp->lchild) ;
        }
        // visit right child  and push the addr
        if(temp->lchild){
            std::cout << temp->rchild->data << " " ;
            q.enqueue(temp->rchild) ;
        }
    }
}

int searchInorder(int inArray[], int inStart, int inEnd, int data){
    for (int i=inStart; i<=inEnd; i++){
        if (inArray[i] == data){
            return i;
        }
    }
    return -1;
}
 
Node* generateFromTraversal(int *inorder, int *preorder, int inStart, int inEnd) {
    static int preIndex = 0;
 
    if (inStart > inEnd){
        return nullptr;
    }
 
    Node* node = new Node ;
    node->data = preorder[preIndex++] ;
 
    if (inStart == inEnd){
        return node;
    }
 
    int splitIndex = searchInorder(inorder, inStart, inEnd, node->data);
    node->lchild = generateFromTraversal(inorder, preorder, inStart, splitIndex-1);
    node->rchild = generateFromTraversal(inorder, preorder, splitIndex+1, inEnd);
 
    return node;
}

int main(){
    create_tree();

    levelorder(root) ;
    return 0 ;

}