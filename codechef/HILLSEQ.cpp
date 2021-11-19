#include <iostream>
#include <map>
#include <deque>
#include <algorithm>


int main (){
    int t;
    std::cin>>t;
    while(t--){
        int n;
        std::cin >> n;
        int a[n];

        std::map <int , int > freq;
        std::deque<int> answer ;
        
        for(size_t i{}; i<n ; i++){
            std::cin >> a[i];
            freq[a[i]]++;
        }
        // display(freq);
        
        auto it = freq.rbegin();
        if(freq.rbegin()->second > 1){
            std::cout << "-1" << std::endl;
            continue;
        }
        
        while(it != freq.rend()) {
            if( it->second > 2 ){
                break;
            }
            else{
                    answer.push_back(it->first);
                    if(it->second == 2)
                    answer.push_front(it->first);
            }
            it++;
        }
        if( it->second > 2 && it != freq.rend()){
            std::cout << "-1" << std::endl;
            continue;
        }

        for (const auto &elem: answer)
        std::cout << elem << " ";

        std::cout << std::endl;

    }
    return 0;
}

