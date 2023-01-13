#include <bits/stdc++.h>

using namespace std;

const int n = 50;
long long dp[n + 1];

int main() {
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1];
        if (i - 2 >= 0) {
            dp[i] += dp[i - 2];
        }
        if (i - 3 >= 0) {
            dp[i] += dp[i - 3];
        }
        if (i - 4 >= 0) {
            dp[i] += dp[i - 4];
        }
    }
    cout << dp[n] << "\n";
    return 0;
}

