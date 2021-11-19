#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, n = 80;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
long long grid[n][n], dp[n][n];

int main() {
    freopen("Y 82.txt", "r", stdin);
    for (auto &i : grid) {
        for (auto &j : i) {
            cin >> j;
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i < n; ++i) {
        dp[i][0] = grid[i][0];
    }
    for (int j = 1; j < n; ++j) {
        long long cur_min = INFL;
        for (int i = n - 1; i >= 0; --i) {
            cur_min = min(cur_min, dp[i][j - 1]);
            cur_min += grid[i][j];
            dp[i][j] = cur_min;
        }
        cur_min = INFL;
        for (int i = 0; i < n; ++i) {
            cur_min = min(cur_min, dp[i][j - 1]);
            cur_min += grid[i][j];
            dp[i][j] = min(dp[i][j], cur_min);
        }
    }
    long long sol = INFL;
    for (auto &i : dp) {
        sol = min(sol, i[n - 1]);
    }
    cout << sol << "\n";
    return 0;
}
