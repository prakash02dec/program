#include<iostream>

#include<vector>

int main ()
{
    std::vector <std::vector <int>> values { {1,2,3}, {4,5,6} ,{7,8,9}};

    for(auto value:values)
        {
            for(auto no:value)
            {
                std::cout<<no<<" ";

            }
            std::cout<<std::endl;
        }

    std::cout<<std::endl;
    return 0;
}
