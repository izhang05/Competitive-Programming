#include <bits/stdc++.h>

using namespace std;

const int maxn = 55;

long long dp[maxn][2]; // dp[pos][red/black]

int main() {
    int n = 50;
    dp[0][1] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
        for (int j = 0; j <= i - 3; ++j) {
            dp[i][0] += dp[j][1];
        }
    }
    cout << dp[n][0] + dp[n][1] << "\n";
    return 0;
}
