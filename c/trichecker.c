#include<stdio.h>
int main()
{
float a1 ,a2 ,a3 ;
printf("\n enter all 3 angle of triagle which you want to check ");
scanf("%f %f %f",&a1 , &a2 ,&a3);
if(a1+a2+a3==180)
printf("\n it is a triangle");
else
printf("\n it is not a triangle");
return 0;
}