#include <bits/stdc++.h>

using namespace std;

const int n = 50;
long long dp[n + 1];

long long solve(int s) {
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1];
        if (i - s >= 0) {
            dp[i] += dp[i - s];
        }
    }
    return dp[n] - 1;
}

int main() {
    cout << solve(2) + solve(3) + solve(4) << "\n";
}
