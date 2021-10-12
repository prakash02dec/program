#include<stdio.h>
int main()
{
char ans='y';
int pos , neg , zero , num ;
pos=neg=zero=0;
while(ans=='y' || ans=='Y')
{ 
printf("\n Enter the number \n");
scanf("%d",&num);
if(num>0) pos++;
if(num<0) neg++;
if(num==0)
zero++;
printf("\n do you want to another number (y/n) \n");
scanf(" %c",&ans);
}
printf("\n no of positive no %d", pos);
printf("\n no of negative no %d",neg); 
printf("\n no of zeros %d", zero);
return 0;
}
