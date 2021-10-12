#include<stdio.h>
int main()
{
int n , a[1200] , temp=0 , k=0 , i , j;
a[0]=1;
printf("enter a number\n");
scanf("%d", &n);
for(i=1;i<=n;i++)
{
for(j=0;j<=k;j++)
{
temp= a[j]*i +temp;
a[j]=temp%10;
temp/=10;
}
while(temp)
{
k++;
a[k]=temp%10;
temp/=10;
}
}
for(i=k ; i>=0 ; i--)
{
printf("%d",a[i]);
}
return 0;
}