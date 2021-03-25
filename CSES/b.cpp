#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
//#define DEBUG
void setIO(string name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;

int dp[maxn];
vector<int> adj[maxn];

int main() {
    setIO("b");

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    long long sol = 0;
    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
        for (auto j : adj[i]) {
            if (j < i) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        sol = max(sol, (long long) (dp[i] * 1ll * adj[i].size()));
    }
    cout << sol << "\n";
    return 0;
}
