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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 16, maxg = 3;

long long dp[1 << maxn][maxg], ti[1 << maxn];

int main() {
    setIO("1");

    int n, t;
    cin >> n >> t;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        --a[i].second;
        dp[1 << i][a[i].second] = 1;
    }
    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                ti[mask] = ti[mask ^ (1 << i)] + a[i].first;
#ifdef DEBUG
                cout << mask << " " << ti[mask] << "\n";
#endif
                break;
            }
        }
    }
    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int i = 0; i < maxg; ++i) {
            long long cur = dp[mask][i];
            if (!cur) {
                continue;
            }
#ifdef DEBUG
            cout << mask << " " << i << " " << cur << "\n";
#endif
            for (int k = 0; k < n; ++k) {
                if (!(mask & (1 << k)) && a[k].second != i) {
                    int ne = mask | (1 << k);
                    dp[ne][a[k].second] += cur;
                    dp[ne][a[k].second] %= mod;
                }
            }
        }
    }

    long long sol = 0;
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < maxg; ++j) {
            if (ti[i] == t) {
                sol += dp[i][j];
                sol %= mod;
            }
        }
    }
    cout << sol << "\n";
    return 0;
}
