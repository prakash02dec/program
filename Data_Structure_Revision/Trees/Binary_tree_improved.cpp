#include <iostream>

#include <queue>

struct Node{
    Node *lchild ;
    int data ;
    Node *rchild ;
};

class Tree{
    private:
       Node* root; 
    public:
    
    Tree()
    :root{nullptr} {} ;

    void create() ;

    void preorder()const{ 
        std::cout << "Preorder : " ;
        preorder(root);
        std::cout << std::endl ; 
    };
    void preorder(Node* parent)const ;

    void inorder()const{
        std::cout << "Inorder : " ;
        inorder(root); 
        std::cout << std::endl ; 
    };
    void inorder(Node* parent)const ;

    void postorder()const{
        std::cout << "Postorder : " ;
        postorder(root); 
        std::cout << std::endl ; 
    };
    void postorder(Node* parent)const ;

    void levelorder()const{ 
        levelorder(root); 
    };
    void levelorder(Node* parent)const ;

    int count()const{ 
        return count(root); 
    } ;
    int count(Node* root)const ;
    
    int height()const{ 
        return height(root); 
    } ;
    int height(Node* root)const ;
};

void Tree::create( ){
    Node *temp {} , *parent ;
    int x ;
    std::queue<Node*> q{} ;
    
    std::cout << "Enter the root node value" << std::endl ;
    std::cin >> x ;
    root = new Node ;
    root->data = x ;
    root->lchild = root->rchild = nullptr ;

    q.push(root) ;
    // -1 value means no child;
    while(q.size()){
        parent = q.front() ;
        q.pop() ;
        std::cout << "Enter the value of the left child of " << parent->data << std::endl ;
        std::cin >> x ;
        if(x != -1){
            temp = new Node ;
            temp->data = x ;
            temp->lchild = temp->rchild = nullptr ;
            parent->lchild = temp ;
            q.push(temp) ;
        }
        std::cout << "Enter the value of the right child of " << parent->data << std::endl ;
        std::cin >> x ;
        if(x != -1){
            temp = new Node ;
            temp->data = x ;
            temp->lchild = temp->rchild = nullptr ;
            parent->rchild = temp ;
            q.push(temp) ;
        }
    }
}

void Tree::preorder(Node* parent)const{
    if(parent){
        std::cout << parent->data << " " ;
        preorder(parent->lchild) ;
        preorder(parent->rchild) ;
    }

}

void Tree::inorder(Node* parent)const{
    if(parent){
        inorder(parent->lchild) ;
        std::cout << parent->data << " " ;
        inorder(parent->rchild) ;
    }

}

void Tree::postorder(Node* parent)const{
    if(parent){
        postorder(parent->lchild) ;
        postorder(parent->rchild) ;
        std::cout << parent->data << " " ;
    }

}

void Tree::levelorder(Node* root)const{
    std::queue<Node*> q {} ;
    Node *temp{root} ;
    // visit root node and push the addr
    std::cout << temp->data << " " ;
    q.push(root) ;
    while(q.size()){
        temp = q.front() ;
        q.pop();
        // visit left child  and push the addr
        if(temp->lchild){
            std::cout << temp->lchild->data << " " ;
            q.push(temp->lchild) ;
        }
        // visit right child  and push the addr
        if(temp->lchild){
            std::cout << temp->rchild->data << " " ;
            q.push(temp->rchild) ;
        }
    }
}

int Tree::height(Node* root)const{
    int x{} , y{} ;
    if(!root)
        return 0 ;
    x = height(root->lchild) ;
    y = height(root->rchild) ;
    if(x>y)
        return x+1 ;
    else
        return y+1 ;
    
}

int Tree::count(Node* root)const{
    if(!root)
        return 0 ;
    return count(root->lchild) + count(root->rchild) + 1 ;
}



int main() {
    Tree tree{} ;
    tree.create();

    tree.preorder() ;

    tree.inorder() ;
    
    tree.postorder() ;
    return 0 ;

}