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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 505;
int dp[maxn][maxn];

int main() {
    setIO("c");
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            dp[i][j] = inf;
        }
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        dp[i][i] = 1;
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
            for (int k = i + 2; k <= j; ++k) {
                if (a[i] == a[k]) {
                    dp[i][j] = min(dp[i][j], dp[i + 1][max(0, k - 1)] + dp[k + 1][j]);
                }
            }
            if (a[i] == a[i + 1]) {
                dp[i][j] = min(dp[i][j], dp[i + 2][j] + 1);
            }
#ifdef DEBUG
            cout << i << " " << j << " " << dp[i][j] << "\n";
#endif
        }
    }
    cout << dp[0][n - 1] << "\n";
    return 0;
}
