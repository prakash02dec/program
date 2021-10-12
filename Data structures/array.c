#include<stdio.h>
#include<stdlib.h>

void array_insert();
void array_display();
void array_create();
void array_delete();


int size , *array;

int main(void)
{
    char response;
    do
    {
        printf("\nMENU\na.\tcreating an array of n size\nb.\tdisplay array with suitable heading\nc.\tinsert the element on i th index\nd.\tdelete the elememt from i th index ");
        printf("\ne.\texit\nENTER THE RESPONSE BELOW\n");
        scanf(" %c",&response);

        switch (response)
        {
        case 'A':
        case 'a': array_create();
                break;  
        
        case 'B':
        case 'b':array_display();
                break;
        case 'C':
        case 'c':
                array_insert();
                break;
        case 'D':
        case 'd':
                array_delete();
                break;
        case 'E':
        case 'e':
                exit(0);
                break;
        
        default:
                printf("wrong option entered");
                break;
        }
        
        printf("\n\n\n");
    }while (response!='e' || response!='E');

    return 0;
    
}

void array_create()
{
        printf("enter the size of array");
        scanf("%d",&size);
        array=(int*)malloc(sizeof(int)*size);
        printf("\nenter the element in array \n ");
        register int i ;
        for(i=0;i<size;i++)
        {
                scanf("%d",&array[i]);
        }

        
}
 void array_display()
 {
        printf("the element in array is \n ");
        register int i ;
        for(i=0;i<size;i++)
        {
                printf("%d",array[i]);
        }
   
 }

 void array_insert()
 {
    printf("element which you want to insert");
    int element , position ;
    scanf("%d",&element);
 
    printf("position at which element is to be inserted");
    scanf("%d",&position);
    
    size++;

    array=(int*)realloc(array,size);
    
    register int i;

    for (i = size-1; i >= position; i--)
    { 
        array[i] = array[i - 1];
    }
    
    array[position ] = element;
 
    printf("updated array");
    for (i = 0; i < size; i++)
    {
        
        printf("%d ", array[i]);
    }
 }

 void array_delete()
 {
    printf("element which you want to deleted");
    int element , position ;
    scanf("%d",&element);
 
    printf("position from which element is to be deleted");
    scanf("%d",&position);
    
    
    
    if(array[position]==element)
    
    {
        register int i;

        for (i =position ; i<size-1; i++)
        { 
                array[i] = array[i+1];
        }
        
        size--;

        array=(int*)realloc(array,size);

 
    printf("updated array");
    for (i = 0; i < size; i++)
    {
        
        printf("%d ", array[i]);
    }
    }
    else{
            printf("given element at given position is invalid ");
    }
 }