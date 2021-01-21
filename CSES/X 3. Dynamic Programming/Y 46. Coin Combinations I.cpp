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
    for (int i = 1; i < x + 1; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i - coins[j] >= 0) {
                dp[i] += dp[i - coins[j]];
                dp[i] %= mod;

            }
        }
    }

    cout << dp[x] << "\n";
    return 0;
}
