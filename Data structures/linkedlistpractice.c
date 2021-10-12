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

 void append(struct node** head , int new_data)
 {
     struct node* new_node=(struct node *)malloc(sizeof(struct node)) ;
     struct node *last;
     last=*head;
     new_node->data=new_data;
     new_node->next=NULL;
     
     if(*head==NULL)
     {
         *head= new_node;
         return;
     }

     while(last->next!=NULL)
     last=last->next;

     last->next=new_node;
     return;


 }

void insert_after_node(struct node* prev_node , int new_data )
{
    
    if(prev_node==NULL)
    {
        printf("previous can not be null");
        return;
    }
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=new_data;
    new_node->next=prev_node->next;
    prev_node->next=new_node;
}

void insert_after_element(struct node** head , int new_data ,int prev_data )
{
    
    if(*head==NULL)
    {
        printf("list is empty ");
        return;
    }
    struct node* new_node=(struct node*)malloc(sizeof(struct node)),*prev_node;

    prev_node=*head;
    
    while(prev_node->data!=prev_data)
    prev_node=prev_node->next;
    if(prev_node->data==prev_data)
    {
        new_node->data=new_data;
        new_node->next=prev_node->next;
        prev_node->next=new_node;
        return;
    }
    else
    printf("element doesnt exits");
}

void delete_by_element(struct node** head , int rem_data)
{
    struct node *temp=*head , *prev;

    if(temp!=NULL && temp->data==rem_data)
    {
        *head=temp->next;
        free(temp);
        return;
    }

    while(temp!=NULL && temp->data!=rem_data)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)
    return;
    prev->next=temp->next;
    free(temp);
}

void delete_by_position(struct node** head, int position)
{
    struct node *temp,*prev;
    temp=*head;

    if(temp==NULL)
    return;

    if(position==0)
    {
        *head=temp->next;
        free(temp);
        return;

    }

    while(position-- && temp!=NULL)
    {
        prev=temp;
        temp=temp->next;    
    }
    if(temp==NULL)
    return;

    prev->next=temp->next;
    free(temp);


}
 
void print_node(struct node* Node)
{
    printf("\n Created Linked list is: ");
    while(Node!=NULL)
    {
        printf("  %d",Node->data);
        Node=Node->next;
    }
    printf("\n");
}
 

 int main()
 {
     struct node* head=NULL;
     char ch;
    //  do{
    //         int choice=7,no;
    //         printf("\tMENU\n\t1. push\n\t 2. append \n\t3. insert after node \n\t4. insert after element \n\t5. delete by element \n\t6. delete by position \n\t7. print list \n\t 8. exit\n");
    //         scanf("%d",&choice);
    //         switch(choice)
    //         {
    //              case 1:
    //              printf("\nenter element");
    //              scanf("%d",&no);
    //              push(&head,no);
    //              break; 
    //              case 2:
    //              printf("\nenter element");
    //              scanf("%d",&no);
    //              append(&head,no);
    //              break; 
    //              case 3:
    //              printf("\nenter element");
    //              scanf("%d",&no);
    //              insert_after_node(&head,no);
    //              break; 
    //              case 4:
    //              printf("\nenter element");
    //              scanf("%d",&no);
    //              insert_after_element(&head,no);
    //              break; 
    //              case 5:
    //              printf("\nenter element");
    //              scanf("%d",&no);
    //              delete_by_element(&head,no);
    //              break; 
    //              case 6:
    //              printf("\nenter element");
    //              scanf("%d",&no);
    //              delete_by_position(&head,no);
    //              break; 
    //              case 7:print_node(head);
    //              break; 
    //              case 8:exit(0); break;
    //              default : printf("\t wrong choice.\n");
    //         }
    //         printf("do you want to continue")
    //         scanf(" %c",&ch);

    //     }while(ch=='y'||ch=='Y')
    // append(&head,8);
    push(&head,5);
    push(&head,6);
    append(&head,8);
    append(&head,2);
    insert_after_node(head->next->next,9);
    insert_after_element(&head, 1,8);
    print_node(head);
    delete_by_element(&head,5);
    delete_by_position(&head,2);
    print_node(head);
    return 0;
 }