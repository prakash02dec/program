#include<stdio.h>
#include<math.h>
#define pi 3.14159265358979323846
int main()
{
double l1 , l2 , g1=0, g2, dis ;
printf(" \n enter the latitude and longitude of place 1 respectively \n");
scanf("%lf %lf",&l1 ,&g1 );
printf("enter the latitude and longitude of place 2 respectively \n ");
scanf("%lf %lf",&l2 ,&g2 );
l1*=pi/180;
l2*=pi/180;
g1*=pi/180;
g2*=pi/180;
dis=3963*acos(sin(l1) *sin(l2) + cos(l1)*cos(l2)*cos(g2-g1));
printf(" \n nuatical miles between two places is    %lf ", dis);
return 0 ;
}