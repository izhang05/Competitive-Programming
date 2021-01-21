#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
int dp[5000][5000], suf[5000][5000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    dp[0][0] = 1;
    char statement[n];
    for (int i = 0; i < n; ++i) {
        cin >> statement[i];
    }

    for (int i = 1; i < n; ++i) {
        suf[i - 1][n - 1] = dp[i - 1][n - 1];
        for (int j = n - 2; j >= 0; --j) {
            suf[i - 1][j] = (suf[i - 1][j + 1] + dp[i - 1][j]) % mod;
        }
        for (int j = 0; j < n; ++j) {
            if (statement[i - 1] == 'f') {
                if (j != 0) {
                    dp[i][j] = dp[i - 1][j - 1];
                }

            } else {
                dp[i][j] = suf[i - 1][j];
            }

        }
    }
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        sol = (sol + dp[n - 1][i]) % mod;
    }
    cout << sol << "\n";
    return 0;
}
