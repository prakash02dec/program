#include<stdio.h>
#include<math.h>
int main()
{
int an ,j , i=1 ,a[3] , num , sum;
printf("\nArmstrong numbers\n");
while(i<=500)
{
num=i;
sum=0;
for(j=0;j<3;j++)
{
a[j]=num%10;
num/=10;
sum+=pow(a[j],3);
}
if(sum==i)
printf("\n %d",i);

i++;
}
return 0;
}
