#include <iostream>
#include <string>
using namespace std;

int main() {
	int t {};
	std::cin>> t;
	while(t--){
	    std::string a , b;
        int n; 
        std::cin >> n ;
        std::cin >> a >> b ; 
        int total_one_a {}; // in a
        int total_zero_a {}; // in a
        int total_one_b {}; // in b
        int total_zero_b {}; // in b
        for(int i {} ; i < n ; i++){
            if(a[i] == '0') total_zero_a++;
            else total_one_a++; 
            if(b[i] == '0') total_zero_b++;
            else total_one_b++; 

        }
    int i{}, j{}, k{};
    std::string c {};
    while (i < n && j < n)
    {
        if (a[i] < b[j]   )
            c[k++] = a[i++];
        else if (b[j] < a[i])
            c[k++] = b[j++];
        else if (b[j] == a[i] ){
            if( total_zero_a > total_zero_b){
            c[k++] = b[i++];}
        }
    }
    while (i < n)
    {
        c[k++] = a[i++];
    }
    while (j < n)
    {
        c[k++] = b[j++];
    }

}
	return 0;
}
