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


// int dp(int v , string &s , int n ,auto &child ,  vector<int> &memo){
//     // base case
//     if(child[v][0] == 0 && child[v][1] == 0){
//         return 0 ;
//     }
//     // memo 
//     if(memo[v] != -1) return memo[v] ;
//     // current work 
//     int count {INT_MAX} ;
//     // left
//     if(child[v][0]){
//         if(s[v-1] == 'L'){
//             count = min(count , dp(child[v][0] , s , n , child , memo ) ) ;
//         }else{
//             count = min(count , dp(child[v][0] , s , n , child , memo )+1 ) ;
//         }
//     }
//     // right
//     if(child[v][1]){
//         if(s[v-1] == 'R'){
//             count = min(count , dp(child[v][1] , s , n , child , memo ) ) ;
//         }else{
//             count = min(count , dp(child[v][1] , s , n , child , memo )+1 ) ;
//         }
//     }

//     return memo[v] =  count ;
// }

// // 192 1276
// void solve() {
//     // solve ;
//     int n {} ;
//     string s ;
//     cin >> n ;
//     cin >> s ;
//     vector<vector<int>> child(n+1 , vector<int> {0 , 0 }) ;
//     for(int i {1} ; i <= n ; i++){
//         cin>> child[i][0] >> child[i][1] ;
//     }

//     vector<int> memo( n+1 , -1) ;
//     cout << dp(1 , s , n ,child , memo ) << endl ;
// }

class graph{
    private :
        int V ;
        vector<pair<int , int>> *adjList ;
    public :
        graph(int v){
            V = v ;
            adjList = new vector<pair<int , int>> [v] ;
        }

        void addEgde(int u , int v , int w  ){
            adjList[u].push_back({v , w}) ;
        }

        int dfs(int i , int par){
            int count {INT_MAX} ;
            for(auto nbrs : adjList[i]){
                count = min(count , dfs(nbrs.first , i)+ nbrs.second) ;
            }

            return count == INT_MAX ? 0 : count   ;
        }

};


void solve() {
    int n {} ;
    string s {} ;
    cin >>n ;
    graph g(n+1) ;
    cin >> s ;
    for(int i {1} ; i <= n ; i++){
        int l {} , r {} ;
        cin >> l >> r ;
        if(l){
            if(s[i-1] != 'L'){
                g.addEgde(i , l , 1) ;
            }else{
                g.addEgde(i , l , 0) ;
            }
        }
        if(r){
            if(s[i-1] != 'R'){
                g.addEgde(i , r , 1) ;
            }else{
                g.addEgde(i , r , 0) ;
            }
        }
    }

    int ans = g.dfs(1 , 0) ;
    cout << ans << endl ;
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