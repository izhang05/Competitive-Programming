/* Author: izhang05
 * Time: 07-01-2021 15:36:33
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifndef TEST
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const int maxn = 2505, mod = 1e9 + 7;
#define int long long
vector<pair<int, int>> adj[maxn];
unordered_map<int, pair<long long, long long>> dp; // dp[min(total length, y)] = {cnt, sum of all paths with cur length}
int comp[maxn], cur_comp = 0, n, m, x, y;
bool visited[maxn];
unordered_map<int, pair<long long, long long>> occ[maxn];

void dfs(int c, int p, int cost) {
    if (comp[c] == -1) {
        comp[c] = cur_comp;
    }
    if (p != -1) {
        occ[comp[c]][min(cost, y)].second += cost;
        occ[comp[c]][min(cost, y)].second %= mod;
        ++occ[comp[c]][min(cost, y)].first;
        occ[comp[c]][min(cost, y)].first %= mod;
    }
    for (auto &i : adj[c]) {
        if (i.first != p) {
            dfs(i.first, c, cost + i.second);
        }
    }
}

signed main() {
    setIO("mooriokart");
    cin >> n >> m >> x >> y;
    for (int i = 0; i < m; ++i) {
        int a, b, d;
        cin >> a >> b >> d;
        --a, --b;
        adj[a].emplace_back(b, d);
        adj[b].emplace_back(a, d);
    }
    memset(comp, -1, sizeof(comp));
    for (int i = 0; i < n; ++i) {
        if (comp[i] == -1) {
            dfs(i, -1, 0);
            ++cur_comp;
        } else {
            dfs(i, -1, 0);
        }
    }
    dp[min(cur_comp * x, y)] = {1, cur_comp * x};
    for (int i = 0; i < cur_comp; ++i) {
        unordered_map<int, pair<long long, long long>> new_dp;
        for (auto &j : occ[i]) {
            j.second.first *= 500000004; // mod inverse of 2
            j.second.first %= mod;
            j.second.second *= 500000004;
            j.second.second %= mod;
            for (auto &k : dp) {
                new_dp[min((k.first + j.first), y)].second += ((j.second.first * k.second.second) % mod + (j.second.second * k.second.first) % mod) % mod;
                new_dp[min((k.first + j.first), y)].second %= mod;
                new_dp[min((k.first + j.first), y)].first += (j.second.first * k.second.first) % mod;
                new_dp[min((k.first + j.first), y)].first %= mod;
            }
        }
        swap(dp, new_dp);
#ifdef DEBUG
        for (auto &j : dp) {
            cout << j.first << " " << j.second.first << " " << j.second.second << "\n";
        }
        cout << "\n";
#endif
    }
    long long sol = dp[y].second;
    for (int i = 1; i < cur_comp; ++i) {
        sol *= i;
        sol %= mod;
        sol *= 2;
        sol %= mod;
    }
    cout << sol << "\n";
    return 0;
}
