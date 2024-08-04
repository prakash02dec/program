#include <bits/stdc++.h>
#define int            long long int
#define S              second
#define F              first
#define pb             push_back
#define si             set <int>
#define vi             vector <int>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define sz(x)          ((int) x.size())
#define double         long double
#define all(p)         p.begin(), p.end()
#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)       for(auto x : a) std::cout << x << " "; std::cout << std::endl
#define print1(a)      for(auto x : a) std::cout << x.F << " " << x.S << std::endl
#define print2(a,x,y)  for(int i = x; i < y; i++) std::cout<< a[i]<< " "; std::cout << endl

inline int power(int a, int b)
{
    int x = 1;
    while (b)
    {
        if (b & 1) x *= a;
        a *= a;
        b >>= 1;
    }
    return x;
}

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { std::cout << name << " : " << arg1 << std::endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr (names + 1, ',');
    std::cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

const int N = 200005;

int solve1(int n  ,int k ,int h ) {

    // int n {} , k {} , h {} ;
    // cin >> n >> k >> h ;
    int steps = ceil((double)h/k) ;
    // cout << steps << endl ;
    int ans {} ;
    for(int b {1} ; b <= n && steps <= n ; b++ ){
        int a {b+steps } ;
        for(int i {steps} ;  i > 0 ; i--  ){
            if(b + k*i >= h){
                a = std::min(a , b+i) ;
            }
        }
        a = std::min(a , h) ;
        // std::cout << a << " " << b << " " << n-a +1 << std::endl ;
        ans += std::max( 0LL , n-a +1LL ) ;
    }
    
    std::cout << ans << std::endl ;
    return ans ;
}
int solve2(int n  ,int k ,int h ) {
    // int n {34} , k {434}, h {342} ;
    // 34 434 342
    int ans {} ;
    for(int b = 1; b <= n; b++){
        int count {} ;
        for(int a {1} ; a <= n; a++){
            int x = 0 ;
            for(int i = 1; i <= k; i++){
                x += a ;
                if(x >= h){ 
                    // std::cout << "a : " << a <<" x " ;
                    count++ ; break;}
                x =  (x-b < 0  ? 0 : x-b) ;
            }
        }
        std::cout << std::endl ;
        // std::cout << count << " " << b << std::endl;
        ans += count ;
    }
    std::cout << ans << std::endl;
    return ans ;
}

int32_t main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
    freopen("output.txt", "w", stdout);
#endif

    clock_t z = clock();

    int t = 10;
    // std::cin >> t;
    while (t--) {
    srand(0) ;
    int n = rand()%100000 + 1;
    int k = rand()%100000 + 1;
    int h = rand()%100000 + 1;
    int s1 = solve1(n , k , h) ;
    int s2 = solve2(n , k , h) ;
    // std::cout << "n : " << n << " k : " << k << " h : " << h << std::endl ;
    if(s1 != s2){
        std::cout << "n : " << n << " k : " << k << " h : " << h << std::endl ;
        std::cout << "a : " << s1 << " b : " << s2 << std::endl ;
        break;
    }
    }
    
    std::cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}