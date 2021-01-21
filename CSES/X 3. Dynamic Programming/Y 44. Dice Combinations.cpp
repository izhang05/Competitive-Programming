#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}
const int maxn = 1e6, mod = 1e9 + 7;
long long dp[maxn + 1];


int main() {
    setIO();

    int n;
    cin >> n;
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= 6 && i + j <= n; ++j) {
            dp[i + j] += dp[i];
            dp[i + j] %= mod;
        }
    }
    cout << dp[n] << "\n";
    return 0;
}
