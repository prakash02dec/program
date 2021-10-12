#include<stdio.h>
#include<math.h>
int main()
{
unsigned int side[3];
int i ;
for(i=0;i<3;i++)
{
printf("\n enter side %d of a triangle \n",i+1);
scanf("%d",&side[i]);
}
if((side[0]<side[1]+side[2])&&(side[1]<side[0]+side[2])&&(side[2]<side[1]+side[0]))
{
if((side[0]==side[1])&&(side[2]==side[1]))
printf("\n its equalateral triangle");
else if((side[0]==side[1])||(side[1]==side[2])||(side[2]==side[0]))
printf("\n its isoceles triangle");
else if((side[0]!=side[1])&&(side[1]!=side[2])&&(side[2]!=side[0]))
printf("\n its scalene triangle");
else if( pow(side[0],2)== pow(side[1],2) + pow(side[2],2) || pow(side[1],2)== pow(side[0],2)+ pow(side[2],2) ||  pow(side[2],2)== pow(side[1],2) + pow(side[0],2) )
printf("\n its right angle triangle");
}
else
printf("\n it is not a triangle");

return 0;
}