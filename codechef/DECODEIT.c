#include<stdio.h>
int main()
{
    int t ;
    scanf("%d",&t);  /* no of test */
    while(t>0)
    {   
        int i , n ,ch=112 , p=8;
        scanf("\n%d",&n); /* length of string */
        char s[n];
        s[n]=0;
        scanf("%s", &s); 
        for(i=0;i<n;i++)
        {
           if(i%4==0)
                ch=112 , p=8;
                 if(s[i]=='0')
                {
                ch=ch-p;
                }
                if((i+1)%4==0)
                printf("%c",ch);    
                p/=2;
        
        }
           
        printf("\n");
        t--;

    }
}