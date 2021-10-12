#include<stdio.h>
int main()
{
long int n , no , sum=0 ;
printf(" enter 5 digit no \n ");
scanf("%d",&no);
n=no;
sum+=n%10;
n/=10;
sum+=n%10;
n/=10;
sum+=n%10;
n/=10;
sum+=n%10;
n/=10;
sum+=n%10;
printf(" \n sum of digit number of %d = %d", no ,sum);
return 0;
}
