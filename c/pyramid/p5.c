#include<stdio.h>
int main()
{
int i , j ,p;
for(i=0 ; i<6;i++)
{ 
for(j=6; j-i>0;j--)
printf("  ");
p=0;
for(j=1;j<2*i;j++)
if(j<=i)
printf(" %d",j);
else 
{p+=2;
printf(" %d",j-p);
}
printf("\n");
}
return 0;
}