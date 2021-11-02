#include <iostream>
#include <vector>

int knapsack(const int &max,const std::vector<int> &weight ,const std::vector<int> &val );

int main (){
    std::vector<int> value {1 , 2 , 5 , 6};
    std::vector<int> weight {2 , 3, 4, 5};
    int weight_max = 8;
    
    std::cout << "Maximum value :: " << knapsack(weight_max , weight , value) <<std::endl;

    return 0;

}

int knapsack(const int &max, const std::vector<int> &weight,const std::vector<int> &val){
    std::vector <std::vector <int>> matrix (weight.size()+1 , std::vector<int>(max+1));

    for(size_t i {0} ; i<=weight.size() ; i++ )
        for(size_t wt {0} ; wt <= max ; wt++ ){
            if(i == 0 || wt == 0 ) matrix.at(i).at(wt) =0;
            else if (weight.at(i-1) <= wt )
            {
                auto a { val.at(i-1) + matrix.at(i-1).at(wt - weight.at(i-1)) } ;
                auto b { matrix.at(i-1).at(wt) };
                matrix.at(i).at(wt) = a > b ? a :b ; 
            }
            else matrix.at(i).at(wt) = matrix.at(i-1).at(wt);

        }
    return matrix.at(weight.size()).at(max);
}

