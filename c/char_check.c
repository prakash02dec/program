#include<stdio.h>
int main()
{
char ch , re='n' ;
do
{
printf("\n enter a character below \n");
scanf(" %c",&ch);
(ch>=97 && ch<123)? printf("\n its lower case"): printf("\n its not lower case");
(ch>=65 && ch<91) ? printf("\n its upper case"): printf("\n its not upper case");
((ch>32 && ch<48)||(ch>57 && ch<65)||(ch>90 && ch<97)||(ch>122 && ch<127)) ? printf("\n its special character") : printf("\n its not special case");

printf("\n do you want to continue (y/n) \n");
scanf(" %c",&re);
}
while((re=='y')||(re=='Y'));
return 0;
}