/* Author: izhang05
 * Time: 07-14-2021 17:30:42
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e3 + 5;
int cnt[maxn], pre[maxn], dp[maxn][2];
char grid[maxn][maxn];

int main() {
    setIO("1");
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == '#') {
                ++cnt[j];
            }
        }
    }
    for (int i = 1; i <= m; ++i) {
        pre[i] = pre[i - 1] + cnt[i - 1];
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = dp[0][1] = 0;
    for (int i = x; i <= m; ++i) {
        for (int j = i - x; j >= i - y && j >= 0; --j) {
            dp[i][0] = min(dp[i][0], dp[j][1] + pre[i] - pre[j]);
            dp[i][1] = min(dp[i][1], dp[j][0] + n * (i - j) - (pre[i] - pre[j]));
        }
    }
    cout << min(dp[m][0], dp[m][1]) << "\n";
    return 0;
}