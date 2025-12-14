#include<bits/stdc++.h>
using namespace std;

int maximumScore(int a, int b, int c) {
    std::priority_queue<int> pq {} ;
    pq.push(a);
    pq.push(b) ;
    pq.push(c) ;
    int cost {} , x{} , y{};
    while(pq.size()>1){
        x = pq.top() ; pq.pop() ;
        y = pq.top() ; pq.pop() ;
        x-- ; y-- ;
        cost++ ;
        if(x) pq.push(x) ;
        if(y) pq.push(y) ;
    }
    return cost ;

}

int main(){
    std::cout << maximumScore(2,4,6);
    return 0 ;
}