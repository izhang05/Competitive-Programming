/*
ID: izhang01
TASK: subset
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("subset.in", "r", stdin);
    freopen("subset.out", "w", stdout);
}
const int maxn = 41;
long long dp[maxn][maxn * maxn];

int main() {
    setIO();
    int n;
    cin >> n;
    int sum = (n * (n + 1)) / 2;
    if (sum % 2 != 0) {
        cout << 0 << "\n";
        return 0;
    }
    dp[0][0] = 1;
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 0; j < sum + 1; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j > 0) {
                dp[i][j] += dp[i - 1][j - i];
            }
        }
    }
    cout << dp[n - 1][sum / 2] << "\n";
    return 0;
}
