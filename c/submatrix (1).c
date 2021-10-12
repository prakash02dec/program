/*===================================header files================================*/
#include<stdio.h>
#include <stdlib.h>
/*=================================global variable==============================*/
int m;
int n;
/*===================================function prototype======================================*/
// void input_matrix(int (*arr)[n],int n);
void output_matrix(int (*arr)[n],int size);
int check (int (*matrix1)[m], int (*matrix2)[n]);
/*====================== function to check small matrix inside bigger matrix=============*/
int check (int (*matrix1)[m], int (*matrix2)[n])
{
    printf("Check func print checks\n");
    printf("the smaller matrix\n");
    int h,g;
    for(h=0;h<m;h++)
    {
        for(g=0;g<m;g++)
        {
            printf("%d ",matrix1[h][g]);       
        }
        printf("\n");
    }    
    
    int k;

    printf("the  bigger matrix\n");
    for(k=0;k<n;k++)
    {
        for(int m=0;m<n;m++)
        {
            printf("%d ",matrix2[k][m]); 
        }
        printf("\n");
    }
    k=0;
    int i , j,l;
    int flag=0;
    for(i=0;i<n-1;i++)
    {
    for(j=0;j<n-1;j++)
   {
       flag=0;
        for(k=0;i<m;i++)
        {
            for(l=0;j<m;j++)
            {   
                if(matrix1[k][l]!=matrix2[i+k][j+l])
            {
                flag=0;
                l=m;
                k=m;

            }
            else 
            {
                flag=1;
            }
        }
        }
   }
         if(flag)
         return 1;  
    }
    return 0;
    
}


/*==========================function to print matrix=================================*/
void output_matrix(int (*arr)[n],int size)
{
    int i , j;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            printf("%d ",arr[i][j]);       
        }
        printf("\n");
    }    
}
/*=========================main function of the programmer =============================*/
int main()
{
    printf("\nenter the n of bigger matrix\n");
    scanf("%d",&n);
    int matrix2[n][n];
    printf("\n enter the element of %dx%d matrix\n",n,n);
    int a,b;
    for(int a=0;a<n;a++)
    {
        for(int b=0;b<n;b++)
        {
            scanf("%d",&matrix2[a][b]); 
        }
    }
    
    printf("\nenter the n of smaller matrix\n");
    scanf("%d",&m);
    int *matrix1[m][m];
    printf("\nenter the element of %d x %d matrix\n",m,m);

    int i , j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&matrix1[i][j]);       
        }
        printf("\n");
    }

    printf("the smaller matrix\n");
    i=0;j=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d ",matrix1[i][j]);       
        }
        printf("\n");
    }    


    printf("the  bigger matrix\n");
    for(int k=0;k<n;k++)
    {
        for(int m=0;m<n;m++)
        {
            printf("%d ",matrix2[k][m]); 
        }
        printf("\n");
    }

    if(check(matrix1,matrix2))
    printf("\n smaller  matrix is found in bigger MATRIX");
    else
    printf("\n smaller matrix is not found in bigger matrix");
    return 0;

}