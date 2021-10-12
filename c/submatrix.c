#include<stdio.h>
int main()
{
    int r,c,x,r1,c1,x1,flag=1;
    printf("Enter number of rows in matrix:\t");
    scanf("%d\n",&r);
    printf("Enter number of columns in matrix:\t");
    scanf("%d\n",&c);
    int a[r][c];
    int sub[r1][c1];
    for (int i=0;i<r;i++)
        {
            for (int j=0;j<c;j++)
            {
                printf("Enter element at index(%d,%d)\n",i,j);
                scanf("%d",&x);
                a[i][j]=x;
            }
        }
    printf("Enter number of rows in matrix that U want to check for submatrix:\t");
    scanf("%d\n",&r1);
    printf("Enter number of columns in matrix that U want to check for submatrix:\t");
    scanf("%d\n",&c1);
    for (int i=0;i<r1;i++)
    {
        for (int j=0;j<c1;j++)
        {
            printf("Enter element at index(%d,%d)\n",i,j);
            scanf("%d",&x);
            sub[i][j]=x;
        }
    }
x=sub[0][0];
for (int i1=0;i1<(r-r1+1);i1++)
{
    for (int j1=0;j1<(r-r1+1);j1++)
    {
        if (flag==0)
        {
            printf("This matrix is a submatrix of the given matrix");
            exit(0);
        }
        
        flag=0;
        x1=a[i1][j1];
        if (x==x1)
        {
            for (int i;i<r1;i++)
            {
                for (int j;j<c1;j++)
                {
                    x=sub[i][j];
                    x1=a[i1][j1];
                    if (x!=x1)
                    {
                        flag=1;
                    }
                    if (flag==1)
                    {
                        break;
                    }
                    j1+=1;
                }
                i1+=1;
                if (flag==1)
                {
                    break;
                }
            }

        }
    }
}
    return 0;
}