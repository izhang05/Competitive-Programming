#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}

const int maxn = 1001, mod = 1e9 + 7;
int dp[maxn][maxn];

int main() {
    setIO();

    int n;
    cin >> n;
    char grid[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    dp[0][0] = grid[0][0] != '*';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i + 1 < n && grid[i + 1][j] != '*') {
                dp[i + 1][j] += dp[i][j];
                dp[i + 1][j] %= mod;
            }
            if (j + 1 < n && grid[i][j + 1] != '*') {
                dp[i][j + 1] += dp[i][j];
                dp[i][j + 1] %= mod;
            }
        }
    }
    cout << dp[n - 1][n - 1] << "\n";
    return 0;
}
