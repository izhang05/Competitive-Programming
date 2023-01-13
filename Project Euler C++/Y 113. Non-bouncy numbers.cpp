#include <bits/stdc++.h>

using namespace std;

const int n = 100;
long long dp[n + 1][10][3]; // dp[ind][last_digit][both,inc,dec]

int main() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < 10; ++j) {
            dp[i][j][0] = 1;
        }
        for (int j = 0; j < 10; ++j) {
            dp[i][j][0] += dp[i - 1][j][0];
            for (int k = 0; k < j; ++k) {
                dp[i][j][1] += dp[i - 1][k][1] + dp[i - 1][k][0];
            }
            dp[i][j][1] += dp[i - 1][j][1];
            dp[i][j][2] += dp[i - 1][j][2];
            for (int k = j + 1; k < 10; ++k) {
                dp[i][j][2] += dp[i - 1][k][2] + dp[i - 1][k][0];
            }
        }
    }
    long long sol = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 3; ++j) {
            sol += dp[n][i][j];
        }
    }
    cout << sol << "\n";
    return 0;
}
