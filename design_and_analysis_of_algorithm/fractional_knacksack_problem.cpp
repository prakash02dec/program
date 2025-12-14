#include <iostream>
#include <vector>
#include <algorithm>

double knapsack(const int &max,const std::vector<int> &weight ,const std::vector<int> &val );

int main(){
    std::vector<int> value {1 , 2 , 5 , 6};
    std::vector<int> weight {2 , 3, 4, 5};
    int weight_max = 8;
    
    std::cout << "Maximum value :: " << knapsack(weight_max , weight , value) <<std::endl;


    return 0;
}

double knapsack(const int &max ,const std::vector<int> &weight ,const std::vector<int> &val ){
    std::vector<std::vector<int>> ratios ;
    
    for(size_t i {}; i < weight.size() ;i++){
        std::vector<int> temp {val.at(i),weight.at(i)} ;
        ratios.push_back(temp);
    };
    
    std::sort(ratios.begin(), ratios.end(),[=](auto a , auto b)
    {return static_cast<double>(a.at(0)/a.at(1)) > static_cast<double>(b.at(0)/b.at(1));});
    
    int net_weight {};
    double value {};
    size_t i = 0;
    for ( i = 0; i < weight.size() && (net_weight + ratios.at(i).at(1) <= max)  ; i++) {
        net_weight += ratios.at(i).at(1);
        value += ratios.at(i).at(0);
        }
    
    int left = max - net_weight;
    value += ratios.at(i).at(0)*(static_cast<double>(left)/static_cast<double>(ratios.at(i).at(1)));

    
    return value;
}