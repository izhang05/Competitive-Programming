/* Author: izhang05
 * Time: 07-29-2021 20:43:58
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 14;
bool grid[maxn][maxn];
long long dp[1 << maxn];

int main() {
    setIO("1");

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < (1 << (n - 1)); ++i) {
        memset(dp, 0, sizeof(dp));
        for (int j = 0; j < n; ++j) {
            dp[(1 << j)] = 1;
        }
        for (int j = 1; j < (1 << n); ++j) {
            int cur = __builtin_popcount(j);
            for (int k = 0; k < n; ++k) {
                if (!(j & (1 << k)) ){
                    if (grid[])
                }
            }
        }
        cout << dp[(1 << n) - 1] << " ";
    }
    cout << "\n";
    return 0;
}
