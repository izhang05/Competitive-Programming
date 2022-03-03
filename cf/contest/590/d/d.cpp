/* Author: izhang
 * Time: 03-03-2022 00:58:32
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 155;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
int dp[2][maxn][maxn * maxn];

void test_case() {
    int n, k, s;
    cin >> n >> k >> s;
    s = min(s, (n * (n + 1)) / 2);
    vector<int> q(n);
    for (int i = 0; i < n; ++i) {
        cin >> q[i];
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[1][0][0] = 0;
    for (int i = 0; i < n; ++i) {
        memset(dp[i % 2], 0x3f, sizeof(dp[i % 2]));
        for (int j = 0; j <= i; ++j) {
            for (int l = 0; l <= s; ++l) {
                int cur = dp[(i % 2) ^ 1][j][l];
                // don't take
                dp[i % 2][j][l] = min(dp[i % 2][j][l], cur);
                if (l + i - j <= s) {
                    dp[i % 2][j + 1][l + i - j] = min(dp[i % 2][j + 1][l - j + 1], cur + q[i]);
                }
            }
        }
    }
    int sol = inf;
    for (int i = 0; i <= s; ++i) {
        sol = min(sol, dp[(n - 1) % 2][k][i]);
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
