#include<stdio.h>
#include<math.h>
int main()
{
float x , y , h , k , r ,d ;
printf("\n enter the x and y coordinates of center of circle\n");
scanf("%d %d",&x,&y);
printf("\n enter the radius of the circle\n");
scanf("%d",&r);
printf("\n enter the point to check it lie on circle or not \n");
scanf("%d %d",&h ,&k);
d=sqrt( pow(x-h,2) + pow(y-k,2) );
if(r==d)
printf("\n point lie on the circle");
else
printf("\n point doesnt lie on the cirlce");
return 0;
} 
