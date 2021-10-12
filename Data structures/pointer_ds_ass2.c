#include<stdio.h>
int main(void)
{
    char *month[]={"january","februay","march","april","may","june","july","august","september","october","november","december"}; 
    int avg_rainfall[12]={5,3,2,3,4,8,12,12,11,9,3,4};
    
    int avg_june_october=0;
    for(int i=5;i<10;i++)
    {
        avg_june_october+=*(avg_rainfall+i);
    }
    avg_june_october/=5;
    printf("average rainfall from june to october is  %d \n",avg_june_october);

    
    for(int i=0;i<12;i++)
    {
        for(int j=0;j<11-i;j++)
        {
            if(*(avg_rainfall+i+1) < *(avg_rainfall+i))
            {
                int tempi;
                char  *tempc;
                tempi=*(avg_rainfall+1+i);
                *(avg_rainfall+1+i)=*(avg_rainfall+i);
                *(avg_rainfall+i)=tempi;
                
                tempc=*(month+i+1);
                *(month+i+1)=*(month+i);
                *(month+i)=tempc;
            }
        }
    }

    printf("\n month have average rain fall less than 4%% is are given below ");

    for(int i=0;i<12;i++)
    {
        if(*(avg_rainfall+i)<4)
        {
            printf("\n%s\t%-6d",*(month+i),*(avg_rainfall+i));


        }
    }

    printf("\nthe lowest avg rainfall in %s is %d",*(month),*(avg_rainfall));
    printf("\nthe highest avg rainfall in %s is %d",*(month+11),*(avg_rainfall+11));
    return 0;
}