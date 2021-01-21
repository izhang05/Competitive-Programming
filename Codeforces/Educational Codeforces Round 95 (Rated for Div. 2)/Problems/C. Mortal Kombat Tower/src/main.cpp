#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 1, inf = 1e9;
int dp[maxn][2]; // dp[loc(not including loc)][player]

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            for (int j = 0; j < 2; ++j) {
                dp[i][j] = inf;
            }
        }
        dp[n][0] = inf, dp[n][1] = inf;
        dp[0][0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 2; ++j) {
                int cur = dp[i][j];
                if (j == 0) {
                    cur += a[i];
                }
                for (int k = i + 1; k < i + 3 && k <= n; ++k) {
                    dp[k][1 - j] = min(dp[k][1 - j], cur);
                    if (j == 0) {
                        cur += a[k];
                    }
                }
            }
        }
        cout << min(dp[n][0], dp[n][1]) << "\n";
    }
    return 0;
}
