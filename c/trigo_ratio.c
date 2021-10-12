#include<stdio.h>
#include<math.h>
#define pi 3.14159265358979323846
int main()
{
double angle ;
printf(" \n enter angle in degree \n");
scanf("%lf",&angle);
angle=angle*pi/180;
printf("\n sin(%f)= %f ", angle , sin(angle) );
printf("\n cos(%f)= %f ", angle , cos(angle) );
printf("\n tan(%f)= %f ", angle , tan(angle) );
printf("\n cosec(%f)= %f ", angle , 1/sin(angle) );
printf("\n sec(%f)= %f ", angle , 1/cos(angle) );
printf("\n cot(%f)= %f ", angle , 1/tan(angle) );
return 0;
}
