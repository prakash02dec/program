#include<stdio.h>
int main()
{
int no , i ;
printf("enter the nomof which you want multiplication table \n");
scanf("%d",&no);
for(i=1;i<=10;i++)
{
printf("\n %d + %d =%d",no , i ,i*no);
}
return 0;
} 
