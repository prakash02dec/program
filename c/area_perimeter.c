#include<stdio.h>
int main()
{
float l, b , area , perimeter ;
printf("\n enter the length of the rectangle \n");
scanf("%f",&l);
printf("\n enter the breadth of the rectange \n");
scanf("%f",&b);
area=l*b;
perimeter=2*(l+b);
if(area>perimeter)
printf("\n area is greater than perimeter of the rectangle \n");
else
printf("\n perimeter is greater than area of the rectangle \n");
return 0;
}