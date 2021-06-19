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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 21;
int dp[1 << maxn], rem[1 << maxn];

int main() {
    setIO("c");

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    memset(dp, -1, sizeof(dp));
    for (int mask = 1; mask < (1 << m); ++mask) {
        for (int i = 0; i < m; ++i) {
            if (mask & (1 << i)) {
                int pre = mask ^ (1 << i);
                if (rem[pre] + b[i] == a[dp[pre] + 1]) {
                    dp[mask] = dp[pre] + 1;
                    rem[mask] = 0;
                } else {
                    if (dp[pre] >= dp[mask]) {
                        dp[mask] = dp[pre];
                        rem[mask] = rem[pre] + b[i];
                    }
                }
                if (dp[mask] == n - 1) {
#ifdef DEBUG
                    cout << mask << " " << dp[mask] << " " << rem[mask] << "\n";
#endif
                    cout << "YES\n";
                    return 0;
                }
            }
        }
#ifdef DEBUG
        cout << mask << " " << dp[mask] << " " << rem[mask] << "\n";
#endif
    }

    cout << "NO\n";
    return 0;
}
