#include <bits/stdc++.h>

using namespace std;

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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e3 + 5;

long double dp[maxn][maxn]; // dp[time][people] = prob

int main() {
    setIO("1");
    int n, t;
    long double p;
    cin >> n >> p >> t;
    dp[0][0] = 1;
    for (int i = 1; i <= t; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (j < n) {
                dp[i][j] += dp[i - 1][j] * (1 - p);
            } else {
                dp[i][j] += dp[i - 1][j];
            }
            if (j > 0) {
                dp[i][j] += dp[i - 1][j - 1] * p;
            }
#ifdef DEBUG
            cout << i << " " << j << " " << dp[i][j] << "\n";
#endif
        }
    }
    long double sol = 0;
    for (int i = 0; i <= n; ++i) {
        sol += i * dp[t][i];
    }
    cout << fixed << setprecision(15) << sol << "\n";
    return 0;
}
