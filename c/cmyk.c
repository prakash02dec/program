#include<stdio.h>
int main()
{
float red , green , blue , white , cyan , magenta , yellow , black ;
printf("\n enter the value of red in range 0 to 255 \n");
scanf("%f",&red);
printf("\n enter the value of green in range 0 to 255\n");
scanf("%f",&green);
printf("\n enter the value of blue in range 0 to 255\n");
scanf("%f",&blue);
if(red==0 && green==0 && blue==0)
{
white=0;
black=1;
}
else
{
white=red/255;
if(green/255>white)
white=green/255;
if(blue/255>white)
white=blue/255;
}
cyan=(white-(red/255))/white;
magenta=(white-(green/255))/white;
yellow=(white-(blue/255))/white;
black=1-white;
printf("\n white= %f \nblack= %f \ncyan= %f \nmagenta= %f \nyellow= %f ", white , black , cyan , magenta , yellow );
return 0 ;
}