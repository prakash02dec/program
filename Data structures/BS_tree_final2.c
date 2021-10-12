/*
// Author : Prakash Agarwal
// Roll no : 20bcs099
// Branch : CSE
// Institute : IIIT Dharwad, India
// country : India
*/

//============================================================= Header file =========================================================================================== 

#include<stdio.h>
#include<stdlib.h>

//============================================================= struture Declaration ================================================================================ 

typedef struct BS_tree{
    int data;
    struct BS_tree *left ;
    struct BS_tree *right;

}NODE;

//============================================================= Function Prototype ================================================================================ 

void create_tree(NODE **root);
void insert_node(NODE **node, int data);
NODE *search_node(NODE *node ,int data);
void inorder(NODE *node);
void preorder(NODE *node);
void postorder(NODE *node);
NODE *find_min(NODE *node);
NODE *find_max(NODE *node);
NODE *delete_node(NODE **node, int data);
void tree_menu();
void quit();

//============================================================= Function defination =============================================================================== 

void create_tree(NODE **root){
    printf("\nEnter the no of the element you want in tree : ");
    int no_of_element=0;
    scanf(" %d",&no_of_element);
    for(int i=0;i<no_of_element; i++){
        int data=0;
        printf("\nEnter the element : ");
        scanf(" %d",&data);
        insert_node(root, data);
        printf("\n%d is added in Tree",data);

    }
}

void insert_node(NODE **node, int data){
    
    if(*node == NULL){
        NODE *temp=NULL;
        temp = (NODE *)malloc(sizeof(NODE));
        temp->data = data;
        temp->left = temp-> right = NULL;
        *node=temp;
        
    }
    else if(data< (*node)->data) insert_node(&((*node)->left),data);

    else if(data > (*node)->data) insert_node(&((*node)->right),data);

}

NODE *search_node( NODE *node , int data){
    NODE *temp=node;
    if(temp == NULL) {
    return NULL;
    }
    else if(data< temp->data){
        temp=search_node(temp->left,data); 
    }
    else if(data > temp->data){
        temp=search_node(temp->right,data);
    }
    
    return temp;

}

void inorder( NODE *node){
    if(node != NULL){
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

void preorder(NODE *node){
    if(node != NULL){
    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
    }
}

void postorder( NODE *node){
    if(node != NULL){
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data);
    }
}

NODE *find_min(NODE *node){
    while (node && node->left != NULL)
        node = node->left;

    return node;
}

NODE *find_max( NODE *node){
    while (node && node->right != NULL)
        node = node->right;

    return node;
}

NODE *delete_node(NODE **node, int data){
    NODE *root=*node;
    if (*node == NULL)
        return *node;
    
    if (data < (*node)->data) (*node)->left = delete_node(&((*node)->left), data);

    else if (data > (*node)->data) (*node)->right = delete_node(&((*node)->right), data);

    else {
        // node with only one child or no child
        if ((*node)->left == NULL) {
            NODE *temp = (*node)->right;
            free(*node);
            return temp;
        }
        else if ((*node)->right == NULL) {
            NODE *temp = (*node)->left;
            free(*node);
            return temp;
        }

        // node with two children: 
        NODE* temp = find_min((*node)->right);
        (*node)->data = temp->data;
        (*node)->right = delete_node(&((*node)->right), temp->data);
    }
    root=*node;
    return root;
}

void quit(){
    printf("\nExiting...  Good Bye");
}

void tree_menu(){
    int choice;
    NODE *root = NULL;
    do{
    printf("\nMENU :\n1. CREATE tree \n2. INSERT element in tree \n3. DELETE element in tree\n4. SEARCH element in tree\n5. INORDER transveral of tree \n6. PREORDER transversal of tree \n7. POSTORDER transversal of tree \n8. MAX element in a tree \n9. MIN element in a tree \n10.Exit");
    printf("\n\nEnter your choice : ");
    scanf(" %d",&choice);
    
    switch (choice)
    {
    case 1 :
        create_tree(&root);
        break;
    case 2 :
        {
            int data=0;
            printf("\nEnter the element which you want to insert : ");
            scanf(" %d",&data);
            insert_node(&root, data);
            printf("\n%d is added in the Tree\n",data);
            
        }
        break;
    case 3 :
        {
            int data=0;
            NODE *node=NULL;
            printf("\nEnter the element which you want to delete : ");
            scanf(" %d",&data);
            node=search_node(root, data);
            
            if(node && node->data == data) root=delete_node(&root, data);
            else {
            printf("%d doesn't exist in a tree\n",data); 
            break;}
            
            printf("\n%d is deleted from the Tree\n",data);
            
        }
        break;
    case 4 :
        {
            int data=0;
            NODE *node=NULL;
            printf("\nEnter the element you want to find : ");
            scanf(" %d",&data);
            node=search_node(root, data);
            
            if(node) printf("\nThe element is found  : %d", node->data);
            else printf("\nThe TREE is EMPTY");
        }
        break;    
    case 5 :
        printf("[ ");
        inorder(root);
        printf("]");
        break;
    case 6 :
        printf("[ ");
        preorder(root);
        printf("]");
        break;
    case 7 :
        printf("[ ");
        postorder(root);
        printf("]");
        break;
    case 8 :
        {
            NODE *node=NULL;
            node=find_max(root);
            printf("\nThe max element is %d : ",node->data);
        }
        break;
    case 9 :
        {
            NODE *node=NULL;
            node=find_min(root);
            printf("\nThe min element is %d : ",node->data);
        }
        break;
    case 10 :
        quit();
        break;    

    default: 
        printf("\nINVALID option you have entered");
        break;
    }

    }while(choice!=10);
}

//============================================================= Main Function  =====================================================================================

int main(){
    tree_menu();
    printf("\n");
    return 0;
}


