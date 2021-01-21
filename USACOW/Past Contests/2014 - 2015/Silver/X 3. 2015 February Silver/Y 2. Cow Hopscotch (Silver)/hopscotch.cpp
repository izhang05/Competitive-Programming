/*
ID: izhang01
TASK: hopscotch
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("hopscotch.in", "r", stdin);
    freopen("hopscotch.out", "w", stdout);
}

const int mod = 1e9 + 7, maxn = 101;
int r, c, k, dp[maxn][maxn], grid[maxn][maxn];

int main() {
    setIO();
    cin >> r >> c >> k;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> grid[i][j];
        }
    }
    dp[0][0] = 1;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            for (int l = i + 1; l < r; ++l) {
                for (int m = j + 1; m < c; ++m) {
                    if (grid[i][j] != grid[l][m]) {
                        dp[l][m] += dp[i][j];
                        dp[l][m] %= mod;
                    }
                }
            }
        }
    }

    cout << dp[r - 1][c - 1] << "\n";
    return 0;
}
