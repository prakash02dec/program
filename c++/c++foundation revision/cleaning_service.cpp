#include<iostream>
using namespace std;

int main()
{
    cout<<"Hello , welcome to Frank's carpet Cleaning Service"<<endl;
    cout<<"\n How many large rooms would you like cleaned? ";

    int number_of_large_rooms {0};
    cin>>number_of_large_rooms;

    cout<<"\n How many small rooms would you like cleaned? ";

    int number_of_small_rooms {0};
    cin>>number_of_small_rooms;


    const double price_per_large_room {35},price_per_small_room {25}, sales_taxes {0.06};
    const int estimate_expiry{30}; //days

    cout<<"\n Estimate for carpet cleaning service "<<endl;
    cout<<"Number of large rooms: "<<number_of_large_rooms<<endl;
    cout<<"Number of small rooms: "<<number_of_small_rooms<<endl;
    cout<<"Price per large room: $"<<price_per_large_room<<endl;
    cout<<"Price per small room: $"<<price_per_small_room<<endl;
    cout<<"Cost: $"<<(price_per_large_room*number_of_large_rooms)+(price_per_small_room*number_of_small_rooms)<<endl;
    cout<<"Tax: $"<<((price_per_large_room*number_of_large_rooms)+(price_per_small_room*number_of_small_rooms))*sales_taxes<<endl;
    cout<<"======================================================"<<endl;
    cout<<"total estimste: $"<<(price_per_large_room*number_of_large_rooms)+(price_per_small_room*number_of_small_rooms)+(((price_per_large_room*number_of_large_rooms)+(price_per_small_room*number_of_small_rooms))*sales_taxes)<<endl;
    cout<<"this estimate is valid for "<<estimate_expiry<<" days"<<endl;

    

    cout<<endl;
    return 0;


}