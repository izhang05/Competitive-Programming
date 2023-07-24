#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T>
using indexed_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}
//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    //    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".in").c_str(), "r", stdin);
#endif
}
const int inf = 0x3f3f3f3f, maxn = 1e5 + 5;
int mod, parent[maxn];
vector<int> adj[maxn];
long long dp[2][maxn]; // dp[down / up][node]
vector<long long> pre[maxn], suf[maxn];

void dfs1(int c, int p) {
    dp[0][c] = 1;
    parent[c] = p;
    vector<long long> cur;
    for (int i : adj[c]) {
        if (i != p) {
            dfs1(i, c);
            cur.push_back(dp[0][i] + 1);
            dp[0][c] *= dp[0][i] + 1;
            dp[0][c] %= mod;
        }
    }
    long long prod = 1;
    for (long long i : cur) {
        prod *= i;
        prod %= mod;
        pre[c].push_back(prod);
    }
    prod = 1;
    for (int i = (int) cur.size() - 1; i >= 0; --i) {
        prod *= cur[i];
        prod %= mod;
        suf[c].push_back(prod);
    }
    reverse(suf[c].begin(), suf[c].end());
}
void dfs2(int c, int p, int count) {
    dp[1][c] = 1;
    if (c != 0) {
        if (count - 1 >= 0) {
            dp[1][c] *= pre[p][count - 1];
        }
        if (count + 1 < (int) pre[p].size()) {
            dp[1][c] *= suf[p][count + 1];
        }
        dp[1][c] %= mod;
        dp[1][c] *= dp[1][p];
        ++dp[1][c];
        dp[1][c] %= mod;
    }
    int co = 0;
    for (int i : adj[c]) {
        if (i != p) {
            dfs2(i, c, co++);
        }
    }
}

int main() {
#ifdef LOCAL
    auto start_time = std::chrono::high_resolution_clock::now();
#endif
    setIO("V");
    int n;
    cin >> n >> mod;
    int a, b;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(0, -1);
    dfs2(0, -1, 0);
    for (int i = 0; i < n; ++i) {
#ifdef DEBUG
        cout << i << " " << dp[0][i] << " " << dp[1][i] << "\n";
#endif
        long long sol = dp[0][i] * dp[1][i];
        cout << sol % mod << "\n";
    }
#ifdef LOCAL
    auto end_time = std::chrono::high_resolution_clock::now();
    cout << setprecision(6) << fixed;
    cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end_time - start_time).count() << " seconds" << endl;
#endif
    return 0;
}
