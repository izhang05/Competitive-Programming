#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5, m = 50, limit = 1e6;


long long dp[maxn][2]; // dp[pos][red/black]

int main() {
    dp[0][1] = 1;
    for (int i = 1;; ++i) {
        dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
        for (int j = 0; j <= i - m; ++j) {
            dp[i][0] += dp[j][1];
        }
        if (dp[i][0] + dp[i][1] > limit) {
            cout << i << "\n";
            break;
        }
    }
    return 0;
}
