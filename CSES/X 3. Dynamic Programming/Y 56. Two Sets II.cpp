#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}

const int mod = 1e9 + 7, maxn = 501;
long long dp[maxn * maxn][maxn];

int main() {
    setIO();

    int n;
    cin >> n;
    int sum = (n * (n + 1)) / 2;
    if (sum % 2 == 1) {
        cout << 0 << "\n";
        return 0;
    }
    dp[0][1] = dp[1][1] = 1;
    for (int i = 0; i < sum; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            dp[i][j] %= mod;
            dp[i + j + 1][j + 1] += dp[i][j];
            dp[i][j + 1] += dp[i][j];
        }
    }
    cout << dp[sum / 2][n - 1] << "\n";
    return 0;
}
