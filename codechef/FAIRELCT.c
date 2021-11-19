#include<stdio.h>
void ascending(int y[],int *s);
int main()
{
    int t;
    scanf("%d",&t);
    while(t>0)
    {
        register int i ,total1=0, total2=0 ,p=0 ;
        int m, n ;
        scanf("\n%d",&n);
        scanf("\t%d\n",&m);
        int a[n],b[m];
        for(i=0;i<n;i++)
        {
             scanf("%d",&a[i]);
             total1+=a[i];
        }
        for(i=0;i<m;i++)
        {
            scanf("%d",&b[i]);
            total2+=b[i];
        }
        ascending(&a[0],&n);
        ascending(&b[0],&m);
        for(i=0;i<m && i<n ;i++)
        {
            if(total2>=total1)
            {   
                total1=total1-a[i]+b[m-1-i];
                total2= total2-b[m-1-i]+a[i];
                a[i]+=b[m-1-i];
                b[m-1-i]=a[i]-b[m-1-i];
                a[i]=a[i]-b[m-1-i];
                p++;
            }
            else 
            break;          
        }
        if(total2>=total1)
        {
            printf("%d\n",-1);
        }
        else
        {
            printf("%d\n",p);
        }
        

        t--;
    }
    return 0;
}
void ascending(int arr[],int *s)
{
  register int i ,j , temp;
 for(i = 0; i < *s; i++)
    {
        for(j = 0; j < *s-1; j++)
        {
            if( arr[j] > arr[j+1])
            {
                // swap the elements
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            } 
        }
}}