#include<stdio.h>
int main()
{
float i , x, y; 
printf("\n i \t x \t y ");
for(y=1 ;y<7; y++)
{for(x=5.5; x<=12.5; x+=0.5)
{
i= 2 + (y + 0.5*x);
printf("\n %0.2f \t %0.2f \t %0.0f ",i , x , y);
}
}
return 0;
}
