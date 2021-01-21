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

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;


int main() {
    setIO();

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        char grid[n][m];
        long long dp[n][m];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> grid[i][j];
            }
        }
        long long col_sum[m];
        memset(col_sum, 0, sizeof(col_sum));
        for (int i = 0; i < n; ++i) {
            long long row_sum = 0;
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '*') {
                    row_sum = 0;
                    col_sum[j] = 0;
                } else {
                    dp[i][j] += row_sum + col_sum[j];
                    dp[i][j] %= mod;
                    col_sum[j] += dp[i][j];
                    row_sum += dp[i][j];
                }
            }
        }
        cout << dp[n - 1][m - 1] << "\n";
    }
    return 0;
}
