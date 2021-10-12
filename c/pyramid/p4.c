#include<stdio.h>
int main()
{
int i , j ,p=1 ;
for(i=0 ; i<6;i++)
{ 
for(j=6; j-i>0;j--)
printf("  ");

for(j=1;j<2*i;j++)
if(j%2==0)
{
printf("  ");
}
else
{printf(" %d",p++);}
printf("\n");
}
return 0;
}