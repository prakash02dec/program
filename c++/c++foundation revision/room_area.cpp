#include<iostream>
using namespace std;

int main ()
{
    cout<<"Enter the room width";
    int room_width {0};
    cin>>room_width;
    
    cout<<"Enter the room length";
    int room_length {0};
    cin>>room_length;
    
    cout<<"room area is "<<room_width*room_length<<"square unit";

    return 0;
}