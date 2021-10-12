#include<iostream>
#include<math.h>
using namespace std;
int main()
{
  int T;
  cin>>T;
  while(T--)
  {
    int N;
    cin>>N;
    if(N>500)
        continue;
    int arr[N];
    int max=0,max2=0;
    int max_pos;
    int min=pow(10,9),min2 = pow(10,9)-1;
    int min_pos;
    for (int i = 0; i < N; i++)
    {
      cin>>arr[i];
      if(arr[i]>max)
      {
        max = arr[i];
        max_pos = i;
      }
      if(arr[i]<min)
      {
        min = arr[i];
        min_pos = i;
      }
    }
    for (int i = 0; i < N; i++)
    {
      if((i != max_pos) && (i != min_pos))
      {
        if(arr[i]>max2)
        {
          max2 = arr[i];
        }
        if(arr[i]<min2)
        {
          min2 = arr[i];
        }
      }
    }//5+3=8
    if((max-min2) > (max2 - min))
    {
      cout<<(max-min) + (max - min2) + (min2 - min)<<"\n";
    }
    else
    {
      cout<<(max-min) + (max2 - min) + (max - min2)<<"\n";
    }
    
    
  }
  return 0;
}