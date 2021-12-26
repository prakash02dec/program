#include <iostream>
#include <map>
#include <vector>
#include <numeric>
using namespace std;

int xorPairCount(int n)
{
    std::vector<int> arr(n);
    std::iota(arr.begin(), arr.end(), 0);
     int result = 0; // Initialize result

    // create empty map that stores counts of
    // individual elements of array.
    std::map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        int curr_xor = 0 ^ arr[i];

        // If there exist an element in map m
        // with XOR equals to x^arr[i], that means
        // there exist an element such that the
        // XOR of element with arr[i] is equal to
        // x, then increment count.
        if (m.find(curr_xor) != m.end())
            result += m[curr_xor];

        // Increment count of current element
        m[arr[i]]++;
    }

    // return total count of pairs with XOR equal to x
    return result;
}

int main()
{
    int t{};
    std::cin >> t;
    while (t--)
    {
        int mod7{1000'000'007};
        int N;
        std::cout << xorPairCount(N);
    }
    return 0;
}
