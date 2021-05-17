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

#define int long long
const int inf = 1e18, mod = 1e9 + 7, maxn = 1e4 + 5;

int dp[maxn];

signed main() {
    setIO("1");

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        dp[i] = inf;
    }
    vector<int> a(n), pre(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pre[i] = pre[max(0ll, i - 1)] ^ a[i];
        dp[i] = pre[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            dp[j] = min(dp[j], dp[i] + (pre[j] ^ pre[i]));
        }
    }
    int mn = dp[n - 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i) {
        dp[i] = pre[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            dp[j] = max(dp[j], dp[i] + (pre[j] ^ pre[i]));
        }
    }
    cout << dp[n - 1] - mn << "\n";
    return 0;
}
