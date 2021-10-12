#include<stdio.h>
#include<math.h>
int main()
{
float wcf , v , t ;
printf(" \n enter temperature in fahrenhiet \n");
scanf("%f",&t);
printf(" \n enter velocity in mph \n");
scanf("%f",&v);
wcf= 35.74 + 0.6215*t + (0.4275*t-35.75)*pow(v,0.16);
printf("\n wind cill factor is\t %f",wcf);
return 0;
}