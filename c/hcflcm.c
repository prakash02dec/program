#include<stdio.h>
int main()
{
int a , b , hcf=1 , lcm ;
printf("\n enter 2 number\n");
scanf("%d %d",&a , &b);
register int i;
for(i=1; i<=a && i<=b ; i++)
{
if(a%i==0 && b%i==0)
{
hcf=i;
}
}
lcm= (a*b)/hcf;
printf("\n for %d and %d hcf and lcm will be %d and %d",a , b , hcf , lcm);
return 0;
}
