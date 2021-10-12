#include<stdio.h>
void fabonacci(int , int , int); 
int main()
{
int no;
printf(" enter the no of terms of fabonacci till which you want \n");
scanf("%d",&no);
printf("0 1");
fabonacci(0,1,(no-2));
return 0;
}
void fabonacci(int pre , int current , int i)
{
if(i!=0)
{
current+=pre;
pre=current;
printf(" %d",current);
fabonacci(pre , current ,--i);
}
else
return;
}
 