#include <iostream>
#include <vector>
#include<algorithm>

int main()
{
    int T;
    std::cin >> T;
    while (T--)
    {
        int N;
        std::cin >> N;
        std::vector<int> array(N);
        int max_index{};
        int max{};
        for (int i{}; i < N; i++)
        {
            std::cin >> array[i];
            if (max < array[i]){
                max_index = i;
                max = array[i];}
        }

        int min{*std::min_element(array.begin(), array.end())};

        if (min == max)
        {
            std::cout << "0" << std::endl;
        }
        else if (max_index == N - 1)
        {
            std::cout << "1" << std::endl;
        }
        else{
            std::cout << "2" << std::endl;
        }
    }

    return 0;
}
