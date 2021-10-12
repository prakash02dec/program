#include<stdio.h>
int main()
{
char ans='y';
printf("\n WELCOME TO MATCHSTICKS GAME \n RULES FOR THE GAME \n # there are 21 matchstick \n # you have to pick 1-4 matchstick only at your turn \n # who so ever pick the last matchstick will LOSE"); 
while((ans=='y' || ans=='Y'))
{
unsigned int sticks=21 , p , c ;
printf("\n NEW GAME STARTED ");
while(1)
{
printf("\n pick number of matchstick in range of 1-4 \n  ");
scanf("%d",&p);
if(p>4 || p<1)
{
printf("\n invalid selection");
continue;
}
sticks-=p;
printf(" no of matchsticks left   %d",sticks);
c=5-p;
printf("\n computer picks %d matchsticks",c);
sticks-=c;
printf("\n no of matchsticks left %d " , sticks);
if(sticks==1)
{
printf(" \n YOU LOSE ");
break;
}
}
printf("\n Do You Want To Play Again (y/n)");
scanf(" %c",&ans);
}
return 0;
}
 

