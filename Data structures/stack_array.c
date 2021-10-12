#include<stdio.h>
#include<stdlib.h>

#define max 100

struct stack{
    int arr[max];
    int top;
};

void create(struct stack *s)
{
    s->top=-1;
}

void push(struct stack *s, int data)
{
    if(s->top==(max-1)){
        printf("\n stack is overflow");
        exit(1);
    }
    else{
        s->top++;
        s->arr[s->top]=data;
    }
}

int pop(struct stack *s )
{
    if(s->top==-1)
    {
        printf("\n stack underflow");
        exit(1);
    }
    else{
        return s->arr[s->top--];
    }
}


int isempty(struct stack *s)
{
    if(s->top==-1)
    {
        printf("\n stack empty");
        return 1;
    }
    else
    {
        printf("\n stack is not empty");
        return 0;
    }

}
int isfull(struct stack *s)
{
    if(s->top==(max-1))
    {
        printf("\n stack full");
        return 1;
    }
    else
    {
        printf("\n stack is not full");
        return 0;
    }
    
}

void print(struct stack *s)
{
    printf("\n");
    for(int i=0; i<=s->top;i++)
    {
        printf("%d  ",s->arr[i]);
    }

}

int main()
{
    struct stack x;

    create(&x);
    push(&x,36);
    push(&x,34);
    push(&x,323);
    push(&x,325);

    push(&x,78);

    push(&x,23);

    push(&x,12);
    push(&x,76);
    print(&x);
    pop(&x);

    print(&x);


    return 0 ;
    
}
