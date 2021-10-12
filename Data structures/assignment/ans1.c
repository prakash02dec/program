#include<stdio.h>
#include<stdlib.h>
 

 struct node
 {
     int data;
     struct node* next;
 };

 void push(struct node** head , int new_data)
 {
     struct node* new_node=(struct node*)malloc(sizeof(struct node));
     new_node->data=new_data;
     new_node->next= *head;
     *head=new_node;
 }

 void display(struct node* Node)
{
    printf("\nLinked list is: ");
    while(Node!=NULL)
    {
        printf("  %d",Node->data);
        Node=Node->next;
    }
    printf("\n");
}
 void reverse(struct node* Node)
{
    if(Node!=NULL)
    {
        reverse(Node->next);
        printf("  %d",Node->data);
        
    }
    else return;
}

int main()
 {
    struct node* head=NULL;
    push(&head,5);
    push(&head,6);
    push(&head,12);
    push(&head,34);
    push(&head,56);
    push(&head,67);
    push(&head,98);
    push(&head,64);
    push(&head,93);
    push(&head,78);
    display(head);
    printf("\nReverse ordered Linked list is: ");
    reverse(head);

    printf("\n");
    return 0;
 }