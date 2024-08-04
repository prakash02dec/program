#include <iostream>
using namespace std;

int main() {
    int ans_array[1000] {} ,x{};
    for (int i {}; i < 17; i++){
        for (int j {i+1}; j < 18; j++){
            for (int k {j+1}; k < 19; k++){
                for (int l {k+1}; l < 20; l++){
                    ans_array[x++] = (1 << l) + (1 << k) + (1 << j) + (1 << i);
                    if (x == 1000){
                       i = j = k = l = 21;
                    }
                }
            }

        }

    }
	int t {};
	std::cin>> t;
	while(t--){
	    int n{};
        std::cin >> n;
        for (int i {}; i < n; i++)
        {
            cout << ans_array[i] << " ";
        }
        cout << endl;

	}
	return 0;
}
