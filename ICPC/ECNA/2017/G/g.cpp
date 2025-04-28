#include <bits/stdc++.h>

using namespace std;

const int mxn = 105;
long long c[mxn], cap[mxn];
long long dp[mxn][mxn][2]; // how many used, decreases used, last rest?

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    cap[0] = m;
    for (int i = 1; i < n + 1; ++i) {
        cap[i] = (cap[i - 1] * 2) / 3;
    }
    long long sol = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // take current
            dp[i + 1][j + 1][0] = max(dp[i + 1][j + 1][0], max(dp[i][j][0], dp[i][j][1]) + min(cap[j], c[i]));
            // don't take current
            // already rested
            dp[i + 1][0][1] = max(dp[i + 1][0][1], dp[i][j][1]);
            // not already rested
            dp[i + 1][max(0, j - 1)][1] = max(dp[i + 1][max(0, j - 1)][1], max(dp[i][j][0], dp[i][j][1]));
        }
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int k = 0; k < 2; ++k) {
                sol = max(sol, dp[i][j][k]);
            }
        }
    }
    cout << sol << "\n";
}