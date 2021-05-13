#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 105;

int dp[maxn][maxn][maxn][2]; // dp[pos][even][odd][last]

int main() {
    setIO("1");

    int n;
    cin >> n;
    if (n == 1) {
        cout << 0 << "\n";
        return 0;
    }
    vector<int> a(n);
    int even = n / 2, odd = (n + 1) / 2;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] != 0) {
            if (a[i] % 2 == 0) {
                --even;
            } else {
                --odd;
            }
        }
    }
#ifdef DEBUG
    cout << even << " " << odd << "\n";
#endif
    memset(dp, 0x3f, sizeof(dp));
    dp[0][even][odd][0] = dp[0][even][odd][1] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                for (int l = 0; l < 2; ++l) {
                    int cur = dp[i][j][k][l];
                    if (cur == inf) {
                        continue;
                    }
#ifdef DEBUG
                    cout << i << " " << j << " " << k << " " << l << " " << cur << "\n";
#endif
                    if (a[i] != 0) {
                        dp[i + 1][j][k][a[i] % 2] = min(dp[i + 1][j][k][a[i] % 2], cur + (l != a[i] % 2));
                    } else {
                        if (j > 0) {
                            dp[i + 1][j - 1][k][0] = min(dp[i + 1][j - 1][k][0], cur + (l != 0));
                        }
                        if (k > 0) {
                            dp[i + 1][j][k - 1][1] = min(dp[i + 1][j][k - 1][1], cur + (l != 1));
                        }
                    }
                }
            }
        }
    }
    cout << min(dp[n][0][0][0], dp[n][0][0][1]) << "\n";
    return 0;
}
