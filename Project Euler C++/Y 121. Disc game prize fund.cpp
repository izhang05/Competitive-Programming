#include <bits/stdc++.h>

using namespace std;

const int n = 15;

long double dp[n + 1][n + 1]; // dp[i][j] = prob of j blue disks after i turns

int main() {
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            dp[i][j] = (long double) i * dp[i - 1][j] / (i + 1);
            if (j) {
                dp[i][j] += (long double) dp[i - 1][j - 1] / (i + 1);
            }
        }
    }
    long double p = 0;
    for (int i = n / 2 + 1; i <= n; ++i) {
        p += dp[n][i];
    }
    cout << floor(1 / p) << "\n";
    return 0;
}
