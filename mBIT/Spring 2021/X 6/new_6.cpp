// You told me...
// At your absolute best, you still won't be good enough for the wrong person... 
// At your worst, you'll still be worth it to the right person...
 
// ............................................................................................
// It was good while it lasted, good bye...                                                   .
// I believe I really loved you... to that point that I always want to hear your voice...     .
// But before my hand could reach you... you seem to be slowly disappearing from my sight...  .
// ............................................................................................
 
#pragma GCC optimize ("Ofast,unroll-loops")
// #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
 
#define pb push_back
#define ff  first
#define ss second
#define tm1 first
#define tm2 second.first
#define tm3 second.second
#define sz(x) ll(x.size())
#define fill(x, v) memset(x, v, sizeof(x))
#define all(v) (v).begin(), (v).end()
#define FER(i,a,b) for(ll i=ll(a); i< ll(b); ++i)
#define IFR(i,a,b) for(ll i=ll(a); i>=ll(b); --i )
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
 
#define N 680005 
// #define mod1 1000000007
#define mod1 998244353
// #define mod2 1000000009
#define bas 987625403
#define sqr(x) (x)*(x)  
#define INF 2e18
 
using namespace std;
using namespace __gnu_pbds;
 
 
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ii > tri;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> S_t;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

#define trace(...) fff(#__VA_ARGS__, __VA_ARGS__)
template<typename t> void fff(const char* x, t&& val1) { cout<<x<< " : "<<val1<<"\n";}
template<typename t1, typename... t2> void fff(const char* x, t1&& val1, t2&&... val2){
    const char* xd=strchr(x+1, ',');
    cout.write(x, xd-x)<<" : "<<val1<<" | ";
    fff(xd+1, val2...);
}

 
inline ll add(ll a, ll b, ll mod) { return a+b < mod? a+b : a+b-mod;}
inline ll rem(ll a, ll b, ll mod) { return a >= b? a - b: a- b + mod;}
inline ll mul(ll a, ll b, ll mod) { return (long long) a*b%mod;}
inline void Mul(ll &a, ll b, ll mod) { a = (long long) a*b%mod;}
inline ll bp(ll a, ll p, ll mod){
    ll ret;
    for(ret = 1; p; p>>=1, Mul(a, a, mod)) (p & 1) && (Mul(ret, a, mod), 1);
    return ret;
}
 
static inline void read(ll &result) {
    bool minus = false;
    char ch;
    ch = getchar();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' and ch <= '9') break;
        ch = getchar();
    }
    (ch == '-')? minus = true: result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' or ch > '9') break;
        result = (result<<3)+ (result<<1) + (ch - '0');
    }
    if(minus) result = -result;
}

string tab[1<<20];
vii adj[1<<20];
set<ii> graph[1<<20];
ll vis[1<<20], idx[1<<20], qp[1<<20];

inline ll find(ll x){
    while(x != idx[x]) idx[x] = idx[idx[x]], x = idx[x];
    return x;
}

inline void unir(ll a, ll b){
    ll p = find(a), q = find(b);
    idx[p] = idx[q];
}

inline void dfs(ll u, ll col, vi &vec){
    vis[u]++;
    vec.pb(u);
    for(auto [v, w]: adj[u]) if(!vis[v] and w == col) {
        dfs(v, w, vec);
    }
}

ll dp[1<<20][3];

inline void go(ll u, ll pp, ll color){
    ll ans1 = 0, ans2 = 0, ta = 0;
    for(auto [v, w]: graph[u]) if(v != pp){
        go(v, u, w);
        ans1 += dp[v][1];
        ans2 += dp[v][2];
        ta++;
    }
    if(color == 1){
        dp[u][1] = min(ans1, ans2 + 2);
        dp[u][2] = min(dp[u][1] + 1, ans2 + 1);
    }
    else{
        dp[u][2] = min(ans2, ans1 + 2);
        dp[u][1] = min(dp[u][2] + 1, ans1 + 1);
    }
}



int main(){
    fastio;
    ll n, m; cin>>n>>m;
    FER(i, 0, n) cin>>tab[i];
    auto id = [&](ll i, ll j){
        return i * m + j;
    };
    FER(i, 0, n) {
        FER(j, 0, m - 1){
            auto x = tab[i][j] == '0'? 1 : 2;
            auto y = tab[i][j + 1] == '0'? 1: 2;
            adj[id(i, j)].pb({id(i, j + 1), y});
            adj[id(i, j + 1)].pb({id(i, j), x});
        }
    }
    FER(i, 0, n - 1){
        FER(j, 0, m){
            auto a = id(i, j);
            auto b = id(i + 1, j);
            auto x = tab[i][j] == '0'? 1: 2;
            auto y = tab[i + 1][j] == '0'? 1: 2;
            adj[a].pb({b, y});
            adj[b].pb({a, x});
            if(i&1){
                if(j){
                    auto c = id(i + 1, j - 1);
                    auto z = tab[i + 1][j - 1] == '0'? 1: 2;
                    adj[a].pb({c, z});
                    adj[c].pb({a, x});
                }
            }
            else{
                if(j < m - 1){
                    auto c = id(i + 1, j + 1);
                    auto z = tab[i + 1][j + 1] == '0'? 1: 2;
                    adj[a].pb({c, z});
                    adj[c].pb({a, x});    
                }
            }
        }
    }
    FER(i, 0, n * m) idx[i] = i;
    FER(i, 0, n * m){
        if(!vis[i]){
            auto x = i/m;
            auto y = i%m;
            auto color = tab[x][y] == '0'? 1: 2;
            vi vec;
            dfs(i, color, vec);
            FER(j, 0, sz(vec) - 1){
                unir(vec[j], vec[j + 1]);
            }
        }
    }
    ll p = 1;
    auto compre = [&](ll x){
        if(qp[x]) return qp[x];
        qp[x] = p++;
        return qp[x];
    };
    ll node = -1, cot = -1;
    FER(u, 0, n * m){
        for(auto [v, w]: adj[u]){
            if(find(v) != find(u)){
                auto x = compre(find(v));
                auto y = compre(find(u));
                auto a1 = u/m;
                auto b1 = u%m;
                auto a2 = v/m;
                auto b2 = v%m;
                // color1 es de u -> y
                // color2 es de v -> x
                auto color1 = tab[a1][b1] == '0'? 1: 2;
                auto color2 = tab[a2][b2] == '0'? 1: 2;
                graph[y].insert({x, color2});
                node = x, cot = color2;
            }
        }
    }
    go(node, 0, cot);
    auto BunChan = min(dp[node][1], dp[node][2]);
    cout<<BunChan<<"\n";
    return 0;
}