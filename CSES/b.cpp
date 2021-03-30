#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
//#define DEBUG
void setIO(string name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e3 + 5;

int dp[maxn][maxn];

int main() {
    setIO("b");

    int n, h, l, r;
    cin >> n >> h >> l >> r;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < h; ++j) {
            int cur = dp[i][j];
            if (cur == -1) {
                continue;
            }
            int b = (j + a[i] - 1) % h, c = (j + a[i]) % h;
            if (b >= l && b <= r) {
                dp[i + 1][b] = max(dp[i + 1][b], cur + 1);
            } else {
                dp[i + 1][b] = max(dp[i + 1][b], cur);
            }
            if (c >= l && c <= r) {
                dp[i + 1][c] = max(dp[i + 1][c], cur + 1);
            } else {
                dp[i + 1][c] = max(dp[i + 1][c], cur);
            }
        }
    }
    int sol = 0;
    for (int i = 0; i < h; ++i) {
        sol = max(sol, dp[n][i]);
    }
    cout << sol << "\n";
    return 0;
}
