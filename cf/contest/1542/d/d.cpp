/* Author: izhang05
 * Time: 07-03-2021 09:05:10
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 998244353, maxn = 505;

long long dp[maxn][maxn]; // dp[i][j] number of ways to get to position[i] with exactly j numbers <= than k (not including k)

int main() {
    setIO("4");

    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        if (c == '+') {
            a[i].first = 1;
            cin >> a[i].second;
        }
    }
    long long sol = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i].first) {
#ifdef DEBUG
            cout << "i: " << i << "\n";
#endif
            memset(dp, 0, sizeof(dp));
            dp[0][0] = 1;
            if (i != 0) {
                if (!a[0].first) {
                    ++dp[0][0];
                } else if (a[0].second <= a[i].second) {
                    ++dp[0][1];
                } else {
                    ++dp[0][0];
                }
            }
#ifdef DEBUG
            cout << "j: " << 0 << "\n";
            for (int k = 0; k < n; ++k) {
                cout << dp[0][k] << "\n";
            }
#endif
            for (int j = 1; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    dp[j][k] = dp[j - 1][k];
                }
                if (i != j) {
                    if (!a[j].first) {
                        for (int k = 1; k < n; ++k) {
                            dp[j][k - 1] += dp[j - 1][k];
                            dp[j][k - 1] %= mod;
                        }
                        if (j < i) {
#ifdef DEBUG
                            cout << j << " " << i << "\n";
#endif

                            dp[j][0] += dp[j - 1][0];
                            dp[j][0] %= mod;
                        }
                    } else if (a[j].second < a[i].second || (a[j].second == a[i].second && j < i)) {
                        for (int k = 0; k < n; ++k) {
                            dp[j][k + 1] += dp[j - 1][k];
                            dp[j][k + 1] %= mod;
                        }
                    } else {
                        for (int k = 0; k < n; ++k) {
                            dp[j][k] += dp[j - 1][k];
                            dp[j][k] %= mod;
                        }
                    }
                }
#ifdef DEBUG
                cout << "j: " << j << "\n";
                for (int k = 0; k < n; ++k) {
                    cout << dp[j][k] << "\n";
                }
#endif
            }
            long long cur = 0;
            for (int j = 0; j < n; ++j) {
                cur += dp[n - 1][j];
                cur %= mod;
            }
            sol += (cur * a[i].second) % mod;
#ifdef DEBUG
            cout << "add: " << (cur * a[i].second) % mod << "\n";
#endif
            sol %= mod;
        }
    }
    cout << sol << "\n";
    return 0;
}