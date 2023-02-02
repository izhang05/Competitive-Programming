#include <bits/stdc++.h>

using namespace std;

const int n = 20;

long long dp[n + 1][10];

int main() {
    for (int i = 0; i < 10; ++i) {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k + j < 10; ++k) {
                dp[i][j + k] += dp[i - 1][k];
            }
        }
    }
    long long sol = 0;
    for (int i = 0; i < 10; ++i) {
        sol += dp[n][i];
    }
    cout << sol << "\n";
    return 0;
}
