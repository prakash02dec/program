#include<stdio.h>
int main()
{
int a , b ;
printf("\n enter 1st integer no \n ");
scanf("%d",&a);
printf("\n enter 2nd interger no \n ");
scanf("%d",&b);
a=a+b;
b=a-b;
a=a-b;
printf(" ist interger = %d\n 2nd interger = %d\n ",a , b );
return 0;
}