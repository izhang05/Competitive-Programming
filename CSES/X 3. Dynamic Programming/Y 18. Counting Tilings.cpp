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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 11, maxm = 1e3 + 5;
long long dp[2][1 << maxn];

int main() {
    setIO("18");
    int n, m;
    cin >> n >> m;
    dp[0][0] = 1;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int mask = 0; mask < (1 << n); ++mask) {
                dp[1][mask] = dp[0][mask ^ (1 << j)];
                if (j && !(mask & (1 << j)) && !(mask & (1 << (j - 1)))) {
                    dp[1][mask] += dp[0][mask ^ (1 << (j - 1))];
                }
                dp[1][mask] %= mod;
            }
            swap(dp[0], dp[1]);
        }
    }
    cout << dp[0][0] << "\n";
    return 0;
}
