#include<stdio.h>
int n;
void factors(int);
int main()
{
printf("enter the no");
scanf("%d",&n);
printf("factors of %d are ",n);
factors(n);
return 0;
}
void factors(int i)
{
 if(i==0)
{ return;}
else if(n%i==0)
{
printf("%d ",i);
}
factors(--i);
}
