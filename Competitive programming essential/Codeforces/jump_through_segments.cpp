#include <bits/stdc++.h>
using namespace std;

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

const int mod {8} , N{101};
const int sz {3};

struct Mat {
    long long m[sz][sz] ; 
    Mat() {
        memset(m, 0 , sizeof(m)) ;
    }
    void identity(){
        for(int i {0} ; i < sz ; i++){
            m[i][i] = 1 ;
        }
    }
    Mat operator*(Mat a){
        Mat res {}; 
        for(int i {} ; i < sz ; i++){
            for(int j {} ; j < sz ; j++){
                for(int k {} ; k < sz ; k++ ){
                    res.m[i][j] += m[i][k]*a.m[k][j] ; 
                    res.m[i][j] %= mod ; 
                }
            }
        }
        return res ;
    }
};

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

int  fac[N] {} ;

int addm(int x , int y) {
    return (x+y) % mod ;
}

int subm(int x , int y){
    return ((x - y ) + mod ) % mod ;
}

int mulm (int x , int y){
    return (x*y) %mod ;
}


int powm(int x , int m ){
    int result {1} ;
    while(m){
        if(m&1) result = mulm(x, result) ;
        x = mulm(x ,x) ;
        m /= 2 ;
    }
    return result ;
}


int inv(int y){
    return  powm(y , mod-2) ;
}

// using fermat theorum
int divm(int x , int y){
    return mulm (x , inv(y)) ;
}

void caculate_factorial() {
    fac[0] = 1 ;
    for(int i=1 ; i< N ; i++){
        fac[i] = mulm(fac[i-1] ,i) ;
    }

}

int nCr(int n , int r){
    return mulm (mulm(fac[n] , inv(fac[r])) , inv(fac[n-r])) ;
}

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { std::cout << name << " : " << arg1 << std::endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr (names + 1, ',');
    std::cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

// 192 1276
bool valid_k(int k , const auto &segments){
    int leftK {} , rightK {} ;
    for(const auto &segment : segments){
        leftK = max(leftK - k , segment.first) ;
        rightK = min(rightK + k , segment.second) ;
        if(leftK > segment.second || rightK < segment.first ){
            return false ;
        }
    }
    return true ;
}

void solve() {
    // solve ;
    int n {}  ;
    cin >> n ;
    vector<pair<int , int>> segments(n , make_pair(0 , 0) ) ;
    for(int i{} ; i < n ;i++){
        int l {} , r{} ;
        cin >> l >> r ;
        segments[i].first = l ;
        segments[i].second = r ; 
    }

    int left = 0 ;
    int right = (int)1e9 ;
    int ans {} ;
    while(left <= right ){
        int k = (left + right)/2 ;
        if(valid_k(k , segments)){
            ans = k ;
            right = k-1 ;
        }else{
            left = k+ 1 ;
        }
    }

    cout << ans << endl ;
    return ;


}

int32_t main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
    freopen("output.txt", "w", stdout);
#endif

    clock_t z = clock();

    int t = 1;
    // caculate_factorial() ;
    std::cin >> t;
    while (t--) solve();
    
    // std::cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}