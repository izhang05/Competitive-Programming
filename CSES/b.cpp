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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 205, maxk = 1e3 + 5;

long long dp[2][maxn / 2][maxk];

int main() {
    setIO();

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    dp[0][0][0] = 1;
    dp[0][1][0] = 1;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j <= n / 2; ++j) {
            for (int l = 0; l <= k; ++l) {
                dp[i % 2][j][l] %= mod;
                long long cur = dp[i % 2][j][l];
#ifdef DEBUG
                cout << i << " " << j << " " << l << " " << cur << "\n";
#endif
                if (cur == 0) {
                    continue;
                }
                int val = l + j * (a[i + 1] - a[i]);
                if (val >= maxk) {
                    continue;
                }
                dp[(i + 1) % 2][j][val] += (j + 1) * cur;
                dp[(i + 1) % 2][j][val] %= mod;
                dp[(i + 1) % 2][j + 1][val] += cur;
                dp[(i + 1) % 2][j + 1][val] %= mod;
                if (j - 1 >= 0) {
                    dp[(i + 1) % 2][j - 1][val] += j * cur;
                    dp[(i + 1) % 2][j - 1][val] %= mod;
                }
            }
        }
        memset(dp[i % 2], 0, sizeof(dp[i % 2]));
    }
    long long sol = 0;
    for (int i = 0; i <= k; ++i) {
        sol += dp[(n - 1) % 2][0][i];
        sol %= mod;
    }
    cout << sol << "\n";
    return 0;
}
