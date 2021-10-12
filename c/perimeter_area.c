#include<stdio.h>
int main()
{
float l , b , r , per , area_rec , area_cir , circum ;
printf("\n enter the length of rectangle\n");
scanf("%f",&l);
printf("\n enter the breadth of rectangle\n");
scanf("%f",&b);
printf("\n enter the radius of circle \n");
scanf("%f",&r);
per=2*(l+b);
area_rec = l*b;
circum=2*(22/7)*r;
area_cir=(22/7)*r*r;
printf("\n area of rectangle = %f \n perimeter of rectangle = %f  \n area of circle = %f \n circumferance of circle = %f", area_rec , per , area_cir , circum);
return 0 ;
} 