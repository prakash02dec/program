#include<stdio.h>
int main()
{
float hd , co , ts ;
int grade=5 ;
printf("\n TO DETERMINE THE GRADE OF STEAL");
printf("\n enter the value of hardness\n");
scanf("%f",&hd);
printf("\n enter the value of carbon content\n ");
scanf("%f",&co);
printf("\n enter the value of tensile strength\n");
scanf("%f",&ts);
if(hd>50 && co<0.7 && ts>5600)
grade=10;
else if(hd>50 && co<0.7 && !(ts>5600))
grade=9;
else if(!(hd>50) && co<0.7 && ts>5600)
grade=8;
else if(hd>50 && !(co<0.7) && ts>5600)
grade=7;
else if(hd>50 || co<0.7 || ts>5600)
grade=6;
printf("\n GRADE OF STEEL IS   %d",grade);
return 0;
} 