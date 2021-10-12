#include<stdio.h>

int main()
{
     printf("Write the no. of Rows of the 2 D arrays having exactly 2 Columns only:-");

    int e; scanf("%d",&e);

    int q[e][2];
    printf("Write the elements of 2D arrays having 2 Columns only:-");
    for (int i = 0; i < e; i++){scanf("%d%d",&q[i][0],&q[i][1]);}

    int r[e][2];
    printf("Write the elements of other 2D arrays having 2 Columns only:-");
    for (int i = 0; i < e; i++){scanf("%d%d",&r[i][0],&r[i][1]);}

    printf("1st Matrix:-\n");
    for (int i = 0; i < e; i++){printf("%d %d\n",q[i][0],q[i][1]);}

    printf("\n2nd Matrix:-\n");
    for (int i = 0; i < e; i++){printf("%d %d\n",r[i][0],r[i][1]);}

    printf("\nSum of Matrixes:-\n");
    for (int i = 0; i < e; i++){printf("%d %d\n",q[i][0]+r[i][0],q[i][1]+r[i][1]);}

}
