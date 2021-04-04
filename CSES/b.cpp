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
const int inf = 0x3f3f3f3f, mod = 998244353, maxn = 205, maxs = 30;

int dp[2][maxn][maxn * maxs];

pair<int, int> fact(long long b) {
    pair<int, int> res;
    while (b % 2 == 0) {
        ++res.first;
        b /= 2;
    }
    while (b % 5 == 0) {
        ++res.second;
        b /= 5;
    }
    return res;
}

int main() {
    setIO("b");

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);

    for (int i = 0; i < n; ++i) {
        long long b;
        cin >> b;
        a[i] = fact(b);
#ifdef DEBUG
        cout << b << " " << a[i].first << " " << a[i].second << "\n";
#endif
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            for (int l = 0; l < maxn * maxs; ++l) {
                int cur = dp[i % 2][j][l];
                if (cur == -1) {
                    continue;
                }
#ifdef DEBUG
                cout << i << " " << j << " " << l << " " << cur << "\n";
#endif
                dp[(i + 1) % 2][j][l] = max(cur, dp[(i + 1) % 2][j][l]);
                dp[(i + 1) % 2][j + 1][l + a[i].second] = max(dp[(i + 1) % 2][j + 1][l + a[i].second], cur + a[i].first);
            }
        }
        memset(dp[i % 2], -1, sizeof(dp[i % 2]));
    }
    int sol = 0;
    for (int i = 0; i < maxn * maxs; ++i) {
        sol = max(sol, min(i, dp[n % 2][k][i]));
    }
    cout << sol << "\n";
    return 0;
}
