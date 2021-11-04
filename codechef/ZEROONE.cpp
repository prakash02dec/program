#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

typedef long long ll;

int main() {
	int T {};
	std::cin >> T;
	while (T--){
	   int N ;
	   std::cin >> N;
	   int array[N];
	   for(int i {} ; i < N ; i++){
	       std::cin >> array[i];
	   }

	std::vector<int> zero , one ;
	   
    for(int i {} ; i<N ; i++){
	        if(i%2==0){
	            zero.push_back(array[i]);
	        }
	        else{
	          one.push_back(array[i]);
            }
	   }

	   std::sort(one.begin() , one.end() );
	   std::sort(zero.begin() , zero.end()  , std::greater<int>());

	   for(int i {} , j {} , k {}  ; i<N  ; i++){
	        
            if(i%2==0)
	            {array[i]=zero.at(j++);}
	        else
	            array[i]=one.at(k++);
	   }
	   int total_seq {};
	   int no_of_zeros {};
	   std::for_each(zero.begin() , zero.end() , [&total_seq , &no_of_zeros , one](int zeros)
	   {total_seq += zeros * std::accumulate(one.begin() + no_of_zeros, one.end() , 0 ); no_of_zeros++;});
	   
       for(const auto &ele : array){
	      std::cout<<ele << " ";
	   }
	    
        // for(int i=0;i<zero.size();i++){
        //     total_seq +=(zero[no_of_zeros]*accumulate(one.begin()+no_of_zeros,one.end(),0));
        //     no_of_zeros++;
        // }
	    std::cout << std::endl << total_seq << std::endl;
	}
	return 0;
}