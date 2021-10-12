#include<stdio.h>
#include<stdlib.h>

struct stack{
    int data;
    struct stack *next;
};

void push(struct stack **top , int element )
{
    struct stack* new_node=(struct stack*)malloc(sizeof(struct stack));
    new_node->data=element;
    new_node->next=*top;
    *top=new_node; 
}
int pop(struct stack **top)
{
    struct stack *temp=*top ;
    int pop_data=temp->data;

    *top=temp->next;
     free(temp);
     return pop_data;

}

void print(struct stack *top )
{

    printf("\n");
    while(top!=NULL)
    {
        printf("%d  ",top->data);
        top=top->next;
    }
}

int main()
{
    struct stack *top=NULL;
    push(&top,36);
    push(&top,34);
    push(&top,323);
    push(&top,325);

    push(&top,78);

    push(&top,23);

    push(&top,12);
    push(&top,76);
    print(top);
    pop(&top);

    print(top);

}