#include<stdio.h>
int main()
{
float cp , sp , p , l ;
printf(" \n enter the cost price of the product \n");
scanf("%f",&cp);
printf(" \n enter the selling price of the product \n ");
scanf("%f",&sp);
p= sp -cp;
l= cp- sp;
if(p>0)
printf(" \n the seller made the profit of %f\t ", p);
if(l>0)
printf(" \n the seller made the loss of %f \t" , l);
if(p==0)
printf(" \n the seller made niether loss nor profit ");
return 0 ;
} 