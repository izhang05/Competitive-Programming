/* Author: izhang05
 * Time: 06-21-2021 16:25:06
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
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 18;
long double dp[1 << maxn], a[maxn][maxn];

int main() {
    cout << fixed << setprecision(6);
    setIO("3");
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    dp[(1 << n) - 1] = 1;
    for (int mask = (1 << n) - 1; mask >= 0; --mask) {
#ifdef DEBUG
        cout << mask << " " << dp[mask] << "\n";
#endif
        int cnt = __builtin_popcount(mask);
        if (cnt <= 1) {
            continue;
        }
        long double cur = dp[mask];
        int pairs = (cnt * (cnt - 1)) / 2;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                long double prob = 0;
                for (int j = 0; j < n; ++j) {
                    if (i != j && mask & (1 << j)) {
                        prob += (cur * a[j][i]) / pairs;
                    }
                }
                dp[mask ^ (1 << i)] += prob;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << dp[1 << i] << " \n"[i == n - 1];
    }
    return 0;
}
