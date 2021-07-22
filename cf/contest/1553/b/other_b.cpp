//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("O2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
////
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#include <bits/stdc++.h>

#include <random>

#define all(x) (x).begin(), (x).end()
#define allp(x) (x)->begin(), (x)->end()

#define pb push_back

using namespace std;
void dout() { cerr << endl; }
//typedef long long ll;
template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
    cerr << H << ' ';
    dout(T...);
}

using ll = long long;
//#ifdef __int128
//using hll = __int128;
//#endif
using pii = pair<ll, ll>;
using ld = long double;
using pll = pair<long long, long long>;

template <typename T>
void do_uniq(vector<T> vec){
    sort(all(vec));
    vec.resize(unique(all(vec)) - vec.begin());
}

clock_t timestamp_start = clock();
void time_calc()
{
    cerr << (ld)(clock() - timestamp_start) / CLOCKS_PER_SEC << "\n";
}


#ifdef _getchar_nolock
#else
#define _getchar_nolock getchar_unlocked
#endif

//#define solvsh
#define multi

ll mod = 1e9 + 7;

ll add(ll a, ll b){
    return (a + b) % mod;
}
ll ml(ll a, ll b) {
    return (a * b) % mod;
}

ll sub(ll a, ll b) {
    return add(a, mod - b);
}

ll b_p(ll b, ll p) {
    if (p == 0) return 1;
    if (p & 1) return ml(b, b_p(b, p ^ 1));
    ll v = ml(b, p >> 1);
    return ml(v, v);
}

const int MAXN = 3e2 + 32;

int ss(int i){

    int ret = 0;

    while (i) {
        ret += i % 10;
        i /= 10;
    }

    return ret;
}

void solve() {

    string s, t;
    cin >> s >> t;

    reverse(all(t));



    for (int i = 0; i < s.size(); ++ i) {

        if (s[i] != t[0]) continue;

        int j = 0;
        while (i + j + 1 < s.size() && j + 1 < t.size() && s[i + j + 1]  == t[j + 1]) {
            ++j;
        }

        int mmx = 0;
        int j1 = j;
        int j2 = j;
        while (j1 - 1 >= 0 && j2 + 1 < t.size() && t[j1 - 1] == t[j2 + 1]) {
            --j1;
            ++j2;
        }

        j = j2;

        int i1 = i;

        while (j + 1 < t.size() && i1 - 1 >= 0 && s[i1 - 1] == t[j + 1]) {
            ++j;
            --i1;
        }

        if (j == t.size() - 1) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

void multisolve() {
    int t;
    cin >> t;

    int i = 1;
    while (t--) {
        solve();
        i++;

//        time_calc();
    }
}


#ifdef STRESS
void stress() {

    while (1) {
        int n = 3;
        auto v = gen(n);

        auto answ =solve(n, v);

        if (!test(answ, n , v)) {
            for (auto e : v) {
                cerr << e.first.first << " " << e.first.second << " " << e.second << endl;
            }
            exit(1);
        } else {
            cerr << "OK!" << endl;
        }
    }
}
#endif

#define int int
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(20);

#ifdef multi
    //        gen();
    multisolve();
#else
    #ifndef STRESS
    solve();
#else
    stress();
#endif
//    gen();
#endif
    time_calc();
}