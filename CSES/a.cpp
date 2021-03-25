#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
//#define DEBUG
void setIO(string name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, maxn = 5e2 + 5;
long long dp[maxn][maxn][maxn]; // dp[ind][lines][bugs]

int main() {
    setIO("1");
    int n, m, b, mod;
    cin >> n >> m >> b >> mod;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    dp[0][0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= m; ++j) {
            for (int k = 0; k <= b; ++k) {
                long long cur = dp[i][j][k];
#ifdef DEBUG
                cout << i << " " << j << " " << k << " " << cur << "\n";
#endif
                if (cur == 0) {
                    continue;
                }
                if (k + a[i] <= b) {
                    dp[i][j + 1][k + 1] += cur;
                    dp[i][j + 1][k + 1] %= mod;
                }
                dp[i + 1][j][k] += cur;
                dp[i + 1][j][k] %= mod;
            }
        }
    }
    long long sol = 0;
    for (int j = 0; j <= b; ++j) {
        sol += dp[n - 1][m][j];
        sol %= mod;
    }
    cout << sol << "\n";
    return 0;
}
