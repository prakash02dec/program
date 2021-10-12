
#include <iostream>
#include<ctype.h>
#include<string.h>
using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int l=0, u=0 , n=0 ,s=0 , len=0;
        char pwd[20];
        scanf("\n%s",&pwd);
        len=strlen(pwd);
        if(len>=10 )
        {
            for(int i=0;i<len-1;i++)
            {
                if(isdigit(pwd[i]) && i!=0 && i!=len-1)
                {
                    n=1;
                }
                else if(isupper(pwd[i]) && i!=0 && i!=len-1)
                {
                    u=1;
                }
                else if(islower(pwd[i]))
                {
                    l=1;
                }
                else if((pwd[i]==35 || pwd[i]==37 || pwd[i]==38 || pwd[i]==64 || pwd[i]==63)&& i!=0 && i!=len-1)
                {
                    s=1;
                }
                
            }
           
        }
        
         if((l+u+n+s) == 4)
            {
                printf("\nYES");
            }
        else
        {
            printf("\nNO");
        }
    }
    return 0;
}