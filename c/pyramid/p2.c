#include<stdio.h>
int main()
{
int i , j ;
for(i=0 ; i<6;i++)
{ 
for(j=6; j-i>0;j--)
printf("  ");

for(j=0;j<2*i-1;j++)
printf(" %d",i);
printf("\n");
}
return 0;
}