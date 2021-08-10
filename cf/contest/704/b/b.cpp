/* Author: izhang05
 * Time: 08-09-2021 23:50:23
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 5005;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

long long dp[maxn][maxn], x[maxn], a[maxn], b[maxn], c[maxn], d[maxn];
template<class T>
bool ckmin(T &a, const T &b) {
    return b < a ? a = b, 1 : 0;
} // set a = min(a,b)

void solve() {
    memset(dp, 0x3f, sizeof(dp));
    int n, s, e;
    cin >> n >> s >> e;
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            long long &cur = dp[i][j];
            if (i == s) {
                // create new component
                ckmin(cur, dp[i - 1][j - 1] - x[i] + d[i]);

                // add to existing on left side
                if (j > 1 || s < e || i == n) {
                    ckmin(cur, dp[i - 1][j] + x[i] + c[i]);
                }

            } else if (i == e) {
                // create new component
                ckmin(cur, dp[i - 1][j - 1] - x[i] + b[i]);

                // add to existing on right side
                if (j > 1 || e < s || i == n) {
                    ckmin(cur, dp[i - 1][j] + x[i] + a[i]);
                }

            } else if (i == n) {
                // merge
                ckmin(cur, dp[i - 1][j + 1] + 2 * x[i] + a[i] + c[i]);
            } else {
                // create new component
                ckmin(cur, dp[i - 1][j - 1] - 2 * x[i] + b[i] + d[i]);

                // add to existing
                // add on the right side
                if (j > 1 || i < e) {
                    ckmin(cur, dp[i - 1][j] + a[i] + d[i]);
                }
                // add on the left side
                if (j > 1 || i < s) {
                    ckmin(cur, dp[i - 1][j] + b[i] + c[i]);
                }

                // merge
                if (j - (i > e) - (i > s) >= 0) {
                    ckmin(cur, dp[i - 1][j + 1] + 2 * x[i] + a[i] + c[i]);
                }
            }
            //            cout << i << " " << j << " " << dp[i][j] << "\n";
        }
    }
    cout << dp[n][1] << "\n";
}

int main() {
    setIO("6");

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
