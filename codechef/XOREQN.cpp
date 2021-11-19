#include <iostream>

typedef long long ll;

void toggle(ll &num, ll pos)
{
    num ^= (1 << pos);
}

bool at_position(ll num, ll pos)
{
    bool bit = num & (1 << pos);
    return bit;
}



int main()
{
    int t;
    std::cin >> t;
    int answer{};
    while (t--)
    {
        int n;
        std::cin >> n;
        ll a[n];
        ll answer{};
        for (size_t i{}; i < n; i++){
            std::cin >> a[i];
        }
        ll array_xor{a[0]};
        for (size_t i{1}; i < n; i++)
        {
            array_xor ^= a[i];
        }

        // ll x{array_xor};

        // ll pos{};
        // while (pos < 63)
        // {
        //     while (!at_position(x, pos) && pos < 63){
        //         pos++;
        //     }
        //     if (pos < 63 && at_position(x, pos))
        //     {
        //         toggle(answer, pos);
        //     }

        //     x = a[0] + answer;
        //     for (size_t i{1}; i < n; i++)
        //     {
        //         x ^= a[i] + answer;
        //     }
        //     if (x == 0 && answer >= 0)
        //     {
        //         std::cout << answer << std::endl;
        //         break;
        //     }

        //     pos++;
        // }

        // if (x != 0 || answer < 0)
        // {
        //     std::cout << "-1" << std::endl;
        // }

        ll j {};
        ll sum {};
        for (j = 0; j < 1190000; j++)
        {
            sum = a[0] +j;
            for(size_t i{1} ; i<n ;i++){
                sum ^= a[i] + j;
            }
            if(sum == 0 ){
                std::cout << j << std::endl;
                break;
            }
        }
        if(sum != 0){
            std::cout << "-1" << std::endl;
        }
    }
    return 0;
}

