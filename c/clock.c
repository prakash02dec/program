#include<stdio.h>
#include<time.h>
void fun()
{

 long int i;
 for (i=0;i<999999;i++)
 {
  printf("%ld\n",i);
 }

}

void main()
{
    clock_t t;
    t = clock();
    fun();
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

    printf("fun() took %f seconds to execute \n", time_taken); 
    
}