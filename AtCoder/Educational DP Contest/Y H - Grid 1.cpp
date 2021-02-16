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
const int mod = 1e9 + 7;

int main() {
    setIO();
    int h, w;
    cin >> h >> w;
    char grid[h][w];
    int dp[h][w];
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] == '#') {
                continue;
            }
            if (i > 0) {
                dp[i][j] += dp[i - 1][j];
                dp[i][j] %= mod;
            }
            if (j > 0) {
                dp[i][j] += dp[i][j - 1];
                dp[i][j] %= mod;
            }
        }
    }
    cout << dp[h - 1][w - 1] << "\n";
    return 0;
}
