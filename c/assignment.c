//======================================header files========================================================
#include<stdio.h>
#include<string.h>
//=====================================global variable===========================================
char message[40];
char sign;
//========================================funtion declaration======================================
void triangle();
void shape();
void rectangle();
void square();
void symbol();
// ============================= main function ==============================================================================
int main()
{
    printf("\n enter the message you want to print in shape \n "); 
    scanf(" %[^\n]s",message);
    symbol();
    shape();
   
    return 0;
}
// =============================shape deciding function =======================================================================
void shape()
{
    int n;
    char response;
    printf("\n choose the shape \n 1. triange \n 2. rectangle \n 3. square\n");
    scanf("%d", &n);
    switch(n)
    {
        case 1 : triangle();
                  break;
        case 2 : rectangle();
                   break;
        case 3 : square();
                   break;
        default :printf(" invalid option ");
         
         
    }     
    printf("do you want continue again (y/n)");
    scanf(" %c",&response);
    if(response=='y' || response=='Y')
    main(); 
}
//==================================triangle shape printing function===================================================
void triangle()
{
    int i=0 , j=0 , l=strlen(message);
    for(i=0;i<l;i++)
    {  
        for(j=l;j>i;j--)
        printf(" ");
        if(i==l/2)
        {
            printf("%s", message);
            printf("\n");
            continue;
        }
        for(j=0; j<=2*i ; j++)
        printf("%c",sign);
        printf("\n");
    }

}
//==================================rectangle shape printing function===================================================
void rectangle()
{
    int l=strlen(message) , i=0 , j=0;
    for(i=0 ; i<l;i++)
    {
        if(i==l/2)
            {
                printf("%s", message);
                printf("\n");
                continue;
            }
        for(j=0;j<l;j++)
        {
            printf("%c",sign);
        }
        printf("\n");
        
    }
}
//====================================square shape printing function=====================================================
void square()
{
    int l=strlen(message), i=0 , j=0;
    for(i=0 ; i<l ; i++)
    {
        if(i==l/2)
        {
            printf("%s", message);
            printf("\n");
            continue;
        }
        for(j=0 ; j<2*l ; j++)
        {
            printf("%c", sign);
        }
        printf("\n");
    }
}
//=================================assigning sign===============================================
void symbol()
{
	printf("\n enter the sign as unit of which you want your shape made off ");
    scanf(" %c", &sign);
}

//========================end of program=============================================================