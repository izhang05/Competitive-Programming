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
const int mod = 1e9 + 7, maxn = 21;
const long long inf = 1e18;
bool grid[maxn][maxn];
long long dp[1 << maxn];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    dp[0] = 1;
    for (int mask = 0; mask < (1 << n) - 1; ++mask) {
        int i = __builtin_popcount(mask);
        for (int j = 0; j < n; ++j) {
            if (!(mask & (1 << j)) && grid[i][j]) {
                dp[mask ^ (1 << j)] += dp[mask];
                if (dp[mask ^ (1 << j)] >= mod) {
                    dp[mask ^ (1 << j)] -= mod;
                }
            }
        }
    }
    cout << dp[(1 << n) - 1] << "\n";
    return 0;
}
