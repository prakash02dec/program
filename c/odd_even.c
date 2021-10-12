#include<stdio.h>
int evenodd(int n)
{
if(n%2==0)
printf("\n its  even");
else 
printf("\n its  odd");
}
int main()
{
char ans='y';
do
{
int no , result;
printf("enter no \n");
scanf("%d",&no);
evenodd(no);
scanf(" %c",&ans);
}
while(ans=='Y' || ans=='y' );
return 0;
}