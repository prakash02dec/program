#include<math.h>
#include<stdio.h>
int main()
{
double x , y  ,r , angle , pi=22/7 ;
printf("\n enter x and y coodinates \n ");
scanf("%lf \n %lf",&x ,&y);
r=sqrt(x*x+y*y);
angle=atan(x/y);
angle*=180/pi;
printf(" polar coordinates are ( %lf , %lf )" , r, angle);
return 0;
}
