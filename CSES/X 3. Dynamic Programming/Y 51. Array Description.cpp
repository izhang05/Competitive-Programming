#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}
const int maxn = 1e5 + 5, maxm = 105, mod = 1e9 + 7;
long long dp[maxn][maxm];


int main() {
    setIO();
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (a[0]) {
        dp[0][a[0]] = 1;
    } else {
        for (int i = 1; i < m + 1; ++i) {
            dp[0][i] = 1;
        }
    }

    for (int i = 1; i < n; ++i) {
        if (a[i]) {
            for (int j = max(1, a[i] - 1); j <= a[i] + 1; ++j) {
                dp[i][a[i]] += dp[i - 1][j];
            }
            dp[i][a[i]] %= mod;
        } else {
            for (int j = 0; j < m + 1; ++j) {
                for (int k = max(1, j - 1); k <= j + 1; ++k) {
                    dp[i][j] += dp[i - 1][k];
                }
                dp[i][j] %= mod;
            }
        }
    }
    long long sol = 0;
    for (int i = 1; i < m + 1; ++i) {
        sol += dp[n - 1][i];
    }
    cout << sol % mod << "\n";
    return 0;
}
