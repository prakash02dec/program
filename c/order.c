#include<stdio.h>
int main()
{
int n , m , money;
char ch;
do
{
printf("\n WELCOME TO ONLINE FOOD ORDERING SERVICE. SELECT THE RESTAURANT FROM BELOW  \n 1. dominos \n 2. subway \n 3. burger king\n PRESS OPTION NO \t ");
scanf("%d",&n);
money=0;
switch(n) 
{
case 1 : printf(" \n choose where you want to eat \n DOMINOS MENU \n 1. magrietta pizza \n 2. peppy paneer pizza \n 3. farmhouse pizza \n PRESS OPTION NO \t ");
        scanf("%d",&m);
        switch(m)
        {
         case 1 : printf(" \n you have choose magreitta to eat");
         money+=90; 
         break;
         case 2 : printf("\n you have choose peppy paneer pizza to eat "); 
         money+=190; 
         break;
         case 3 : printf(" \n you have choose  farmhouse pizza to eat");
         money+=170; 
         break;
         }
         break;
case 2 : printf(" \n SUBWAY MENU \n 1. veggie dellite subway  \n 2. egg and cheese subway \n 3. paneer subway \n PRESS OPTION NO \t ");
        scanf("%d",&m);
        switch(m)
        {
         case 1 : printf(" \n you have choose veggie dellite subwya to eat");
         money+=140;
         break;
         case 2 : printf("\n you have choose egg and cheese subway to eat"); 
         money+=160;
         break;
         case 3 : printf(" \n you have choose paneers subway to eat");
         money+=210;
         break;
         }
         break;
case 3 : printf(" \n BURGER KING MENU \n 1. crispy veg burger \n 2. king egg burger \n 3. veg wooper\n PRESS OPTION NO \t");
        scanf("%d",&m);
        switch(m)
        {
         case 1 : printf(" \n you have choose crispy veg burger to eat");
         money+=60; 
         break;
         case 2 : printf("\n you have choose king egg burger to eat");
         money+=70;  
         break;
         case 3 : printf(" \n you have choose  veg wooper to eat"); 
         money+=150; 
         break;
         }
         break;
}
if(!(n>0 && n<4) || !(m>0 && m<4))
printf("\n invalid option");

printf("\n pay money %d  rupess", money);
printf("\n do you want to place another order  (y/n)");
scanf(" %c",&ch);
}
while(ch=='y' || ch== 'Y');
return 0;
}