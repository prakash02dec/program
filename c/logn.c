#include<stdio.h>
#include<math.h>
int main()
{
double x , sum ;
printf(" enteR  no ");
scanf("%lf",&x);
sum=(x-1)/x;
int i;
for(i=2;i<=7;i++)
{
sum+=0.5*pow(((x-1)/x),i);
}
printf("natural log = %lf ", sum);
return 0;
}
