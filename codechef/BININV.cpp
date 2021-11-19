#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <map>
#include <iterator>
#include <algorithm>
#include <pair>
int main (){
    int t{};
    std::cin>>t;
    while(t--){
        int n{} , m{};
        std::cin>> n>>m;
        std::multimap<int , int > inversions;
        // std::deque <std::string> strings;
        // std::string string;
        for(int i {} ; i < n ; i++){
            // std::cin >> string;
            int zero {} , ones{} ;
            for (int j {} ; j < m ; j++){
                int x {};
                std::cin >> x;
                if(x==1) ones++;
                else zero++;
            }
            inversions.insert(std::make_pair(zero, ones));

        }
        int answer{};
        auto it = inversions.begin();
        while ( it != std::advance(inversions.end(), -1) )
        {
            answer += it->second * std::acculmulate(it+1, inversions.end(), 0 , [](std::pair<int , int> p1 , std::pair<int , int> p2){return p1.second + p2.second});
        }
        

    }
    return 0;
}