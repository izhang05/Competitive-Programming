#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}

const int mod = 1e9 + 7;

int main() {
    setIO();

    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < x + 1; ++j) {
            if (j - coins[i] >= 0) {
                dp[j] += dp[j - coins[i]];
                dp[j] %= mod;
            }
        }
    }

    cout << dp[x] << "\n";
    return 0;
}
