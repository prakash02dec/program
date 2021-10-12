#include<stdio.h>
int main()
{
int i,reverse=0 , no , n ;
printf("\n enter 5 digit no \n");
scanf("%d",&no);
n=no;
for(i=0;i<5;i++)
{reverse*=10;
reverse= reverse + n%10;
n=n/10;
}
printf("reverse= \t %d",reverse);
if(no==reverse)
{
    printf("\n your no is equal to its reverse\n ");
}
else
{
    printf("\n your no is not equal to its reverse \n");
}
return 0;
}