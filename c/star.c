#include<stdio.h>
int main()
{
int i , j ,p=0 ;
for(i=0 ; i<10;i++)
{ 
for(j=10; j-i>0;j--)
{
if(i>=2 && i<=5 && j<=(7-p))
{
printf(" * *");
}
else
printf("  ");
}
if(i>=2 && i<=5)
p++;
for(j=0; j<=(2*i);j++)
printf(" *");

printf("\n");
}
for(i=8 ; i<10;i++)
{
for(j=0; j<=i;j++)
{
printf("  ");}
if(i==8)
{
for(j=3;j>0;j--)
printf(" *");
}
else
printf(" *"); 
printf("\n");
}
return 0;
}
