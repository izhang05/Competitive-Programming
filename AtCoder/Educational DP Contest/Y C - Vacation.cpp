#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}

const int maxn = 1e5;
int dp[maxn][3];

int main() {
    setIO();

    int n;
    cin >> n;
    int val[n][3];
    for (int i = 0; i < n; ++i) {
        cin >> val[i][0] >> val[i][1] >> val[i][2];
    }
    dp[0][0] = val[0][0];
    dp[0][1] = val[0][1];
    dp[0][2] = val[0][2];
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (j != k) {
                    dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + val[i + 1][k]);
                }
            }
        }
    }
    cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << "\n";
    return 0;
}
