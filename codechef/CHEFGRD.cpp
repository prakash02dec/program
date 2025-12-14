#include <iostream>
using namespace std;

int main() {
	int t {};
	std::cin>> t;
	while(t--){
	    int n , x , y ;
        cin >> n >> x >>y;
        // 2 mean both even x and y;
        int temp {};
        if(x%2==0) temp++;
        if(y%2==0) temp++;
        if(temp == 1) cout << "1" << endl;
        else cout << "0" <<endl;
	}
	return 0;
}
