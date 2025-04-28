#include<bits/stdc++.h>

using namespace std;

const int mxk = 30, mxn = 1000;
long long dp[mxk][mxn];

long long solve(int k, int n) {
    if (dp[k][n] != -1) {
        return dp[k][n];
    }
    dp[k][n] = 0;
    for (int i = 0; i <= n / 2; ++i) {
        dp[k][n] += dp[k - 1][i];
    }
    return dp[k][n];
}

int main() {
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 0; i < 30; ++i) {
        cout << i << ": ";
        for (int j = 0; j < 100; ++j) {
            cout << solve(i, j) << " ";
        }
        cout << "\n";
    }

}