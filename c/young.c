#include<stdio.h>
int main()
{
int ramage,shyage, ajage;
printf("\n enter the age of ram \n");
scanf("%d",&ramage);
printf(" \n enter the age of shyam \n");
scanf("%d",&shyage);
printf(" \n enter the age of ajay \n");
scanf("%d",&ajage);
if(shyage<ramage)
{
if(shyage<ajage)
printf("\n shyam is youngest among them");
else 
printf("\n ajay is youngest among them");
}
else
{
if(ramage<ajage)
printf("\n ram is youngest among them ");
else
 printf("\n ajay is youngest among them");
}
return 0;
}