/* Author: izhang05
 * Time: 06-28-2021 23:24:51
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}
#define int long long
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;
vector<int> adj[maxn];
int dp[maxn], mn[maxn], mx[maxn], depth[maxn], val[maxn], par[maxn];
vector<vector<int>> nodes;

void dfs(int c, int p, int d) {
    depth[c] = d;
    nodes[d].push_back(c);
    par[c] = p;
    mn[d] = min(mn[d], val[c]);
    mx[d] = max(mx[d], val[c]);
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs(i, c, d + 1);
        }
    }
}

signed main() {
    setIO("1");

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        nodes.resize(n);
        for (int i = 0; i < n; ++i) {
            dp[i] = 0;
            mn[i] = inf;
            mx[i] = 0;
            adj[i].clear();
            nodes[i].clear();
        }
        for (int i = 1; i < n; ++i) {
            int a;
            cin >> a;
            --a;
            adj[i].push_back(a);
            adj[a].push_back(i);
        }
        for (int i = 1; i < n; ++i) {
            cin >> val[i];
        }
        dfs(0, -1, 0);
        int sol = -inf;
        for (int i = 1; i < n; ++i) {
            if (nodes[i].empty()) {
                break;
            }
            int mx_plus = -inf, mx_min = -inf;
            for (auto &j : nodes[i]) {
                mx_plus = max(mx_plus, dp[par[j]] + val[j]);
                mx_min = max(mx_min, dp[par[j]] - val[j]);
            }

            for (auto &j : nodes[i]) {
                dp[j] = max({dp[j], dp[par[j]] + mx[i] - val[j], dp[par[j]] + val[j] - mn[i]});
                dp[j] = max({dp[j], mx_plus - val[j], mx_min + val[j]});
                sol = max(sol, dp[j]);
            }
        }
        cout << sol << "\n";
    }
    return 0;
}
