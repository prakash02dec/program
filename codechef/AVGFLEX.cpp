#include <iostream>
#include <map>
#include <algorithm>
#include <numeric>

template <typename T1, typename T2>
void display(const std::map<T1, T2> &l) {
    std::cout << "[ ";
    for (const auto &elem: l) {
        std::cout << elem.first << ":" << elem.second << " ";
    }
    std::cout << "]  " << std::endl;
}



int main() {
	int T;
	std::cin >> T;
	while(T--){
	    std::map<int , int> marks_freq;
	    int N , marks;
	    std::cin >> N;
	    int i {N};
	    while(i--){
	        std::cin>>marks ;
	        marks_freq[marks]++;
	    }
	   // display(marks_freq);
	    i = marks_freq.size();
	    auto it = marks_freq.begin();
	    int total {} ;
	    while(i--)
	    {
	        it++ ;
	        int sum1 = std::accumulate(marks_freq.begin()  , it , 0 , 
	        [] (int value, const std::map<int, int>::value_type &p)
                   { return value + p.second; }
               );
	        
	        int sum2 = std::accumulate(it , marks_freq.end() , 0 , 
	        [] (int value, const std::map<int, int>::value_type &p)
                   { return value + p.second; }
               );
            // std::cout << sum1 << sum2 ;
            // std::cout << it->second;
	        if(sum1 > sum2) 
	        {   it--;
	            total += it->second;
	            it++;    
	        }
	        
	        
	    }  
	    std::cout<< total << std::endl;
	}
	return 0;
}

