#include<stdio.h>
int main()
{
int i , j ;
for(i=0 ; i<6;i++)
{ 
for(j=6; j-i>0;j--)
printf("  ");

for(j=1;j<2*i;j++)
printf(" %c", 64+j);
printf("\n");
}
return 0;
}