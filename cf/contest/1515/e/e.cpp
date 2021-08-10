/* Author: izhang05
 * Time: 08-10-2021 13:16:00
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
const int inf = 0x3f3f3f3f, maxn = 405;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
long long dp[maxn][maxn];

void solve() {
    int n, mod;
    cin >> n >> mod;
    dp[1][1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            long long &cur = dp[i][j];
            // create a new component
            cur += j * dp[i - 1][j - 1];
            cur %= mod;

            // add to existing component with 0 space
            cur += 2 * j * dp[i - 1][j];
            cur %= mod;

            // add to existing component with 1 spaces
            cur += 2 * j * dp[i - 2][j];
            cur %= mod;

            // merge 2 components with 1 space
            cur += 2 * j * dp[i - 2][j + 1];
            cur %= mod;

            // merge 2 components with 2 spaces
            if (i - 3 >= 0) {
                cur += j * dp[i - 3][j + 1];
                cur %= mod;
            }
        }
    }
    cout << dp[n][1] << "\n";
}

int main() {
    setIO("1");

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
