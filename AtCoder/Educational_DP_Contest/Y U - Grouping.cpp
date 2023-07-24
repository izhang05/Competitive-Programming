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
const int mod = 1e9 + 7, maxn = 17;
const long long inf = 1e18;
int a[maxn][maxn];
vector<long long> dp, pre;


int main() {
    setIO("U");
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    pre.resize(1 << n);
#ifdef DEBUG
    cout << "pre:"
         << "\n";
#endif
    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
            if (!(mask & (1 << i))) {
                pre[mask | (1 << i)] = pre[mask];
                for (int j = 0; j < n; ++j) {
                    if (mask & (1 << j)) {
                        pre[mask | (1 << i)] += a[i][j];
                    }
                }
            }
        }
#ifdef DEBUG
        cout << mask << " " << pre[mask] << "\n";
#endif
    }
    dp.resize(1 << n);
    dp[0] = 0;
#ifdef DEBUG
    cout << "dp:"
         << "\n";
#endif
    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int sub = mask;; sub = (sub - 1) & mask) {
            dp[mask] = max(dp[mask], dp[mask ^ sub] + pre[sub]);
            if (sub == 0) {
                break;
            }
        }
#ifdef DEBUG
        cout << mask << " " << dp[mask] << "\n";
#endif
    }
    cout << dp[(1 << n) - 1] << "\n";
    return 0;
}
