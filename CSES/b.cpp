#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
//#define DEBUG
void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    freopen("b.out", "w", stderr);
#endif
}
const int mod = 1e9 + 7, maxn = 19;
long long dp[1 << maxn][maxn];
const long long inf = 1e18;

int main() {
    setIO();
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (auto &i : dp) {
        for (long long &j : i) {
            j = -inf;
        }
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        dp[1 << i][i] = a[i];
    }
    map<int, map<int, int>> rules;
    for (int i = 0; i < k; ++i) {
        int b, c, d;
        cin >> b >> c >> d;
        --b, --c;
        rules[b][c] = d;
    }
    long long sol = 0;
    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
#ifdef DEBUG
            cout << __builtin_popcount(mask) << "\n";
            cout << mask << " " << i << "\n";
            cout << dp[mask][i] << "\n";
            cout << "\n";
#endif
            if (dp[mask][i] == -inf) {
                continue;
            }
            if (__builtin_popcount(mask) == m) {
                sol = max(sol, dp[mask][i]);
            }
            for (int j = 0; j < n; ++j) {
                if (mask & (1 << j)) {
                    continue;
                }
                dp[mask | (1 << j)][j] = max(dp[mask | (1 << j)][j], dp[mask][i] + a[j] + rules[i][j]);
            }
        }
    }
    cout << sol << "\n";
    return 0;
}
