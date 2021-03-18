#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
//#define DEBUG
void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    freopen("b.out", "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 72;
int grid[maxn][maxn], dp[maxn][maxn][maxn][maxn];

int main() {
    setIO();

    int n, m, k;
    cin >> n >> m >> k;
    for (auto &i : dp) {
        for (auto &j : i) {
            for (auto &l : j) {
                for (int &i1 : l) {
                    i1 = -inf;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            dp[i][j][1][grid[i][j] % k] = grid[i][j];
        }
    }
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            for (int take = 0; take < m; ++take) {
                for (int rem = 0; rem < k; ++rem) {
                    int cur = dp[x][y][take][rem];
                    if (y != m - 1) {
                        dp[x][y + 1][take][rem] = max(dp[x][y + 1][take][rem], cur);
                        if (take < m / 2) {
                            dp[x][y + 1][take + 1][(rem + grid[x][y + 1]) % k] = max(dp[x][y + 1][take + 1][(rem + grid[x][y + 1]) % k], cur + grid[x][y + 1]);
                        }
                    } else {
                        if (x != n - 1) {
                            dp[x + 1][0][0][rem] = max(dp[x + 1][0][0][rem], cur);
                            dp[x + 1][0][1][(rem + grid[x + 1][0]) % k] = max(dp[x + 1][0][1][(rem + grid[x + 1][0]) % k], cur + grid[x + 1][0]);
                        }
                    }
                }
            }
        }
    }
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int l = 0; l < m; ++l) {
#ifdef DEBUG
                cout << dp[i][j][l][0] << "\n";
#endif
                sol = max(sol, dp[i][j][l][0]);
            }
        }
    }
    cout << sol << "\n";
    return 0;
}
