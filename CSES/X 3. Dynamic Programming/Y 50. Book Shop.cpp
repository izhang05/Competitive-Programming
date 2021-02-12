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

const int maxn = 1001, maxw = 1e5 + 1;
int dp[maxn][maxw];

int main() {
    setIO();
    int n, w;
    cin >> n >> w;
    int h[n], s[n];
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j = 0; j < w + 1; ++j) {
            dp[i][j] = 0;
        }
        dp[i][h[i]] = s[i];
    }
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < w + 1; ++j) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if (j + h[i + 1] <= w && i + 1 < n) {
                dp[i + 1][j + h[i + 1]] = max(dp[i + 1][j + h[i + 1]], dp[i][j] + s[i + 1]);
            }
            if (i == n - 1) {
                sol = max(sol, dp[i][j]);
            }
        }
    }
    cout << sol << "\n";
    return 0;
}
