#include<stdio.h>
#include<math.h>
#define pi 3.1415926535
int main()
{
float a , angle ;
printf(" enter angle in degree \n");
scanf("%f",&a);
angle=a;
a*=pi/180;
if(pow(sin(a),2)+pow(cos(a),2)==1)
printf("sum of sq of sin %f and cos %f = %f",angle , angle ,pow(sin(a),2)+pow(cos(a),2));
return 0;
}