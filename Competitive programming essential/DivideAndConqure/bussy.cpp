#include <bits/stdc++.h>

using namespace std ;

int solve(int n,int k, std::vector<int> &h ){
    int count {} ;
    std::sort(h.begin() , h.end() , std::greater<int>() ) ;
    int max {h[0]} ;
    int min {h[n-1]} ;
    int slice {max } , idx {0 } ;
    long long sum {0} ;
    while(slice>=min){
        while(idx<n && slice < h[idx]){
            sum += h[idx] ;
            idx++ ;

        }
        
        // std::cout << sum << " " << idx <<  " " <<(sum - idx*(slice)  ) << " " << slice <<" " << endl;
        // std::cout << sum << " " << idx <<  " " <<(sum - idx*(slice-1)  ) << " -1 " << slice <<  endl;
        if(k == (sum - idx*(slice))){

            count++ ;
            sum = idx*slice ;
        }else if(k == (sum - idx*(slice-1))){
            count++ ;
            sum = idx*slice ;
        }else if (k < (sum - idx*(slice-1))){

            count++ ;
            sum = idx*slice ;
        }
        
        
        slice-- ;
    }
    // std::cout  << slice<< endl ;
    std::cout << count << endl ;
    return count ;
}


int main()
{
    // std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
    freopen("output.txt", "w", stdout);
#endif

    // clock_t z = clock();

    int t = 1;
    // caculate_factorial() ;
    std::cin >> t;
    while (t--) {
        int n {} , k {} ;
        std::cin >> n >> k ;
        std::vector <int > h (n) ;
        for(auto &ele : h) {
            int temp {} ;
            std::cin>> temp ;
            ele = temp ;
        }
        solve(n , k , h);
    }
    
    // std::cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}

// 96 96 84 80 78 76 59 56 52 51 49 47 43 37 36 33 33 32 26 23 23 17 17 17 13 13 11 10 9 4 4 1 0 