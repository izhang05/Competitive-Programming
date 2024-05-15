#include <bits/stdc++.h>

using namespace std;

const int n = 15;

int grid[n][n], dp[n + 1][1 << n];

int main() {
    freopen("Y 345.txt", "r", stdin);

    for (auto &i: grid) {
        for (int &j: i) {
            cin >> j;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < (1 << n); ++j) {
            for (int k = 0; k < n; ++k) {
                if (j & (1 << k)) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j ^ (1 << k)] + grid[i - 1][k]);
                }
            }
        }
    }
    cout << dp[n][(1 << n) - 1] << "\n";
    return 0;
}
