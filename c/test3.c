#include<stdio.h>
#include<string.h>
void final(char msg[40],int choice);
int triangle_maker(char symbol,char msg[40]);
int square_maker(char symbol,char msg[40]);
int rectangle_maker(char symbol,char msg[40]);
int choose_shape();
int main()
{
   int choice;
   char message[40];
   printf("\nPlease enter your message: ");
   scanf("%s",&message);
   choice=choose_shape();
   final(message,choice);
   return 0;
}
int triangle_maker(char symbol,char msg[40])
{
   int n,i,j;

   n = strlen(msg);
   for(i = 1; i <= n; i++) {
      
         for(j = 1; j <= n-i; j++)
            printf(" ");
        if(i != n/2)
        {
         for(j = 1; j <= i; j++)
            printf("%c ",symbol);

         
      }
      else
      {
         printf("%s",msg);
      }   
      printf("\n");
   }
   return 1;
}
int rectangle_maker(char symbol,char msg[40])
{
   int n,m=11;
   n = strlen(msg);
   if (m==6)
   {
      printf("%s",msg);
   }
   else
   {
      for(int i=1;i<=m;i++){
         for (int j = 0; j < n; j++)
         {
            printf(" %c",symbol);
         }
         printf("\n");
      }
   }
   return 1;
}
int square_maker(char symbol,char msg[40])
{
 int n;
 n = strlen(msg);
 for (int i = 0; i < n; i++)
 {
   if(i==n/2)
    {
       printf("%s",msg);
    }
   else
    {
      for (int j = 0; j < n; j++)
      { 
         printf("%s",symbol);
      }
    }
 return 1;
 } 
}
int choose_shape()
{
   int choice;
   printf("Select any of the following patterns:\n1. Triangle\n2. Rectangle\n3. Square");
   printf("\nPlease enter your choice: ");
   scanf("%d",&choice);
   return choice;
}
void final(char msg[40],int choice)
{
   char symbol;
   printf("\nPlease enter symbol to fill the shape: ");
   scanf(" %c", &symbol);
    switch (choice)
   {
   case 1:
      triangle_maker(symbol,msg);
      break;
   case 2:
      rectangle_maker(symbol,msg);
      break;
   case 3:
      square_maker(symbol,msg);
      break;
   
   default:
      printf("Please make a valid selection....");
      break;
   }
}