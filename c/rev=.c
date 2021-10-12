#include<stdio.h>
int main()
{
int i,reverse=0 , no , n ;
printf("\n enter 5 digit no \n");
scanf("%d",no);
n=no;
for(i=0,i<5,i++)
{
reverse+=n%10;
reverse*=0;
n/10;
}
if(no==reverse)
printf("\n your no is equal to its reverse\n");
else
printf("\n your no is equal to its reverse \n");
return 0;
}