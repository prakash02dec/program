#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t>0)
    {
        int low=0, upper=0 , no=0 ,spec=0 , len=0;
        char s[20];
        scanf("\n%s",&s);
        len=strlen(s);
        if(len>=10 )
        {
            int i;
            for(i=0;i<len-1;i++)
            {
                if(isdigit(s[i]) && i!=0 && i!=len-1)
                {
                    no++;
                }
                else if(isupper(s[i]) && i!=0 && i!=len-1)
                {
                    upper++;
                }
                else if(islower(s[i]))
                {
                    low++;
                }
                else if((s[i]==35 || s[i]==37 || s[i]==38 || s[i]==64 || s[i]==63) && i!=0 && i!=len-1)
                {
                    spec++;
                }
                
            }
           
        }
        
         if(no>0 && upper>0 && low>0 && spec>0)
            {
                printf("\nYES");
            }
        else
        {
            printf("\nNO");
        }
            
        t--;
    }
    return 0;
}


