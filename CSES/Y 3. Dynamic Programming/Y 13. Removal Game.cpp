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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 5e3 + 5;
long long dp[maxn][maxn];

int main() {
    setIO("13");
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int r = 0; r <= n; ++r) {
        for (int l = r - 1; l >= 0; --l) {
            if ((r - l) % 2 == n % 2) {
                // first player
                dp[l][r] = max(dp[l + 1][r] + a[l], dp[l][r - 1] + a[r - 1]);
            } else {
                // second player
                dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]);
            }
        }
    }
    cout << dp[0][n] << "\n";
    return 0;
}
