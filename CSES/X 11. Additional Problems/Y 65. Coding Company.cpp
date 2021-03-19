#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
//#define DEBUG
void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("65.in", "r", stdin);
    freopen("65.out", "w", stdout);
    freopen("65.out", "w", stderr);
#endif
}
const int mod = 1e9 + 7, maxn = 105, maxp = 53, maxk = 1e4 + 5;
const long long inf = 1e18;
long long dp[maxn][maxp][maxk];

int main() {
    setIO();
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    dp[0][0][5000] = 1;
    dp[0][1][5000 - a[0]] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < maxp; ++j) {
            for (int k = 0; k < maxk; ++k) {
                dp[i][j][k] %= mod;
                long long cur = dp[i][j][k];
                if (cur) {
                    dp[i + 1][j][k] += (j + 1) * cur;
                    if (i + 1 < n) {
                        if (j > 0) {
                            dp[i + 1][j - 1][k + a[i + 1]] += j * cur;
                        }
                        if (j + 1 < maxp) {
                            dp[i + 1][j + 1][k - a[i + 1]] += cur;
                        }
                    }
                }
            }
        }
    }
    long long sol = 0;
    for (int i = 5000; i <= 5000 + x; ++i) {
        sol += dp[n - 1][0][i];
        sol %= mod;
    }
    cout << sol << "\n";
    return 0;
}
