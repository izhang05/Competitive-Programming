#pragma GCC target("avx2")
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
void print(T a) {
    for (auto i : a) {
        cout << i << " ";
    }
    cout << "\n";
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 20;
int dp[1 << maxn][maxn];
vector<int> adj[maxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
    }
    dp[1][0] = 1;
    for (int mask = 1; mask < (1 << (n - 1)); ++mask) {
        int cur_mask = mask;
        while (cur_mask != 0) {
            int i = __builtin_ctz(cur_mask);
            cur_mask ^= 1 << i;
            if (mask & 1 << i) {
                for (int j : adj[i]) {
                    if (!(mask & 1 << j)) {
                        dp[mask ^ 1 << j][j] += dp[mask][i];
                        if (dp[mask ^ 1 << j][j] >= mod) {
                            dp[mask ^ 1 << j][j] -= mod;
                        }
                    }
                }
            }
        }
    }
    cout << dp[(1 << n) - 1][n - 1] << "\n";
    return 0;
}
