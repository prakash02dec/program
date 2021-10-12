#include<stdio.h>
int main()
{
double p=100000, r=10, t=1; 
printf("\n population initially %lf", p);
for(t;t<=10;t++)
{
p+=0.1*p;
printf("\n population after %0.0lf year is %0.3lf",t,p);
}
return 0;
}
