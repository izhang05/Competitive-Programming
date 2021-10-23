/* Author: izhang05
 * Time: 08-24-2021 14:05:02
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, maxn = 4e6 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
long long dp[maxn], suf[maxn];

void solve() {
    int n, mod;
    cin >> n >> mod;
    dp[n] = suf[n] = 1;
    for (int i = n - 1; i >= 1; --i) {
        dp[i] = suf[i + 1];
        for (int j = 2; i * j <= n; ++j) {
            dp[i] += suf[i * j];
            dp[i] %= mod;
            if (i * j + j <= n) {
                dp[i] -= suf[i * j + j];
            }
        }
        dp[i] = (dp[i] + mod) % mod;
        suf[i] = (suf[i + 1] + dp[i]) % mod;
#ifdef DEBUG
        cout << i << " " << dp[i] << "\n";
#endif
    }
    cout << dp[1] << "\n";
}

int main() {
    setIO("1");

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
