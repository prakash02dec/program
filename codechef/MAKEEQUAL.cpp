#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t {};
	std::cin>> t;
	while(t--){
		int n{};
		std::cin >> n;
	    std::vector<int> arr(n);
		for(auto &no : arr) std::cin >> no;
		auto max = *std::max_element(arr.begin(), arr.end());
		auto min = *std::min_element( arr.begin() , arr.end());
		std::cout << max - min << std::endl;
	}
	return 0;
}
