#include<stdio.h>

int main(void)
{
    int a[3]={1,2,3};
    for(int i=0;i<3;i++)
    {
        printf("%d",a[i]);
        printf("%d",i[a]);
        printf("%d",a+i);
        printf("%d",*(a+ i));
        printf("%d",*a);
        
        // below statement give error when you un comment it 
        // a++; 


    }
    
}